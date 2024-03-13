#include "tree_sitter/alloc.h" 
#include "tree_sitter/parser.h"
#include <limits.h>
#include <string.h>
#include <wctype.h>

#define OPEN_TAG_CAPACITY UCHAR_MAX

enum TokenType {
	HTML_OPTION_TAG_CLOSE,
	HTML_OPTION_TAG_OPEN,
	HTML_TAG_CLOSE,
	HTML_TAG_OPEN,
	HTML_VOID_TAG_OPEN,
};

typedef struct {
	char *open_tags[UCHAR_MAX];
	unsigned open_tag_count;
} Scanner;

char *VOID_TAGS[] = {
	"area",
	"base",
	"basefont",
	"bgsound",
	"br",
	"col",
	"command",
	"embed",
	"frame",
	"hr",
	"image",
	"img",
	"input",
	"isindex",
	"keygen",
	"link",
	"menuitem",
	"meta",
	"nextid",
	"param",
	"source",
	"track",
	"wbr",
};

char *OPTION_TAGS[] = {
	"body",
	"caption",
	"colgroup",
	"dd",
	"dt",
	"head",
	"html",
	"li",
	"optgroup",
	"option",
	"p",
	"rp",
	"rt",
	"tbody",
	"td",
	"tfoot",
	"th",
	"thead",
	"tr",
};

bool is_option_tag(char *tag) {
	size_t option_tags_len = sizeof(OPTION_TAGS)/sizeof(char*);
	for (unsigned i = 0; i < option_tags_len; i++) {
		if (strcmp(tag, OPTION_TAGS[i]) == 0) {
			return true;
		}
	}
	return false;
}

bool is_void_tag(char *tag) {
	size_t void_tags_len = sizeof(VOID_TAGS)/sizeof(char*);
	for (unsigned i = 0; i < void_tags_len; i++) {
		if (strcmp(tag, VOID_TAGS[i]) == 0) {
			return true;
		}
	}
	return false;
}

char *scan_tag_name(TSLexer *lexer) {
	unsigned capacity = 8;
	char *tag_name = ts_malloc(capacity * sizeof(char*) + 1);
	unsigned tag_name_len = 0;
	while (iswalnum(lexer->lookahead)) {
		if (tag_name_len == capacity) {
			capacity *= 2;
			tag_name = realloc(tag_name, capacity + 1);
		}
		tag_name[tag_name_len++] = lexer->lookahead;
		lexer->advance(lexer, false);
	}
	if (tag_name_len == 0) {
		return NULL;
	}
	tag_name[tag_name_len++] = '\0';
	return tag_name;
}

bool scan_tag_close(
	Scanner *scanner,
	TSLexer *lexer,
	const bool *valid_symbols
) {
	char *tag_name = scan_tag_name(lexer);
	if (!tag_name) {
		return false;
	}
	if (lexer->lookahead != '>') {
		return false;
	}
	lexer->advance(lexer, false);
	enum TokenType result_symbol = is_option_tag(tag_name)
		? HTML_OPTION_TAG_CLOSE
		: HTML_TAG_CLOSE;
	if (!valid_symbols[result_symbol]) {
		return false;
	}
	unsigned option_tag_offset = scanner->open_tag_count;
	char *open_tag;
	do {
		if (option_tag_offset-- == 0) {
			return false;
		}
		open_tag = scanner->open_tags[option_tag_offset];
		if (strcmp(tag_name, open_tag) == 0) {
			lexer->mark_end(lexer);
			lexer->result_symbol = result_symbol;
			scanner->open_tag_count = option_tag_offset;
			return true;
		}
	} while (is_option_tag(open_tag));
	return false;
}

bool scan_tag_open(
	Scanner *scanner,
	TSLexer *lexer,
	const bool *valid_symbols
) {
	char *tag_name = scan_tag_name(lexer);
	if (!tag_name) {
		return false;
	}
	if (!iswspace(lexer->lookahead) && lexer->lookahead != '/' && lexer->lookahead != '>') {
		return false;
	}
	if (is_void_tag(tag_name)) {
		if (!valid_symbols[HTML_VOID_TAG_OPEN]) {
			return false;
		}
		lexer->mark_end(lexer);
		lexer->result_symbol = HTML_VOID_TAG_OPEN;
	} else if (scanner->open_tag_count == OPEN_TAG_CAPACITY) {
		return false;
	} else if (is_option_tag(tag_name)) {
		if (!valid_symbols[HTML_OPTION_TAG_OPEN]) {
			return false;
		}
		lexer->mark_end(lexer);
		lexer->result_symbol = HTML_OPTION_TAG_OPEN;
		scanner->open_tags[scanner->open_tag_count++] = tag_name;
	} else {
		if (!valid_symbols[HTML_TAG_OPEN]) {
			return false;
		}
		lexer->mark_end(lexer);
		lexer->result_symbol = HTML_TAG_OPEN;
		scanner->open_tags[scanner->open_tag_count++] = tag_name;
	}
	return true;
}

void *tree_sitter_spml_external_scanner_create() {
	return (Scanner *)ts_calloc(sizeof(Scanner), 1);
}

bool tree_sitter_spml_external_scanner_scan(
	void *payload,
	TSLexer *lexer,
	const bool *valid_symbols
) {
	Scanner *scanner = (Scanner *)payload;
	if (lexer->eof(lexer)) {
		return false;
	}
	while (iswspace(lexer->lookahead)) {
		lexer->advance(lexer, true);
	}
	if (lexer->lookahead != '<') {
		return false;
	}
	lexer->mark_end(lexer);
	lexer->advance(lexer, false);
	if (lexer->lookahead == '/') {
		lexer->advance(lexer, false);
		return scan_tag_close(scanner, lexer, valid_symbols);
	}
	return scan_tag_open(scanner, lexer, valid_symbols);
}

unsigned tree_sitter_spml_external_scanner_serialize(
	void *payload,
	char *buffer
) {
	unsigned size = 0, name_length = 0;
	Scanner *scanner = (Scanner *)payload;
	if (scanner->open_tag_count == 0) {
		return 0;
	}
	buffer[size++] = (char)scanner->open_tag_count;
	for (unsigned i = 0; i < scanner->open_tag_count; i++) {
		name_length = strlen(scanner->open_tags[i]) + 1;
		if (size + name_length >= TREE_SITTER_SERIALIZATION_BUFFER_SIZE) {
			buffer[0] = size; // change size to what was actually written
			break;
		}
		buffer[size++] = (char)name_length;
		strncpy(&buffer[size], scanner->open_tags[i], name_length);
		size += name_length;
	}
	return size;
}

void tree_sitter_spml_external_scanner_deserialize(
	void *payload,
	const char *buffer,
	unsigned length
) {
	unsigned size = 0, name_length = 0;
	Scanner *scanner = (Scanner *)payload;
	if (length == 0) {
		return;
	}
	scanner->open_tag_count = (unsigned)buffer[size++];
	for (unsigned i = 0; i < scanner->open_tag_count; i++) {
		name_length = buffer[size++];
		strncpy(scanner->open_tags[i], &buffer[size], name_length);
		size += name_length;
	}
}

void tree_sitter_spml_external_scanner_destroy(void *payload) {
	free((Scanner *)payload);
}
