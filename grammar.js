/**
 * @file SPML grammar for tree-sitter
 * @author Mario Schäper
 * @license MIT
 */

/* eslint-disable arrow-parens */
/* eslint-disable camelcase */
/* eslint-disable-next-line spaced-comment */
/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
	name: 'spml',

	rules: {

		document: $ => seq(
			optional($.comment),
			$.page_header,
			optional($.comment),
			repeat1($.taglib_header),
			repeat($._top_level_tag),
		),

		_top_level_tag: $ => choice(
			$.collection_tag,
			$.comment,
			$.condition_tag,
			$.if_tag,
			$.include_tag,
			$.loop_tag,
			$.map_tag,
			$.print_tag,
			$.return_tag,
			$.set_tag,
			$.text,
		),

		_tag_value_body: $ => choice(
			$.comment,
			$.print_tag,
			$.text,
		),

		page_header: $ => seq(
			$.header_open,
			'page',
			$.language_attribute,
			$.pageEncoding_attribute,
			$.contentType_attribute,
			$.header_close,
		),

		taglib_header: $ => seq(
			$.header_open,
			'taglib',
			choice(
				$.uri_attribute,
				$.tagdir_attribute,
			),
			$.prefix_attribute,
			$.header_close,
		),

		header_open: $ => '<%@',
		header_close: $ => '%>',

		// tags

		argument_tag: $ => seq(
			$.argument_tag_open,
			repeat(
				choice(
					$.condition_attribute,
					$.default_attribute,
					$.expression_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.object_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._tag_value_body),
					$.argument_tag_close,
				),
			),
		),
		argument_tag_open: $ => '<sp:argument',
		argument_tag_close: $ => '</sp:argument>',

		collection_tag: $ => seq(
			$.collection_tag_open,
			repeat(
				choice(
					$.action_attribute,
					$.condition_attribute,
					$.default_attribute,
					$.expression_attribute,
					$.index_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.object_attribute,
					$.publisher_attribute,
					$.query_attribute,
					$.scope_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._tag_value_body),
					$.collection_tag_close,
				),
			),
		),
		collection_tag_open: $ => '<sp:collection',
		collection_tag_close: $ => '</sp:collection>',

		condition_tag: $ => seq(
			$.condition_tag_open,
			'>',
			repeat($.comment),
			$.if_tag,
			repeat(
				choice(
					prec(2, $.comment),
					$.elseif_tag,
				),
			),
			optional($.else_tag),
			repeat(
				prec(1, $.comment),
			),
			$.condition_tag_close,
		),
		condition_tag_open: $ => '<sp:condition',
		condition_tag_close: $ => '</sp:condition>',

		else_tag: $ => seq(
			$.else_tag_open,
			'>',
			repeat($._top_level_tag),
			$.else_tag_close,
		),
		else_tag_open: $ => '<sp:else',
		else_tag_close: $ => '</sp:else>',

		elseif_tag: $ => seq(
			$.elseif_tag_open,
			repeat(
				choice(
					$.condition_attribute,
					$.contains_attribute,
					$.eq_attribute,
					$.gt_attribute,
					$.gte_attribute,
					$.ic_attribute,
					$.isNull_attribute,
					$.locale_attribute,
					$.lt_attribute,
					$.lte_attribute,
					$.name_attribute,
					$.neq_attribute,
				),
			),
			'>',
			repeat($._top_level_tag),
			$.elseif_tag_close,
		),
		elseif_tag_open: $ => '<sp:elseif',
		elseif_tag_close: $ => '</sp:elseif>',

		if_tag: $ => seq(
			$.if_tag_open,
			repeat(
				choice(
					$.condition_attribute,
					$.contains_attribute,
					$.eq_attribute,
					$.gt_attribute,
					$.gte_attribute,
					$.ic_attribute,
					$.isNull_attribute,
					$.locale_attribute,
					$.lt_attribute,
					$.lte_attribute,
					$.name_attribute,
					$.neq_attribute,
				),
			),
			'>',
			repeat($._top_level_tag),
			$.if_tag_close,
		),
		if_tag_open: $ => '<sp:if',
		if_tag_close: $ => '</sp:if>',

		include_tag: $ => seq(
			$.include_tag_open,
			repeat(
				choice(
					$.anchor_attribute,
					$.module_attribute,
					$.return_attribute,
					$.template_attribute,
					$.uri_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat(
						choice(
							$.argument_tag,
							$.comment,
						),
					),
					$.include_tag_close,
				),
			),
		),
		include_tag_open: $ => '<sp:include',
		include_tag_close: $ => '</sp:include>',

		loop_tag: $ => seq(
			$.loop_tag_open,
			repeat(
				choice(
					$.collection_attribute,
					$.list_attribute,
					$.separator_attribute,
					$.item_attribute,
					$.locale_attribute,
				),
			),
			'>',
			repeat($._top_level_tag),
			$.loop_tag_close,
		),
		loop_tag_open: $ => '<sp:loop',
		loop_tag_close: $ => '</sp:loop>',

		map_tag: $ => seq(
			$.map_tag_open,
			repeat(
				choice(
					$.action_attribute,
					$.condition_attribute,
					$.default_attribute,
					$.expression_attribute,
					$.key_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.object_attribute,
					$.overwrite_attribute,
					$.scope_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._tag_value_body),
					$.map_tag_close,
				),
			),
		),
		map_tag_open: $ => '<sp:map',
		map_tag_close: $ => '</sp:map>',

		set_tag: $ => seq(
			$.set_tag_open,
			repeat(
				choice(
					$.condition_attribute,
					$.contentType_attribute,
					$.default_attribute,
					$.expression_attribute,
					$.insert_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.object_attribute,
					$.overwrite_attribute,
					$.scope_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._tag_value_body),
					$.set_tag_close,
				),
			),
		),
		set_tag_open: $ => '<sp:set',
		set_tag_close: $ => '</sp:set>',

		print_tag: $ => seq(
			$.print_tag_open,
			repeat(
				choice(
					$.arg_attribute,
					$.condition_attribute,
					$.convert_attribute,
					$.cryptkey_attribute,
					$.decimalformat_attribute,
					$.decoding_attribute,
					$.decrypt_attribute,
					$.default_attribute,
					$.encoding_attribute,
					$.encrypt_attribute,
					$.expression_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.text_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		print_tag_open: $ => '<sp:print',

		return_tag: $ => seq(
			$.return_tag_open,
			repeat(
				choice(
					$.condition_attribute,
					$.default_attribute,
					$.expression_attribute,
					$.locale_attribute,
					$.object_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._tag_value_body),
					$.return_tag_close,
				),
			),
		),
		return_tag_open: $ => '<sp:return',
		return_tag_close: $ => '</sp:return>',

		self_closing_tag_end: $ => '/>',

		// attributes

		action_attribute: $ => seq(
			'action=',
			$.string,
		),

		anchor_attribute: $ => seq(
			'anchor=',
			$.string,
		),

		arg_attribute: $ => seq(
			'arg=',
			$.string,
		),

		collection_attribute: $ => seq(
			'collection=',
			$.string,
		),

		condition_attribute: $ => seq(
			'condition=',
			$.string,
		),

		contains_attribute: $ => seq(
			'contains=',
			$.string,
		),

		contentType_attribute: $ => seq(
			'contentType=',
			$.string,
		),

		convert_attribute: $ => seq(
			'convert=',
			$.string,
		),

		cryptkey_attribute: $ => seq(
			'cryptkey=',
			$.string,
		),

		decimalformat_attribute: $ => seq(
			'decimalformat=',
			$.string,
		),

		decoding_attribute: $ => seq(
			'decoding=',
			$.string,
		),

		decrypt_attribute: $ => seq(
			'decrypt=',
			$.string,
		),

		default_attribute: $ => seq(
			'default=',
			$.string,
		),

		encoding_attribute: $ => seq(
			'encoding=',
			$.string,
		),

		encrypt_attribute: $ => seq(
			'encrypt=',
			$.string,
		),

		eq_attribute: $ => seq(
			'eq=',
			$.string,
		),

		expression_attribute: $ => seq(
			'expression=',
			$.string,
		),

		gt_attribute: $ => seq(
			'gt=',
			$.string,
		),

		gte_attribute: $ => seq(
			'gte=',
			$.string,
		),

		ic_attribute: $ => seq(
			'ic=',
			$.string,
		),

		index_attribute: $ => seq(
			'index=',
			$.string,
		),

		insert_attribute: $ => seq(
			'insert=',
			$.string,
		),

		isNull_attribute: $ => seq(
			'isNull=',
			$.string,
		),

		item_attribute: $ => seq(
			'item=',
			$.string,
		),

		key_attribute: $ => seq(
			'key=',
			$.string,
		),

		language_attribute: $ => seq(
			'language=',
			$.string,
		),

		list_attribute: $ => seq(
			'list=',
			$.string,
		),

		locale_attribute: $ => seq(
			'locale=',
			$.string,
		),

		lt_attribute: $ => seq(
			'lt=',
			$.string,
		),

		lte_attribute: $ => seq(
			'lte=',
			$.string,
		),

		module_attribute: $ => seq(
			'module=',
			$.string,
		),

		name_attribute: $ => seq(
			'name=',
			$.string,
		),

		neq_attribute: $ => seq(
			'neq=',
			$.string,
		),

		object_attribute: $ => seq(
			'object=',
			$.string,
		),

		overwrite_attribute: $ => seq(
			'overwrite=',
			$.string,
		),

		pageEncoding_attribute: $ => seq(
			'pageEncoding=',
			$.string,
		),

		prefix_attribute: $ => seq(
			'prefix=',
			$.string,
		),

		publisher_attribute: $ => seq(
			'publisher=',
			$.string,
		),

		query_attribute: $ => seq(
			'query=',
			$.string,
		),

		return_attribute: $ => seq(
			'return=',
			$.string,
		),

		scope_attribute: $ => seq(
			'scope=',
			$.string,
		),

		separator_attribute: $ => seq(
			'separator=',
			$.string,
		),

		tagdir_attribute: $ => seq(
			'tagdir=',
			$.string,
		),

		template_attribute: $ => seq(
			'template=',
			$.string,
		),

		text_attribute: $ => seq(
			'text=',
			$.string,
		),

		uri_attribute: $ => seq(
			'uri=',
			$.string,
		),

		value_attribute: $ => seq(
			'value=',
			$.string,
		),

		// other

		string: $ => seq(
			'"',
			repeat(
				choice(
					/[^"$]+/,
					$.interpolated_string,
				),
			),
			'"',
		),

		interpolated_string: $ => seq(
			'${',
			repeat(
				choice(
					/[^"$\}]+/,
					$.interpolated_string,
				),
			),
			'}',
		),

		text: $ => /[^<>]+/,

		comment: $ => /<%--[^-]*-(?:(?:[^-]|-+[^-%]|-+%[^>])[^-]*-)*-+%>/,
	}
});
