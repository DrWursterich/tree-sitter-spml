#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 166
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 72
#define ALIAS_COUNT 0
#define TOKEN_COUNT 39
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 1

enum {
  anon_sym_GT = 1,
  sym_argument_tag_open = 2,
  sym_argument_tag_close = 3,
  sym_condition_tag_open = 4,
  sym_condition_tag_close = 5,
  sym_else_tag_open = 6,
  sym_else_tag_close = 7,
  sym_elseif_tag_open = 8,
  sym_elseif_tag_close = 9,
  sym_if_tag_open = 10,
  sym_if_tag_close = 11,
  sym_include_tag_open = 12,
  sym_include_tag_close = 13,
  sym_self_closing_tag_end = 14,
  anon_sym_anchor_EQ = 15,
  anon_sym_condition_EQ = 16,
  anon_sym_contains_EQ = 17,
  anon_sym_default_EQ = 18,
  anon_sym_eq_EQ = 19,
  anon_sym_expression_EQ = 20,
  anon_sym_gt_EQ = 21,
  anon_sym_gte_EQ = 22,
  anon_sym_ic_EQ = 23,
  anon_sym_isNull_EQ = 24,
  anon_sym_locale_EQ = 25,
  anon_sym_lt_EQ = 26,
  anon_sym_lte_EQ = 27,
  anon_sym_module_EQ = 28,
  anon_sym_name_EQ = 29,
  anon_sym_neq_EQ = 30,
  anon_sym_object_EQ = 31,
  anon_sym_return_EQ = 32,
  anon_sym_template_EQ = 33,
  anon_sym_text_EQ = 34,
  anon_sym_uri_EQ = 35,
  anon_sym_value_EQ = 36,
  sym_string = 37,
  sym_text = 38,
  sym_document = 39,
  sym__top_level_tag = 40,
  sym_argument_tag = 41,
  sym_condition_tag = 42,
  sym_else_tag = 43,
  sym_elseif_tag = 44,
  sym_if_tag = 45,
  sym_include_tag = 46,
  sym_anchor_attribute = 47,
  sym_condition_attribute = 48,
  sym_contains_attribute = 49,
  sym_default_attribute = 50,
  sym_eq_attribute = 51,
  sym_expression_attribute = 52,
  sym_gt_attribute = 53,
  sym_gte_attribute = 54,
  sym_ic_attribute = 55,
  sym_isNull_attribute = 56,
  sym_locale_attribute = 57,
  sym_lt_attribute = 58,
  sym_lte_attribute = 59,
  sym_module_attribute = 60,
  sym_name_attribute = 61,
  sym_neq_attribute = 62,
  sym_object_attribute = 63,
  sym_return_attribute = 64,
  sym_template_attribute = 65,
  sym_text_attribute = 66,
  sym_uri_attribute = 67,
  sym_value_attribute = 68,
  aux_sym_document_repeat1 = 69,
  aux_sym_condition_tag_repeat1 = 70,
  aux_sym_include_tag_repeat1 = 71,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_GT] = ">",
  [sym_argument_tag_open] = "argument_tag_open",
  [sym_argument_tag_close] = "argument_tag_close",
  [sym_condition_tag_open] = "condition_tag_open",
  [sym_condition_tag_close] = "condition_tag_close",
  [sym_else_tag_open] = "else_tag_open",
  [sym_else_tag_close] = "else_tag_close",
  [sym_elseif_tag_open] = "elseif_tag_open",
  [sym_elseif_tag_close] = "elseif_tag_close",
  [sym_if_tag_open] = "if_tag_open",
  [sym_if_tag_close] = "if_tag_close",
  [sym_include_tag_open] = "include_tag_open",
  [sym_include_tag_close] = "include_tag_close",
  [sym_self_closing_tag_end] = "self_closing_tag_end",
  [anon_sym_anchor_EQ] = "anchor=",
  [anon_sym_condition_EQ] = "condition=",
  [anon_sym_contains_EQ] = "contains=",
  [anon_sym_default_EQ] = "default=",
  [anon_sym_eq_EQ] = "eq=",
  [anon_sym_expression_EQ] = "expression=",
  [anon_sym_gt_EQ] = "gt=",
  [anon_sym_gte_EQ] = "gte=",
  [anon_sym_ic_EQ] = "ic=",
  [anon_sym_isNull_EQ] = "isNull=",
  [anon_sym_locale_EQ] = "locale=",
  [anon_sym_lt_EQ] = "lt=",
  [anon_sym_lte_EQ] = "lte=",
  [anon_sym_module_EQ] = "module=",
  [anon_sym_name_EQ] = "name=",
  [anon_sym_neq_EQ] = "neq=",
  [anon_sym_object_EQ] = "object=",
  [anon_sym_return_EQ] = "return=",
  [anon_sym_template_EQ] = "template=",
  [anon_sym_text_EQ] = "text=",
  [anon_sym_uri_EQ] = "uri=",
  [anon_sym_value_EQ] = "value=",
  [sym_string] = "string",
  [sym_text] = "text",
  [sym_document] = "document",
  [sym__top_level_tag] = "_top_level_tag",
  [sym_argument_tag] = "argument_tag",
  [sym_condition_tag] = "condition_tag",
  [sym_else_tag] = "else_tag",
  [sym_elseif_tag] = "elseif_tag",
  [sym_if_tag] = "if_tag",
  [sym_include_tag] = "include_tag",
  [sym_anchor_attribute] = "anchor_attribute",
  [sym_condition_attribute] = "condition_attribute",
  [sym_contains_attribute] = "contains_attribute",
  [sym_default_attribute] = "default_attribute",
  [sym_eq_attribute] = "eq_attribute",
  [sym_expression_attribute] = "expression_attribute",
  [sym_gt_attribute] = "gt_attribute",
  [sym_gte_attribute] = "gte_attribute",
  [sym_ic_attribute] = "ic_attribute",
  [sym_isNull_attribute] = "isNull_attribute",
  [sym_locale_attribute] = "locale_attribute",
  [sym_lt_attribute] = "lt_attribute",
  [sym_lte_attribute] = "lte_attribute",
  [sym_module_attribute] = "module_attribute",
  [sym_name_attribute] = "name_attribute",
  [sym_neq_attribute] = "neq_attribute",
  [sym_object_attribute] = "object_attribute",
  [sym_return_attribute] = "return_attribute",
  [sym_template_attribute] = "template_attribute",
  [sym_text_attribute] = "text_attribute",
  [sym_uri_attribute] = "uri_attribute",
  [sym_value_attribute] = "value_attribute",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_condition_tag_repeat1] = "condition_tag_repeat1",
  [aux_sym_include_tag_repeat1] = "include_tag_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_GT] = anon_sym_GT,
  [sym_argument_tag_open] = sym_argument_tag_open,
  [sym_argument_tag_close] = sym_argument_tag_close,
  [sym_condition_tag_open] = sym_condition_tag_open,
  [sym_condition_tag_close] = sym_condition_tag_close,
  [sym_else_tag_open] = sym_else_tag_open,
  [sym_else_tag_close] = sym_else_tag_close,
  [sym_elseif_tag_open] = sym_elseif_tag_open,
  [sym_elseif_tag_close] = sym_elseif_tag_close,
  [sym_if_tag_open] = sym_if_tag_open,
  [sym_if_tag_close] = sym_if_tag_close,
  [sym_include_tag_open] = sym_include_tag_open,
  [sym_include_tag_close] = sym_include_tag_close,
  [sym_self_closing_tag_end] = sym_self_closing_tag_end,
  [anon_sym_anchor_EQ] = anon_sym_anchor_EQ,
  [anon_sym_condition_EQ] = anon_sym_condition_EQ,
  [anon_sym_contains_EQ] = anon_sym_contains_EQ,
  [anon_sym_default_EQ] = anon_sym_default_EQ,
  [anon_sym_eq_EQ] = anon_sym_eq_EQ,
  [anon_sym_expression_EQ] = anon_sym_expression_EQ,
  [anon_sym_gt_EQ] = anon_sym_gt_EQ,
  [anon_sym_gte_EQ] = anon_sym_gte_EQ,
  [anon_sym_ic_EQ] = anon_sym_ic_EQ,
  [anon_sym_isNull_EQ] = anon_sym_isNull_EQ,
  [anon_sym_locale_EQ] = anon_sym_locale_EQ,
  [anon_sym_lt_EQ] = anon_sym_lt_EQ,
  [anon_sym_lte_EQ] = anon_sym_lte_EQ,
  [anon_sym_module_EQ] = anon_sym_module_EQ,
  [anon_sym_name_EQ] = anon_sym_name_EQ,
  [anon_sym_neq_EQ] = anon_sym_neq_EQ,
  [anon_sym_object_EQ] = anon_sym_object_EQ,
  [anon_sym_return_EQ] = anon_sym_return_EQ,
  [anon_sym_template_EQ] = anon_sym_template_EQ,
  [anon_sym_text_EQ] = anon_sym_text_EQ,
  [anon_sym_uri_EQ] = anon_sym_uri_EQ,
  [anon_sym_value_EQ] = anon_sym_value_EQ,
  [sym_string] = sym_string,
  [sym_text] = sym_text,
  [sym_document] = sym_document,
  [sym__top_level_tag] = sym__top_level_tag,
  [sym_argument_tag] = sym_argument_tag,
  [sym_condition_tag] = sym_condition_tag,
  [sym_else_tag] = sym_else_tag,
  [sym_elseif_tag] = sym_elseif_tag,
  [sym_if_tag] = sym_if_tag,
  [sym_include_tag] = sym_include_tag,
  [sym_anchor_attribute] = sym_anchor_attribute,
  [sym_condition_attribute] = sym_condition_attribute,
  [sym_contains_attribute] = sym_contains_attribute,
  [sym_default_attribute] = sym_default_attribute,
  [sym_eq_attribute] = sym_eq_attribute,
  [sym_expression_attribute] = sym_expression_attribute,
  [sym_gt_attribute] = sym_gt_attribute,
  [sym_gte_attribute] = sym_gte_attribute,
  [sym_ic_attribute] = sym_ic_attribute,
  [sym_isNull_attribute] = sym_isNull_attribute,
  [sym_locale_attribute] = sym_locale_attribute,
  [sym_lt_attribute] = sym_lt_attribute,
  [sym_lte_attribute] = sym_lte_attribute,
  [sym_module_attribute] = sym_module_attribute,
  [sym_name_attribute] = sym_name_attribute,
  [sym_neq_attribute] = sym_neq_attribute,
  [sym_object_attribute] = sym_object_attribute,
  [sym_return_attribute] = sym_return_attribute,
  [sym_template_attribute] = sym_template_attribute,
  [sym_text_attribute] = sym_text_attribute,
  [sym_uri_attribute] = sym_uri_attribute,
  [sym_value_attribute] = sym_value_attribute,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_condition_tag_repeat1] = aux_sym_condition_tag_repeat1,
  [aux_sym_include_tag_repeat1] = aux_sym_include_tag_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [sym_argument_tag_open] = {
    .visible = true,
    .named = true,
  },
  [sym_argument_tag_close] = {
    .visible = true,
    .named = true,
  },
  [sym_condition_tag_open] = {
    .visible = true,
    .named = true,
  },
  [sym_condition_tag_close] = {
    .visible = true,
    .named = true,
  },
  [sym_else_tag_open] = {
    .visible = true,
    .named = true,
  },
  [sym_else_tag_close] = {
    .visible = true,
    .named = true,
  },
  [sym_elseif_tag_open] = {
    .visible = true,
    .named = true,
  },
  [sym_elseif_tag_close] = {
    .visible = true,
    .named = true,
  },
  [sym_if_tag_open] = {
    .visible = true,
    .named = true,
  },
  [sym_if_tag_close] = {
    .visible = true,
    .named = true,
  },
  [sym_include_tag_open] = {
    .visible = true,
    .named = true,
  },
  [sym_include_tag_close] = {
    .visible = true,
    .named = true,
  },
  [sym_self_closing_tag_end] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_anchor_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_condition_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_contains_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_default_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_eq_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_expression_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_gt_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_gte_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ic_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_isNull_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_locale_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_lt_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_lte_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_module_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_name_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_neq_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_object_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_template_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_text_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uri_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_value_EQ] = {
    .visible = true,
    .named = false,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym__top_level_tag] = {
    .visible = false,
    .named = true,
  },
  [sym_argument_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_condition_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_else_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_elseif_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_if_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_include_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_anchor_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_condition_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_contains_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_default_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_eq_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_expression_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_gt_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_gte_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_ic_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_isNull_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_locale_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_lt_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_lte_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_module_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_name_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_neq_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_object_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_return_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_template_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_text_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_uri_attribute] = {
    .visible = true,
    .named = true,
  },
  [sym_value_attribute] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_condition_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_include_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 2,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 14,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 11,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 23,
  [29] = 29,
  [30] = 26,
  [31] = 17,
  [32] = 18,
  [33] = 27,
  [34] = 34,
  [35] = 25,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 58,
  [61] = 61,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 61,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 81,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 48,
  [93] = 45,
  [94] = 49,
  [95] = 90,
  [96] = 42,
  [97] = 97,
  [98] = 98,
  [99] = 39,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 97,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 127,
  [128] = 128,
  [129] = 129,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 140,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 153,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 136,
  [164] = 129,
  [165] = 165,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(175);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '/') ADVANCE(30);
      if (lookahead == '<') ADVANCE(2);
      if (lookahead == '>') ADVANCE(176);
      if (lookahead == 'a') ADVANCE(111);
      if (lookahead == 'c') ADVANCE(124);
      if (lookahead == 'd') ADVANCE(60);
      if (lookahead == 'e') ADVANCE(139);
      if (lookahead == 'g') ADVANCE(154);
      if (lookahead == 'i') ADVANCE(48);
      if (lookahead == 'l') ADVANCE(125);
      if (lookahead == 'm') ADVANCE(123);
      if (lookahead == 'n') ADVANCE(38);
      if (lookahead == 'o') ADVANCE(46);
      if (lookahead == 'r') ADVANCE(65);
      if (lookahead == 't') ADVANCE(61);
      if (lookahead == 'u') ADVANCE(141);
      if (lookahead == 'v') ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(212);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '/') ADVANCE(153);
      if (lookahead == 's') ADVANCE(133);
      END_STATE();
    case 3:
      if (lookahead == '/') ADVANCE(151);
      if (lookahead == 's') ADVANCE(135);
      END_STATE();
    case 4:
      if (lookahead == ':') ADVANCE(42);
      END_STATE();
    case 5:
      if (lookahead == ':') ADVANCE(49);
      END_STATE();
    case 6:
      if (lookahead == ':') ADVANCE(75);
      END_STATE();
    case 7:
      if (lookahead == ':') ADVANCE(45);
      END_STATE();
    case 8:
      if (lookahead == '=') ADVANCE(194);
      END_STATE();
    case 9:
      if (lookahead == '=') ADVANCE(196);
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(198);
      END_STATE();
    case 11:
      if (lookahead == '=') ADVANCE(201);
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 12:
      if (lookahead == '=') ADVANCE(197);
      END_STATE();
    case 13:
      if (lookahead == '=') ADVANCE(202);
      END_STATE();
    case 14:
      if (lookahead == '=') ADVANCE(205);
      END_STATE();
    case 15:
      if (lookahead == '=') ADVANCE(210);
      END_STATE();
    case 16:
      if (lookahead == '=') ADVANCE(204);
      END_STATE();
    case 17:
      if (lookahead == '=') ADVANCE(209);
      END_STATE();
    case 18:
      if (lookahead == '=') ADVANCE(211);
      END_STATE();
    case 19:
      if (lookahead == '=') ADVANCE(190);
      END_STATE();
    case 20:
      if (lookahead == '=') ADVANCE(199);
      END_STATE();
    case 21:
      if (lookahead == '=') ADVANCE(200);
      END_STATE();
    case 22:
      if (lookahead == '=') ADVANCE(203);
      END_STATE();
    case 23:
      if (lookahead == '=') ADVANCE(206);
      END_STATE();
    case 24:
      if (lookahead == '=') ADVANCE(207);
      END_STATE();
    case 25:
      if (lookahead == '=') ADVANCE(193);
      END_STATE();
    case 26:
      if (lookahead == '=') ADVANCE(192);
      END_STATE();
    case 27:
      if (lookahead == '=') ADVANCE(208);
      END_STATE();
    case 28:
      if (lookahead == '=') ADVANCE(191);
      END_STATE();
    case 29:
      if (lookahead == '=') ADVANCE(195);
      END_STATE();
    case 30:
      if (lookahead == '>') ADVANCE(189);
      END_STATE();
    case 31:
      if (lookahead == '>') ADVANCE(186);
      END_STATE();
    case 32:
      if (lookahead == '>') ADVANCE(182);
      if (lookahead == 'i') ADVANCE(82);
      END_STATE();
    case 33:
      if (lookahead == '>') ADVANCE(184);
      END_STATE();
    case 34:
      if (lookahead == '>') ADVANCE(188);
      END_STATE();
    case 35:
      if (lookahead == '>') ADVANCE(178);
      END_STATE();
    case 36:
      if (lookahead == '>') ADVANCE(180);
      END_STATE();
    case 37:
      if (lookahead == 'N') ADVANCE(165);
      END_STATE();
    case 38:
      if (lookahead == 'a') ADVANCE(108);
      if (lookahead == 'e') ADVANCE(140);
      END_STATE();
    case 39:
      if (lookahead == 'a') ADVANCE(97);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(87);
      END_STATE();
    case 41:
      if (lookahead == 'a') ADVANCE(105);
      END_STATE();
    case 42:
      if (lookahead == 'a') ADVANCE(142);
      if (lookahead == 'c') ADVANCE(126);
      if (lookahead == 'e') ADVANCE(96);
      if (lookahead == 'i') ADVANCE(77);
      END_STATE();
    case 43:
      if (lookahead == 'a') ADVANCE(162);
      END_STATE();
    case 44:
      if (lookahead == 'a') ADVANCE(168);
      END_STATE();
    case 45:
      if (lookahead == 'a') ADVANCE(146);
      if (lookahead == 'c') ADVANCE(132);
      if (lookahead == 'e') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(80);
      END_STATE();
    case 46:
      if (lookahead == 'b') ADVANCE(95);
      END_STATE();
    case 47:
      if (lookahead == 'c') ADVANCE(85);
      END_STATE();
    case 48:
      if (lookahead == 'c') ADVANCE(10);
      if (lookahead == 's') ADVANCE(37);
      END_STATE();
    case 49:
      if (lookahead == 'c') ADVANCE(126);
      if (lookahead == 'i') ADVANCE(77);
      END_STATE();
    case 50:
      if (lookahead == 'c') ADVANCE(41);
      END_STATE();
    case 51:
      if (lookahead == 'c') ADVANCE(99);
      END_STATE();
    case 52:
      if (lookahead == 'c') ADVANCE(160);
      END_STATE();
    case 53:
      if (lookahead == 'c') ADVANCE(103);
      END_STATE();
    case 54:
      if (lookahead == 'd') ADVANCE(86);
      if (lookahead == 't') ADVANCE(40);
      END_STATE();
    case 55:
      if (lookahead == 'd') ADVANCE(64);
      END_STATE();
    case 56:
      if (lookahead == 'd') ADVANCE(68);
      END_STATE();
    case 57:
      if (lookahead == 'd') ADVANCE(173);
      END_STATE();
    case 58:
      if (lookahead == 'd') ADVANCE(93);
      END_STATE();
    case 59:
      if (lookahead == 'd') ADVANCE(94);
      END_STATE();
    case 60:
      if (lookahead == 'e') ADVANCE(81);
      END_STATE();
    case 61:
      if (lookahead == 'e') ADVANCE(107);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(181);
      END_STATE();
    case 63:
      if (lookahead == 'e') ADVANCE(32);
      END_STATE();
    case 64:
      if (lookahead == 'e') ADVANCE(187);
      END_STATE();
    case 65:
      if (lookahead == 'e') ADVANCE(156);
      END_STATE();
    case 66:
      if (lookahead == 'e') ADVANCE(147);
      END_STATE();
    case 67:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 68:
      if (lookahead == 'e') ADVANCE(34);
      END_STATE();
    case 69:
      if (lookahead == 'e') ADVANCE(117);
      END_STATE();
    case 70:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 71:
      if (lookahead == 'e') ADVANCE(18);
      END_STATE();
    case 72:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 74:
      if (lookahead == 'e') ADVANCE(27);
      END_STATE();
    case 75:
      if (lookahead == 'e') ADVANCE(102);
      if (lookahead == 'i') ADVANCE(79);
      END_STATE();
    case 76:
      if (lookahead == 'e') ADVANCE(118);
      END_STATE();
    case 77:
      if (lookahead == 'f') ADVANCE(185);
      if (lookahead == 'n') ADVANCE(51);
      END_STATE();
    case 78:
      if (lookahead == 'f') ADVANCE(183);
      END_STATE();
    case 79:
      if (lookahead == 'f') ADVANCE(31);
      END_STATE();
    case 80:
      if (lookahead == 'f') ADVANCE(31);
      if (lookahead == 'n') ADVANCE(53);
      END_STATE();
    case 81:
      if (lookahead == 'f') ADVANCE(44);
      END_STATE();
    case 82:
      if (lookahead == 'f') ADVANCE(33);
      END_STATE();
    case 83:
      if (lookahead == 'g') ADVANCE(169);
      END_STATE();
    case 84:
      if (lookahead == 'g') ADVANCE(172);
      END_STATE();
    case 85:
      if (lookahead == 'h') ADVANCE(127);
      END_STATE();
    case 86:
      if (lookahead == 'i') ADVANCE(157);
      END_STATE();
    case 87:
      if (lookahead == 'i') ADVANCE(115);
      END_STATE();
    case 88:
      if (lookahead == 'i') ADVANCE(15);
      END_STATE();
    case 89:
      if (lookahead == 'i') ADVANCE(130);
      END_STATE();
    case 90:
      if (lookahead == 'i') ADVANCE(131);
      END_STATE();
    case 91:
      if (lookahead == 'i') ADVANCE(128);
      END_STATE();
    case 92:
      if (lookahead == 'i') ADVANCE(129);
      END_STATE();
    case 93:
      if (lookahead == 'i') ADVANCE(163);
      END_STATE();
    case 94:
      if (lookahead == 'i') ADVANCE(164);
      END_STATE();
    case 95:
      if (lookahead == 'j') ADVANCE(67);
      END_STATE();
    case 96:
      if (lookahead == 'l') ADVANCE(148);
      END_STATE();
    case 97:
      if (lookahead == 'l') ADVANCE(171);
      END_STATE();
    case 98:
      if (lookahead == 'l') ADVANCE(43);
      END_STATE();
    case 99:
      if (lookahead == 'l') ADVANCE(167);
      END_STATE();
    case 100:
      if (lookahead == 'l') ADVANCE(101);
      END_STATE();
    case 101:
      if (lookahead == 'l') ADVANCE(20);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(149);
      END_STATE();
    case 103:
      if (lookahead == 'l') ADVANCE(170);
      END_STATE();
    case 104:
      if (lookahead == 'l') ADVANCE(161);
      END_STATE();
    case 105:
      if (lookahead == 'l') ADVANCE(72);
      END_STATE();
    case 106:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 107:
      if (lookahead == 'm') ADVANCE(137);
      if (lookahead == 'x') ADVANCE(159);
      END_STATE();
    case 108:
      if (lookahead == 'm') ADVANCE(70);
      END_STATE();
    case 109:
      if (lookahead == 'm') ADVANCE(69);
      END_STATE();
    case 110:
      if (lookahead == 'm') ADVANCE(76);
      END_STATE();
    case 111:
      if (lookahead == 'n') ADVANCE(47);
      END_STATE();
    case 112:
      if (lookahead == 'n') ADVANCE(54);
      END_STATE();
    case 113:
      if (lookahead == 'n') ADVANCE(179);
      END_STATE();
    case 114:
      if (lookahead == 'n') ADVANCE(58);
      END_STATE();
    case 115:
      if (lookahead == 'n') ADVANCE(150);
      END_STATE();
    case 116:
      if (lookahead == 'n') ADVANCE(36);
      END_STATE();
    case 117:
      if (lookahead == 'n') ADVANCE(155);
      END_STATE();
    case 118:
      if (lookahead == 'n') ADVANCE(158);
      END_STATE();
    case 119:
      if (lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 120:
      if (lookahead == 'n') ADVANCE(28);
      END_STATE();
    case 121:
      if (lookahead == 'n') ADVANCE(29);
      END_STATE();
    case 122:
      if (lookahead == 'n') ADVANCE(59);
      END_STATE();
    case 123:
      if (lookahead == 'o') ADVANCE(57);
      END_STATE();
    case 124:
      if (lookahead == 'o') ADVANCE(112);
      END_STATE();
    case 125:
      if (lookahead == 'o') ADVANCE(50);
      if (lookahead == 't') ADVANCE(11);
      END_STATE();
    case 126:
      if (lookahead == 'o') ADVANCE(114);
      END_STATE();
    case 127:
      if (lookahead == 'o') ADVANCE(145);
      END_STATE();
    case 128:
      if (lookahead == 'o') ADVANCE(113);
      END_STATE();
    case 129:
      if (lookahead == 'o') ADVANCE(116);
      END_STATE();
    case 130:
      if (lookahead == 'o') ADVANCE(120);
      END_STATE();
    case 131:
      if (lookahead == 'o') ADVANCE(121);
      END_STATE();
    case 132:
      if (lookahead == 'o') ADVANCE(122);
      END_STATE();
    case 133:
      if (lookahead == 'p') ADVANCE(4);
      END_STATE();
    case 134:
      if (lookahead == 'p') ADVANCE(144);
      END_STATE();
    case 135:
      if (lookahead == 'p') ADVANCE(5);
      END_STATE();
    case 136:
      if (lookahead == 'p') ADVANCE(6);
      END_STATE();
    case 137:
      if (lookahead == 'p') ADVANCE(98);
      END_STATE();
    case 138:
      if (lookahead == 'p') ADVANCE(7);
      END_STATE();
    case 139:
      if (lookahead == 'q') ADVANCE(8);
      if (lookahead == 'x') ADVANCE(134);
      END_STATE();
    case 140:
      if (lookahead == 'q') ADVANCE(14);
      END_STATE();
    case 141:
      if (lookahead == 'r') ADVANCE(88);
      END_STATE();
    case 142:
      if (lookahead == 'r') ADVANCE(83);
      END_STATE();
    case 143:
      if (lookahead == 'r') ADVANCE(119);
      END_STATE();
    case 144:
      if (lookahead == 'r') ADVANCE(66);
      END_STATE();
    case 145:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 146:
      if (lookahead == 'r') ADVANCE(84);
      END_STATE();
    case 147:
      if (lookahead == 's') ADVANCE(152);
      END_STATE();
    case 148:
      if (lookahead == 's') ADVANCE(62);
      END_STATE();
    case 149:
      if (lookahead == 's') ADVANCE(63);
      END_STATE();
    case 150:
      if (lookahead == 's') ADVANCE(26);
      END_STATE();
    case 151:
      if (lookahead == 's') ADVANCE(136);
      END_STATE();
    case 152:
      if (lookahead == 's') ADVANCE(90);
      END_STATE();
    case 153:
      if (lookahead == 's') ADVANCE(138);
      END_STATE();
    case 154:
      if (lookahead == 't') ADVANCE(9);
      END_STATE();
    case 155:
      if (lookahead == 't') ADVANCE(177);
      END_STATE();
    case 156:
      if (lookahead == 't') ADVANCE(166);
      END_STATE();
    case 157:
      if (lookahead == 't') ADVANCE(89);
      END_STATE();
    case 158:
      if (lookahead == 't') ADVANCE(35);
      END_STATE();
    case 159:
      if (lookahead == 't') ADVANCE(17);
      END_STATE();
    case 160:
      if (lookahead == 't') ADVANCE(23);
      END_STATE();
    case 161:
      if (lookahead == 't') ADVANCE(25);
      END_STATE();
    case 162:
      if (lookahead == 't') ADVANCE(74);
      END_STATE();
    case 163:
      if (lookahead == 't') ADVANCE(91);
      END_STATE();
    case 164:
      if (lookahead == 't') ADVANCE(92);
      END_STATE();
    case 165:
      if (lookahead == 'u') ADVANCE(100);
      END_STATE();
    case 166:
      if (lookahead == 'u') ADVANCE(143);
      END_STATE();
    case 167:
      if (lookahead == 'u') ADVANCE(55);
      END_STATE();
    case 168:
      if (lookahead == 'u') ADVANCE(104);
      END_STATE();
    case 169:
      if (lookahead == 'u') ADVANCE(109);
      END_STATE();
    case 170:
      if (lookahead == 'u') ADVANCE(56);
      END_STATE();
    case 171:
      if (lookahead == 'u') ADVANCE(71);
      END_STATE();
    case 172:
      if (lookahead == 'u') ADVANCE(110);
      END_STATE();
    case 173:
      if (lookahead == 'u') ADVANCE(106);
      END_STATE();
    case 174:
      if (eof) ADVANCE(175);
      if (lookahead == '<') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(213);
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(214);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_argument_tag_open);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_argument_tag_close);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_condition_tag_open);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_condition_tag_close);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_else_tag_open);
      if (lookahead == 'i') ADVANCE(78);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_else_tag_close);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_elseif_tag_open);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_elseif_tag_close);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_if_tag_open);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_if_tag_close);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_include_tag_open);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_include_tag_close);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_self_closing_tag_end);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_anchor_EQ);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(anon_sym_condition_EQ);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_contains_EQ);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(anon_sym_default_EQ);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(anon_sym_eq_EQ);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_expression_EQ);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_gt_EQ);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_gte_EQ);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_ic_EQ);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(anon_sym_isNull_EQ);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_locale_EQ);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(anon_sym_lt_EQ);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_lte_EQ);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_module_EQ);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(anon_sym_name_EQ);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_neq_EQ);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_object_EQ);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_return_EQ);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_template_EQ);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_text_EQ);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_uri_EQ);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(anon_sym_value_EQ);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(213);
      if (lookahead != 0 &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(214);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_text);
      if (lookahead != 0 &&
          lookahead != '<' &&
          lookahead != '>') ADVANCE(214);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 174},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 174},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 174},
  [12] = {.lex_state = 174},
  [13] = {.lex_state = 174},
  [14] = {.lex_state = 174},
  [15] = {.lex_state = 174},
  [16] = {.lex_state = 174},
  [17] = {.lex_state = 174},
  [18] = {.lex_state = 174},
  [19] = {.lex_state = 174},
  [20] = {.lex_state = 174},
  [21] = {.lex_state = 174},
  [22] = {.lex_state = 174},
  [23] = {.lex_state = 174},
  [24] = {.lex_state = 174},
  [25] = {.lex_state = 174},
  [26] = {.lex_state = 174},
  [27] = {.lex_state = 174},
  [28] = {.lex_state = 174},
  [29] = {.lex_state = 174},
  [30] = {.lex_state = 174},
  [31] = {.lex_state = 174},
  [32] = {.lex_state = 174},
  [33] = {.lex_state = 174},
  [34] = {.lex_state = 174},
  [35] = {.lex_state = 174},
  [36] = {.lex_state = 174},
  [37] = {.lex_state = 174},
  [38] = {.lex_state = 174},
  [39] = {.lex_state = 174},
  [40] = {.lex_state = 174},
  [41] = {.lex_state = 174},
  [42] = {.lex_state = 174},
  [43] = {.lex_state = 174},
  [44] = {.lex_state = 174},
  [45] = {.lex_state = 174},
  [46] = {.lex_state = 174},
  [47] = {.lex_state = 174},
  [48] = {.lex_state = 174},
  [49] = {.lex_state = 174},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 174},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 0},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 174},
  [127] = {.lex_state = 0},
  [128] = {.lex_state = 0},
  [129] = {.lex_state = 0},
  [130] = {.lex_state = 0},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 174},
  [134] = {.lex_state = 174},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 0},
  [157] = {.lex_state = 0},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 0},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [sym_argument_tag_open] = ACTIONS(1),
    [sym_argument_tag_close] = ACTIONS(1),
    [sym_condition_tag_open] = ACTIONS(1),
    [sym_condition_tag_close] = ACTIONS(1),
    [sym_else_tag_open] = ACTIONS(1),
    [sym_else_tag_close] = ACTIONS(1),
    [sym_elseif_tag_open] = ACTIONS(1),
    [sym_elseif_tag_close] = ACTIONS(1),
    [sym_if_tag_open] = ACTIONS(1),
    [sym_if_tag_close] = ACTIONS(1),
    [sym_include_tag_open] = ACTIONS(1),
    [sym_include_tag_close] = ACTIONS(1),
    [sym_self_closing_tag_end] = ACTIONS(1),
    [anon_sym_anchor_EQ] = ACTIONS(1),
    [anon_sym_condition_EQ] = ACTIONS(1),
    [anon_sym_contains_EQ] = ACTIONS(1),
    [anon_sym_default_EQ] = ACTIONS(1),
    [anon_sym_eq_EQ] = ACTIONS(1),
    [anon_sym_expression_EQ] = ACTIONS(1),
    [anon_sym_gt_EQ] = ACTIONS(1),
    [anon_sym_gte_EQ] = ACTIONS(1),
    [anon_sym_ic_EQ] = ACTIONS(1),
    [anon_sym_isNull_EQ] = ACTIONS(1),
    [anon_sym_locale_EQ] = ACTIONS(1),
    [anon_sym_lt_EQ] = ACTIONS(1),
    [anon_sym_lte_EQ] = ACTIONS(1),
    [anon_sym_module_EQ] = ACTIONS(1),
    [anon_sym_name_EQ] = ACTIONS(1),
    [anon_sym_neq_EQ] = ACTIONS(1),
    [anon_sym_object_EQ] = ACTIONS(1),
    [anon_sym_return_EQ] = ACTIONS(1),
    [anon_sym_template_EQ] = ACTIONS(1),
    [anon_sym_text_EQ] = ACTIONS(1),
    [anon_sym_uri_EQ] = ACTIONS(1),
    [anon_sym_value_EQ] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(165),
    [sym__top_level_tag] = STATE(36),
    [sym_condition_tag] = STATE(36),
    [sym_if_tag] = STATE(36),
    [sym_include_tag] = STATE(36),
    [aux_sym_document_repeat1] = STATE(36),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_condition_tag_open] = ACTIONS(5),
    [sym_if_tag_open] = ACTIONS(7),
    [sym_include_tag_open] = ACTIONS(9),
    [sym_text] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 13,
    ACTIONS(13), 1,
      anon_sym_GT,
    ACTIONS(15), 1,
      anon_sym_contains_EQ,
    ACTIONS(17), 1,
      anon_sym_eq_EQ,
    ACTIONS(19), 1,
      anon_sym_gt_EQ,
    ACTIONS(21), 1,
      anon_sym_gte_EQ,
    ACTIONS(23), 1,
      anon_sym_isNull_EQ,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(27), 1,
      anon_sym_lt_EQ,
    ACTIONS(29), 1,
      anon_sym_lte_EQ,
    ACTIONS(31), 1,
      anon_sym_neq_EQ,
    STATE(90), 1,
      sym_isNull_attribute,
    STATE(153), 1,
      sym_locale_attribute,
    STATE(58), 7,
      sym_contains_attribute,
      sym_eq_attribute,
      sym_gt_attribute,
      sym_gte_attribute,
      sym_lt_attribute,
      sym_lte_attribute,
      sym_neq_attribute,
  [46] = 13,
    ACTIONS(15), 1,
      anon_sym_contains_EQ,
    ACTIONS(17), 1,
      anon_sym_eq_EQ,
    ACTIONS(19), 1,
      anon_sym_gt_EQ,
    ACTIONS(21), 1,
      anon_sym_gte_EQ,
    ACTIONS(23), 1,
      anon_sym_isNull_EQ,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(27), 1,
      anon_sym_lt_EQ,
    ACTIONS(29), 1,
      anon_sym_lte_EQ,
    ACTIONS(31), 1,
      anon_sym_neq_EQ,
    ACTIONS(33), 1,
      anon_sym_GT,
    STATE(89), 1,
      sym_isNull_attribute,
    STATE(121), 1,
      sym_locale_attribute,
    STATE(57), 7,
      sym_contains_attribute,
      sym_eq_attribute,
      sym_gt_attribute,
      sym_gte_attribute,
      sym_lt_attribute,
      sym_lte_attribute,
      sym_neq_attribute,
  [92] = 13,
    ACTIONS(15), 1,
      anon_sym_contains_EQ,
    ACTIONS(17), 1,
      anon_sym_eq_EQ,
    ACTIONS(19), 1,
      anon_sym_gt_EQ,
    ACTIONS(21), 1,
      anon_sym_gte_EQ,
    ACTIONS(23), 1,
      anon_sym_isNull_EQ,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(27), 1,
      anon_sym_lt_EQ,
    ACTIONS(29), 1,
      anon_sym_lte_EQ,
    ACTIONS(31), 1,
      anon_sym_neq_EQ,
    ACTIONS(35), 1,
      anon_sym_GT,
    STATE(95), 1,
      sym_isNull_attribute,
    STATE(159), 1,
      sym_locale_attribute,
    STATE(60), 7,
      sym_contains_attribute,
      sym_eq_attribute,
      sym_gt_attribute,
      sym_gte_attribute,
      sym_lt_attribute,
      sym_lte_attribute,
      sym_neq_attribute,
  [138] = 1,
    ACTIONS(37), 16,
      anon_sym_GT,
      anon_sym_condition_EQ,
      anon_sym_contains_EQ,
      anon_sym_default_EQ,
      anon_sym_eq_EQ,
      anon_sym_expression_EQ,
      anon_sym_gt_EQ,
      anon_sym_gte_EQ,
      anon_sym_isNull_EQ,
      anon_sym_locale_EQ,
      anon_sym_lt_EQ,
      anon_sym_lte_EQ,
      anon_sym_neq_EQ,
      anon_sym_object_EQ,
      anon_sym_text_EQ,
      anon_sym_value_EQ,
  [157] = 11,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(39), 1,
      anon_sym_GT,
    ACTIONS(41), 1,
      anon_sym_condition_EQ,
    ACTIONS(43), 1,
      anon_sym_default_EQ,
    ACTIONS(45), 1,
      anon_sym_expression_EQ,
    ACTIONS(47), 1,
      anon_sym_object_EQ,
    ACTIONS(49), 1,
      anon_sym_text_EQ,
    ACTIONS(51), 1,
      anon_sym_value_EQ,
    STATE(7), 1,
      sym_default_attribute,
    STATE(9), 1,
      sym_locale_attribute,
    STATE(118), 5,
      sym_condition_attribute,
      sym_expression_attribute,
      sym_object_attribute,
      sym_text_attribute,
      sym_value_attribute,
  [195] = 9,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(41), 1,
      anon_sym_condition_EQ,
    ACTIONS(45), 1,
      anon_sym_expression_EQ,
    ACTIONS(47), 1,
      anon_sym_object_EQ,
    ACTIONS(49), 1,
      anon_sym_text_EQ,
    ACTIONS(51), 1,
      anon_sym_value_EQ,
    ACTIONS(53), 1,
      anon_sym_GT,
    STATE(10), 1,
      sym_locale_attribute,
    STATE(127), 5,
      sym_condition_attribute,
      sym_expression_attribute,
      sym_object_attribute,
      sym_text_attribute,
      sym_value_attribute,
  [227] = 7,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(57), 1,
      sym_condition_tag_open,
    ACTIONS(62), 1,
      sym_if_tag_open,
    ACTIONS(65), 1,
      sym_include_tag_open,
    ACTIONS(68), 1,
      sym_text,
    ACTIONS(60), 3,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [255] = 7,
    ACTIONS(41), 1,
      anon_sym_condition_EQ,
    ACTIONS(45), 1,
      anon_sym_expression_EQ,
    ACTIONS(47), 1,
      anon_sym_object_EQ,
    ACTIONS(49), 1,
      anon_sym_text_EQ,
    ACTIONS(51), 1,
      anon_sym_value_EQ,
    ACTIONS(53), 1,
      anon_sym_GT,
    STATE(127), 5,
      sym_condition_attribute,
      sym_expression_attribute,
      sym_object_attribute,
      sym_text_attribute,
      sym_value_attribute,
  [281] = 7,
    ACTIONS(41), 1,
      anon_sym_condition_EQ,
    ACTIONS(45), 1,
      anon_sym_expression_EQ,
    ACTIONS(47), 1,
      anon_sym_object_EQ,
    ACTIONS(49), 1,
      anon_sym_text_EQ,
    ACTIONS(51), 1,
      anon_sym_value_EQ,
    ACTIONS(71), 1,
      anon_sym_GT,
    STATE(115), 5,
      sym_condition_attribute,
      sym_expression_attribute,
      sym_object_attribute,
      sym_text_attribute,
      sym_value_attribute,
  [307] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(73), 1,
      sym_if_tag_close,
    ACTIONS(75), 1,
      sym_text,
    STATE(32), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [330] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(77), 1,
      sym_elseif_tag_close,
    ACTIONS(79), 1,
      sym_text,
    STATE(22), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [353] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(81), 1,
      sym_elseif_tag_close,
    ACTIONS(83), 1,
      sym_text,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [376] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(85), 1,
      sym_if_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [399] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(81), 1,
      sym_elseif_tag_close,
    ACTIONS(87), 1,
      sym_text,
    STATE(34), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [422] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(89), 1,
      sym_if_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [445] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(91), 1,
      sym_if_tag_close,
    ACTIONS(93), 1,
      sym_text,
    STATE(16), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [468] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(91), 1,
      sym_if_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [491] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(95), 1,
      sym_elseif_tag_close,
    ACTIONS(97), 1,
      sym_text,
    STATE(21), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [514] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(99), 1,
      sym_elseif_tag_close,
    ACTIONS(101), 1,
      sym_text,
    STATE(13), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [537] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(99), 1,
      sym_elseif_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [560] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(95), 1,
      sym_elseif_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [583] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(103), 1,
      sym_if_tag_close,
    ACTIONS(105), 1,
      sym_text,
    STATE(33), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [606] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(107), 1,
      sym_if_tag_close,
    ACTIONS(109), 1,
      sym_text,
    STATE(18), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [629] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(107), 1,
      sym_if_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [652] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(111), 1,
      sym_if_tag_close,
    ACTIONS(113), 1,
      sym_text,
    STATE(25), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [675] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(111), 1,
      sym_if_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [698] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(115), 1,
      sym_if_tag_close,
    ACTIONS(117), 1,
      sym_text,
    STATE(27), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [721] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(119), 1,
      sym_else_tag_close,
    ACTIONS(121), 1,
      sym_text,
    STATE(37), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [744] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(123), 1,
      sym_if_tag_close,
    ACTIONS(125), 1,
      sym_text,
    STATE(35), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [767] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(127), 1,
      sym_if_tag_close,
    ACTIONS(129), 1,
      sym_text,
    STATE(14), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [790] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(127), 1,
      sym_if_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [813] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(123), 1,
      sym_if_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [836] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(131), 1,
      sym_elseif_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [859] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(73), 1,
      sym_if_tag_close,
    ACTIONS(83), 1,
      sym_text,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [882] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(133), 1,
      ts_builtin_sym_end,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [905] = 6,
    ACTIONS(5), 1,
      sym_condition_tag_open,
    ACTIONS(7), 1,
      sym_if_tag_open,
    ACTIONS(9), 1,
      sym_include_tag_open,
    ACTIONS(83), 1,
      sym_text,
    ACTIONS(135), 1,
      sym_else_tag_close,
    STATE(8), 5,
      sym__top_level_tag,
      sym_condition_tag,
      sym_if_tag,
      sym_include_tag,
      aux_sym_document_repeat1,
  [928] = 2,
    ACTIONS(137), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(139), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [941] = 2,
    ACTIONS(141), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(143), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [954] = 2,
    ACTIONS(145), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(147), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [967] = 2,
    ACTIONS(149), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(151), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [980] = 2,
    ACTIONS(153), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(155), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [993] = 2,
    ACTIONS(157), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(159), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [1006] = 2,
    ACTIONS(161), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(163), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [1019] = 2,
    ACTIONS(165), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(167), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [1032] = 2,
    ACTIONS(169), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(171), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [1045] = 2,
    ACTIONS(173), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(175), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [1058] = 2,
    ACTIONS(177), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(179), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [1071] = 2,
    ACTIONS(181), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(183), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [1084] = 6,
    ACTIONS(185), 1,
      anon_sym_anchor_EQ,
    ACTIONS(187), 1,
      anon_sym_module_EQ,
    ACTIONS(189), 1,
      anon_sym_template_EQ,
    ACTIONS(191), 1,
      anon_sym_uri_EQ,
    STATE(56), 1,
      sym_module_attribute,
    STATE(63), 3,
      sym_anchor_attribute,
      sym_template_attribute,
      sym_uri_attribute,
  [1105] = 2,
    ACTIONS(193), 2,
      ts_builtin_sym_end,
      sym_text,
    ACTIONS(195), 6,
      sym_condition_tag_open,
      sym_else_tag_close,
      sym_elseif_tag_close,
      sym_if_tag_open,
      sym_if_tag_close,
      sym_include_tag_open,
  [1118] = 1,
    ACTIONS(197), 7,
      anon_sym_GT,
      anon_sym_condition_EQ,
      anon_sym_expression_EQ,
      anon_sym_locale_EQ,
      anon_sym_object_EQ,
      anon_sym_text_EQ,
      anon_sym_value_EQ,
  [1128] = 5,
    ACTIONS(199), 1,
      sym_condition_tag_close,
    ACTIONS(201), 1,
      sym_else_tag_open,
    ACTIONS(203), 1,
      sym_elseif_tag_open,
    STATE(130), 1,
      sym_else_tag,
    STATE(59), 2,
      sym_elseif_tag,
      aux_sym_condition_tag_repeat1,
  [1145] = 1,
    ACTIONS(205), 6,
      anon_sym_GT,
      anon_sym_condition_EQ,
      anon_sym_expression_EQ,
      anon_sym_object_EQ,
      anon_sym_text_EQ,
      anon_sym_value_EQ,
  [1154] = 5,
    ACTIONS(201), 1,
      sym_else_tag_open,
    ACTIONS(203), 1,
      sym_elseif_tag_open,
    ACTIONS(207), 1,
      sym_condition_tag_close,
    STATE(141), 1,
      sym_else_tag,
    STATE(53), 2,
      sym_elseif_tag,
      aux_sym_condition_tag_repeat1,
  [1171] = 4,
    ACTIONS(185), 1,
      anon_sym_anchor_EQ,
    ACTIONS(189), 1,
      anon_sym_template_EQ,
    ACTIONS(191), 1,
      anon_sym_uri_EQ,
    STATE(72), 3,
      sym_anchor_attribute,
      sym_template_attribute,
      sym_uri_attribute,
  [1186] = 5,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(209), 1,
      anon_sym_GT,
    ACTIONS(211), 1,
      anon_sym_ic_EQ,
    STATE(101), 1,
      sym_ic_attribute,
    STATE(117), 1,
      sym_locale_attribute,
  [1202] = 5,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(211), 1,
      anon_sym_ic_EQ,
    ACTIONS(213), 1,
      anon_sym_GT,
    STATE(82), 1,
      sym_ic_attribute,
    STATE(136), 1,
      sym_locale_attribute,
  [1218] = 4,
    ACTIONS(215), 1,
      sym_condition_tag_close,
    ACTIONS(217), 1,
      sym_else_tag_open,
    ACTIONS(219), 1,
      sym_elseif_tag_open,
    STATE(59), 2,
      sym_elseif_tag,
      aux_sym_condition_tag_repeat1,
  [1232] = 5,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(211), 1,
      anon_sym_ic_EQ,
    ACTIONS(222), 1,
      anon_sym_GT,
    STATE(81), 1,
      sym_ic_attribute,
    STATE(163), 1,
      sym_locale_attribute,
  [1248] = 4,
    ACTIONS(41), 1,
      anon_sym_condition_EQ,
    ACTIONS(224), 1,
      anon_sym_name_EQ,
    STATE(4), 1,
      sym_name_attribute,
    STATE(103), 1,
      sym_condition_attribute,
  [1261] = 3,
    ACTIONS(226), 1,
      sym_argument_tag_open,
    ACTIONS(228), 1,
      sym_include_tag_close,
    STATE(66), 2,
      sym_argument_tag,
      aux_sym_include_tag_repeat1,
  [1272] = 4,
    ACTIONS(230), 1,
      anon_sym_GT,
    ACTIONS(232), 1,
      sym_self_closing_tag_end,
    ACTIONS(234), 1,
      anon_sym_return_EQ,
    STATE(104), 1,
      sym_return_attribute,
  [1285] = 3,
    ACTIONS(226), 1,
      sym_argument_tag_open,
    ACTIONS(236), 1,
      sym_include_tag_close,
    STATE(70), 2,
      sym_argument_tag,
      aux_sym_include_tag_repeat1,
  [1296] = 4,
    ACTIONS(41), 1,
      anon_sym_condition_EQ,
    ACTIONS(224), 1,
      anon_sym_name_EQ,
    STATE(2), 1,
      sym_name_attribute,
    STATE(97), 1,
      sym_condition_attribute,
  [1309] = 3,
    ACTIONS(226), 1,
      sym_argument_tag_open,
    ACTIONS(238), 1,
      sym_include_tag_close,
    STATE(70), 2,
      sym_argument_tag,
      aux_sym_include_tag_repeat1,
  [1320] = 3,
    ACTIONS(226), 1,
      sym_argument_tag_open,
    ACTIONS(240), 1,
      sym_include_tag_close,
    STATE(64), 2,
      sym_argument_tag,
      aux_sym_include_tag_repeat1,
  [1331] = 3,
    ACTIONS(226), 1,
      sym_argument_tag_open,
    ACTIONS(238), 1,
      sym_include_tag_close,
    STATE(69), 2,
      sym_argument_tag,
      aux_sym_include_tag_repeat1,
  [1342] = 3,
    ACTIONS(226), 1,
      sym_argument_tag_open,
    ACTIONS(240), 1,
      sym_include_tag_close,
    STATE(70), 2,
      sym_argument_tag,
      aux_sym_include_tag_repeat1,
  [1353] = 3,
    ACTIONS(242), 1,
      sym_argument_tag_open,
    ACTIONS(245), 1,
      sym_include_tag_close,
    STATE(70), 2,
      sym_argument_tag,
      aux_sym_include_tag_repeat1,
  [1364] = 4,
    ACTIONS(41), 1,
      anon_sym_condition_EQ,
    ACTIONS(224), 1,
      anon_sym_name_EQ,
    STATE(3), 1,
      sym_name_attribute,
    STATE(88), 1,
      sym_condition_attribute,
  [1377] = 4,
    ACTIONS(228), 1,
      sym_self_closing_tag_end,
    ACTIONS(234), 1,
      anon_sym_return_EQ,
    ACTIONS(247), 1,
      anon_sym_GT,
    STATE(114), 1,
      sym_return_attribute,
  [1390] = 1,
    ACTIONS(249), 3,
      anon_sym_GT,
      sym_self_closing_tag_end,
      anon_sym_return_EQ,
  [1396] = 1,
    ACTIONS(251), 3,
      anon_sym_GT,
      sym_self_closing_tag_end,
      anon_sym_return_EQ,
  [1402] = 1,
    ACTIONS(253), 3,
      anon_sym_GT,
      anon_sym_ic_EQ,
      anon_sym_locale_EQ,
  [1408] = 1,
    ACTIONS(255), 3,
      anon_sym_GT,
      anon_sym_ic_EQ,
      anon_sym_locale_EQ,
  [1414] = 2,
    ACTIONS(259), 1,
      sym_else_tag_open,
    ACTIONS(257), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1422] = 1,
    ACTIONS(261), 3,
      anon_sym_GT,
      anon_sym_ic_EQ,
      anon_sym_locale_EQ,
  [1428] = 2,
    ACTIONS(265), 1,
      sym_else_tag_open,
    ACTIONS(263), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1436] = 2,
    ACTIONS(269), 1,
      sym_else_tag_open,
    ACTIONS(267), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1444] = 3,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(271), 1,
      anon_sym_GT,
    STATE(164), 1,
      sym_locale_attribute,
  [1454] = 3,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(273), 1,
      anon_sym_GT,
    STATE(129), 1,
      sym_locale_attribute,
  [1464] = 2,
    ACTIONS(277), 1,
      sym_else_tag_open,
    ACTIONS(275), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1472] = 1,
    ACTIONS(279), 3,
      anon_sym_GT,
      anon_sym_ic_EQ,
      anon_sym_locale_EQ,
  [1478] = 1,
    ACTIONS(281), 3,
      anon_sym_GT,
      anon_sym_ic_EQ,
      anon_sym_locale_EQ,
  [1484] = 1,
    ACTIONS(283), 3,
      anon_sym_GT,
      sym_self_closing_tag_end,
      anon_sym_return_EQ,
  [1490] = 1,
    ACTIONS(285), 3,
      anon_sym_anchor_EQ,
      anon_sym_template_EQ,
      anon_sym_uri_EQ,
  [1496] = 3,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(33), 1,
      anon_sym_GT,
    STATE(121), 1,
      sym_locale_attribute,
  [1506] = 3,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(209), 1,
      anon_sym_GT,
    STATE(117), 1,
      sym_locale_attribute,
  [1516] = 3,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(213), 1,
      anon_sym_GT,
    STATE(136), 1,
      sym_locale_attribute,
  [1526] = 1,
    ACTIONS(287), 3,
      anon_sym_GT,
      anon_sym_ic_EQ,
      anon_sym_locale_EQ,
  [1532] = 2,
    ACTIONS(179), 1,
      sym_else_tag_open,
    ACTIONS(177), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1540] = 2,
    ACTIONS(167), 1,
      sym_else_tag_open,
    ACTIONS(165), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1548] = 2,
    ACTIONS(183), 1,
      sym_else_tag_open,
    ACTIONS(181), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1556] = 3,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(222), 1,
      anon_sym_GT,
    STATE(163), 1,
      sym_locale_attribute,
  [1566] = 2,
    ACTIONS(155), 1,
      sym_else_tag_open,
    ACTIONS(153), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1574] = 3,
    ACTIONS(13), 1,
      anon_sym_GT,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    STATE(153), 1,
      sym_locale_attribute,
  [1584] = 2,
    ACTIONS(291), 1,
      sym_else_tag_open,
    ACTIONS(289), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1592] = 2,
    ACTIONS(143), 1,
      sym_else_tag_open,
    ACTIONS(141), 2,
      sym_condition_tag_close,
      sym_elseif_tag_open,
  [1600] = 1,
    ACTIONS(293), 3,
      anon_sym_GT,
      sym_self_closing_tag_end,
      anon_sym_locale_EQ,
  [1606] = 3,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(295), 1,
      anon_sym_GT,
    STATE(131), 1,
      sym_locale_attribute,
  [1616] = 1,
    ACTIONS(297), 3,
      anon_sym_GT,
      anon_sym_ic_EQ,
      anon_sym_locale_EQ,
  [1622] = 3,
    ACTIONS(25), 1,
      anon_sym_locale_EQ,
    ACTIONS(35), 1,
      anon_sym_GT,
    STATE(159), 1,
      sym_locale_attribute,
  [1632] = 2,
    ACTIONS(228), 1,
      sym_self_closing_tag_end,
    ACTIONS(247), 1,
      anon_sym_GT,
  [1639] = 1,
    ACTIONS(299), 2,
      sym_argument_tag_open,
      sym_include_tag_close,
  [1644] = 2,
    ACTIONS(301), 1,
      sym_if_tag_open,
    STATE(55), 1,
      sym_if_tag,
  [1651] = 1,
    ACTIONS(303), 2,
      sym_argument_tag_open,
      sym_include_tag_close,
  [1656] = 1,
    ACTIONS(305), 2,
      anon_sym_GT,
      anon_sym_locale_EQ,
  [1661] = 1,
    ACTIONS(307), 2,
      sym_argument_tag_open,
      sym_include_tag_close,
  [1666] = 2,
    ACTIONS(224), 1,
      anon_sym_name_EQ,
    STATE(6), 1,
      sym_name_attribute,
  [1673] = 1,
    ACTIONS(309), 2,
      sym_argument_tag_open,
      sym_include_tag_close,
  [1678] = 1,
    ACTIONS(311), 2,
      anon_sym_GT,
      anon_sym_locale_EQ,
  [1683] = 1,
    ACTIONS(313), 2,
      anon_sym_GT,
      sym_self_closing_tag_end,
  [1688] = 2,
    ACTIONS(238), 1,
      sym_self_closing_tag_end,
    ACTIONS(315), 1,
      anon_sym_GT,
  [1695] = 1,
    ACTIONS(317), 1,
      sym_self_closing_tag_end,
  [1699] = 1,
    ACTIONS(319), 1,
      sym_string,
  [1703] = 1,
    ACTIONS(295), 1,
      anon_sym_GT,
  [1707] = 1,
    ACTIONS(321), 1,
      sym_self_closing_tag_end,
  [1711] = 1,
    ACTIONS(323), 1,
      sym_condition_tag_close,
  [1715] = 1,
    ACTIONS(325), 1,
      sym_argument_tag_close,
  [1719] = 1,
    ACTIONS(209), 1,
      anon_sym_GT,
  [1723] = 1,
    ACTIONS(327), 1,
      sym_self_closing_tag_end,
  [1727] = 1,
    ACTIONS(329), 1,
      sym_self_closing_tag_end,
  [1731] = 1,
    ACTIONS(331), 1,
      sym_self_closing_tag_end,
  [1735] = 1,
    ACTIONS(333), 1,
      sym_self_closing_tag_end,
  [1739] = 1,
    ACTIONS(335), 1,
      sym_text,
  [1743] = 1,
    ACTIONS(325), 1,
      sym_self_closing_tag_end,
  [1747] = 1,
    ACTIONS(337), 1,
      anon_sym_GT,
  [1751] = 1,
    ACTIONS(339), 1,
      anon_sym_GT,
  [1755] = 1,
    ACTIONS(341), 1,
      sym_condition_tag_close,
  [1759] = 1,
    ACTIONS(343), 1,
      anon_sym_GT,
  [1763] = 1,
    ACTIONS(317), 1,
      sym_argument_tag_close,
  [1767] = 1,
    ACTIONS(345), 1,
      sym_text,
  [1771] = 1,
    ACTIONS(347), 1,
      sym_text,
  [1775] = 1,
    ACTIONS(349), 1,
      sym_string,
  [1779] = 1,
    ACTIONS(273), 1,
      anon_sym_GT,
  [1783] = 1,
    ACTIONS(351), 1,
      sym_string,
  [1787] = 1,
    ACTIONS(353), 1,
      sym_string,
  [1791] = 1,
    ACTIONS(355), 1,
      sym_argument_tag_close,
  [1795] = 1,
    ACTIONS(357), 1,
      sym_string,
  [1799] = 1,
    ACTIONS(199), 1,
      sym_condition_tag_close,
  [1803] = 1,
    ACTIONS(359), 1,
      sym_string,
  [1807] = 1,
    ACTIONS(361), 1,
      anon_sym_GT,
  [1811] = 1,
    ACTIONS(363), 1,
      sym_string,
  [1815] = 1,
    ACTIONS(365), 1,
      sym_string,
  [1819] = 1,
    ACTIONS(367), 1,
      sym_string,
  [1823] = 1,
    ACTIONS(369), 1,
      sym_string,
  [1827] = 1,
    ACTIONS(371), 1,
      sym_string,
  [1831] = 1,
    ACTIONS(373), 1,
      sym_string,
  [1835] = 1,
    ACTIONS(375), 1,
      sym_string,
  [1839] = 1,
    ACTIONS(377), 1,
      sym_string,
  [1843] = 1,
    ACTIONS(379), 1,
      sym_string,
  [1847] = 1,
    ACTIONS(213), 1,
      anon_sym_GT,
  [1851] = 1,
    ACTIONS(381), 1,
      sym_string,
  [1855] = 1,
    ACTIONS(383), 1,
      sym_string,
  [1859] = 1,
    ACTIONS(385), 1,
      sym_string,
  [1863] = 1,
    ACTIONS(387), 1,
      sym_string,
  [1867] = 1,
    ACTIONS(389), 1,
      sym_string,
  [1871] = 1,
    ACTIONS(222), 1,
      anon_sym_GT,
  [1875] = 1,
    ACTIONS(391), 1,
      sym_string,
  [1879] = 1,
    ACTIONS(393), 1,
      sym_string,
  [1883] = 1,
    ACTIONS(395), 1,
      sym_condition_tag_close,
  [1887] = 1,
    ACTIONS(271), 1,
      anon_sym_GT,
  [1891] = 1,
    ACTIONS(397), 1,
      anon_sym_GT,
  [1895] = 1,
    ACTIONS(399), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 46,
  [SMALL_STATE(4)] = 92,
  [SMALL_STATE(5)] = 138,
  [SMALL_STATE(6)] = 157,
  [SMALL_STATE(7)] = 195,
  [SMALL_STATE(8)] = 227,
  [SMALL_STATE(9)] = 255,
  [SMALL_STATE(10)] = 281,
  [SMALL_STATE(11)] = 307,
  [SMALL_STATE(12)] = 330,
  [SMALL_STATE(13)] = 353,
  [SMALL_STATE(14)] = 376,
  [SMALL_STATE(15)] = 399,
  [SMALL_STATE(16)] = 422,
  [SMALL_STATE(17)] = 445,
  [SMALL_STATE(18)] = 468,
  [SMALL_STATE(19)] = 491,
  [SMALL_STATE(20)] = 514,
  [SMALL_STATE(21)] = 537,
  [SMALL_STATE(22)] = 560,
  [SMALL_STATE(23)] = 583,
  [SMALL_STATE(24)] = 606,
  [SMALL_STATE(25)] = 629,
  [SMALL_STATE(26)] = 652,
  [SMALL_STATE(27)] = 675,
  [SMALL_STATE(28)] = 698,
  [SMALL_STATE(29)] = 721,
  [SMALL_STATE(30)] = 744,
  [SMALL_STATE(31)] = 767,
  [SMALL_STATE(32)] = 790,
  [SMALL_STATE(33)] = 813,
  [SMALL_STATE(34)] = 836,
  [SMALL_STATE(35)] = 859,
  [SMALL_STATE(36)] = 882,
  [SMALL_STATE(37)] = 905,
  [SMALL_STATE(38)] = 928,
  [SMALL_STATE(39)] = 941,
  [SMALL_STATE(40)] = 954,
  [SMALL_STATE(41)] = 967,
  [SMALL_STATE(42)] = 980,
  [SMALL_STATE(43)] = 993,
  [SMALL_STATE(44)] = 1006,
  [SMALL_STATE(45)] = 1019,
  [SMALL_STATE(46)] = 1032,
  [SMALL_STATE(47)] = 1045,
  [SMALL_STATE(48)] = 1058,
  [SMALL_STATE(49)] = 1071,
  [SMALL_STATE(50)] = 1084,
  [SMALL_STATE(51)] = 1105,
  [SMALL_STATE(52)] = 1118,
  [SMALL_STATE(53)] = 1128,
  [SMALL_STATE(54)] = 1145,
  [SMALL_STATE(55)] = 1154,
  [SMALL_STATE(56)] = 1171,
  [SMALL_STATE(57)] = 1186,
  [SMALL_STATE(58)] = 1202,
  [SMALL_STATE(59)] = 1218,
  [SMALL_STATE(60)] = 1232,
  [SMALL_STATE(61)] = 1248,
  [SMALL_STATE(62)] = 1261,
  [SMALL_STATE(63)] = 1272,
  [SMALL_STATE(64)] = 1285,
  [SMALL_STATE(65)] = 1296,
  [SMALL_STATE(66)] = 1309,
  [SMALL_STATE(67)] = 1320,
  [SMALL_STATE(68)] = 1331,
  [SMALL_STATE(69)] = 1342,
  [SMALL_STATE(70)] = 1353,
  [SMALL_STATE(71)] = 1364,
  [SMALL_STATE(72)] = 1377,
  [SMALL_STATE(73)] = 1390,
  [SMALL_STATE(74)] = 1396,
  [SMALL_STATE(75)] = 1402,
  [SMALL_STATE(76)] = 1408,
  [SMALL_STATE(77)] = 1414,
  [SMALL_STATE(78)] = 1422,
  [SMALL_STATE(79)] = 1428,
  [SMALL_STATE(80)] = 1436,
  [SMALL_STATE(81)] = 1444,
  [SMALL_STATE(82)] = 1454,
  [SMALL_STATE(83)] = 1464,
  [SMALL_STATE(84)] = 1472,
  [SMALL_STATE(85)] = 1478,
  [SMALL_STATE(86)] = 1484,
  [SMALL_STATE(87)] = 1490,
  [SMALL_STATE(88)] = 1496,
  [SMALL_STATE(89)] = 1506,
  [SMALL_STATE(90)] = 1516,
  [SMALL_STATE(91)] = 1526,
  [SMALL_STATE(92)] = 1532,
  [SMALL_STATE(93)] = 1540,
  [SMALL_STATE(94)] = 1548,
  [SMALL_STATE(95)] = 1556,
  [SMALL_STATE(96)] = 1566,
  [SMALL_STATE(97)] = 1574,
  [SMALL_STATE(98)] = 1584,
  [SMALL_STATE(99)] = 1592,
  [SMALL_STATE(100)] = 1600,
  [SMALL_STATE(101)] = 1606,
  [SMALL_STATE(102)] = 1616,
  [SMALL_STATE(103)] = 1622,
  [SMALL_STATE(104)] = 1632,
  [SMALL_STATE(105)] = 1639,
  [SMALL_STATE(106)] = 1644,
  [SMALL_STATE(107)] = 1651,
  [SMALL_STATE(108)] = 1656,
  [SMALL_STATE(109)] = 1661,
  [SMALL_STATE(110)] = 1666,
  [SMALL_STATE(111)] = 1673,
  [SMALL_STATE(112)] = 1678,
  [SMALL_STATE(113)] = 1683,
  [SMALL_STATE(114)] = 1688,
  [SMALL_STATE(115)] = 1695,
  [SMALL_STATE(116)] = 1699,
  [SMALL_STATE(117)] = 1703,
  [SMALL_STATE(118)] = 1707,
  [SMALL_STATE(119)] = 1711,
  [SMALL_STATE(120)] = 1715,
  [SMALL_STATE(121)] = 1719,
  [SMALL_STATE(122)] = 1723,
  [SMALL_STATE(123)] = 1727,
  [SMALL_STATE(124)] = 1731,
  [SMALL_STATE(125)] = 1735,
  [SMALL_STATE(126)] = 1739,
  [SMALL_STATE(127)] = 1743,
  [SMALL_STATE(128)] = 1747,
  [SMALL_STATE(129)] = 1751,
  [SMALL_STATE(130)] = 1755,
  [SMALL_STATE(131)] = 1759,
  [SMALL_STATE(132)] = 1763,
  [SMALL_STATE(133)] = 1767,
  [SMALL_STATE(134)] = 1771,
  [SMALL_STATE(135)] = 1775,
  [SMALL_STATE(136)] = 1779,
  [SMALL_STATE(137)] = 1783,
  [SMALL_STATE(138)] = 1787,
  [SMALL_STATE(139)] = 1791,
  [SMALL_STATE(140)] = 1795,
  [SMALL_STATE(141)] = 1799,
  [SMALL_STATE(142)] = 1803,
  [SMALL_STATE(143)] = 1807,
  [SMALL_STATE(144)] = 1811,
  [SMALL_STATE(145)] = 1815,
  [SMALL_STATE(146)] = 1819,
  [SMALL_STATE(147)] = 1823,
  [SMALL_STATE(148)] = 1827,
  [SMALL_STATE(149)] = 1831,
  [SMALL_STATE(150)] = 1835,
  [SMALL_STATE(151)] = 1839,
  [SMALL_STATE(152)] = 1843,
  [SMALL_STATE(153)] = 1847,
  [SMALL_STATE(154)] = 1851,
  [SMALL_STATE(155)] = 1855,
  [SMALL_STATE(156)] = 1859,
  [SMALL_STATE(157)] = 1863,
  [SMALL_STATE(158)] = 1867,
  [SMALL_STATE(159)] = 1871,
  [SMALL_STATE(160)] = 1875,
  [SMALL_STATE(161)] = 1879,
  [SMALL_STATE(162)] = 1883,
  [SMALL_STATE(163)] = 1887,
  [SMALL_STATE(164)] = 1891,
  [SMALL_STATE(165)] = 1895,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(151),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(150),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(149),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(148),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(154),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(147),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(145),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_name_attribute, 2),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(134),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(161),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(135),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(142),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(138),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(140),
  [53] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [57] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(128),
  [60] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2),
  [62] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(65),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(50),
  [68] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(8),
  [71] = {.entry = {.count = 1, .reusable = true}}, SHIFT(133),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(77),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(119),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [127] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(162),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_tag, 6),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_tag, 6),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_tag, 8),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_tag, 8),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_tag, 3),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_tag, 3),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_tag, 7),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_tag, 7),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_tag, 7),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_tag, 7),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition_tag, 4),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_condition_tag, 4),
  [161] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition_tag, 6),
  [163] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_condition_tag, 6),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_tag, 5),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_tag, 5),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_tag, 4),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_tag, 4),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_include_tag, 5),
  [175] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_include_tag, 5),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_tag, 4),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_tag, 4),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_tag, 6),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_tag, 6),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(158),
  [187] = {.entry = {.count = 1, .reusable = true}}, SHIFT(157),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition_tag, 5),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_condition_tag, 5),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_default_attribute, 2),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(143),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_locale_attribute, 2),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(137),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_condition_tag_repeat1, 2),
  [217] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_condition_tag_repeat1, 2),
  [219] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_condition_tag_repeat1, 2), SHIFT_REPEAT(71),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [224] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [226] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(144),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [242] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_include_tag_repeat1, 2), SHIFT_REPEAT(110),
  [245] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_include_tag_repeat1, 2),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_uri_attribute, 2),
  [251] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_anchor_attribute, 2),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lte_attribute, 2),
  [255] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_eq_attribute, 2),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elseif_tag, 5),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_tag, 5),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_contains_attribute, 2),
  [263] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elseif_tag, 7),
  [265] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_tag, 7),
  [267] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elseif_tag, 8),
  [269] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_tag, 8),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elseif_tag, 6),
  [277] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_tag, 6),
  [279] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gt_attribute, 2),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_gte_attribute, 2),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template_attribute, 2),
  [285] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module_attribute, 2),
  [287] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_lt_attribute, 2),
  [289] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_elseif_tag, 4),
  [291] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_elseif_tag, 4),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_condition_attribute, 2),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [297] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_neq_attribute, 2),
  [299] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_tag, 5),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [303] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_tag, 7),
  [305] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_isNull_attribute, 2),
  [307] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_tag, 6),
  [309] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_tag, 4),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ic_attribute, 2),
  [313] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_attribute, 2),
  [315] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [317] = {.entry = {.count = 1, .reusable = true}}, SHIFT(109),
  [319] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [321] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_tag, 3),
  [325] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_attribute, 2),
  [329] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_object_attribute, 2),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text_attribute, 2),
  [333] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value_attribute, 2),
  [335] = {.entry = {.count = 1, .reusable = true}}, SHIFT(132),
  [337] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [339] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [341] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [343] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [345] = {.entry = {.count = 1, .reusable = true}}, SHIFT(139),
  [347] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [349] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [351] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [353] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [355] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
  [357] = {.entry = {.count = 1, .reusable = true}}, SHIFT(125),
  [359] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [361] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [363] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [365] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [367] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [369] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [385] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [387] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [389] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [391] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [393] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [395] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_else_tag, 4),
  [397] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [399] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_spml(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
