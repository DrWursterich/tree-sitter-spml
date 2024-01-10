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

		document: $ => repeat(
			$._top_level_tag,
		),

		_top_level_tag: $ => choice(
			$.include_tag,
			$.if_tag,
			$.condition_tag,
			$.text,
		),

		// tags
		
		argument_tag: $ => seq(
			$.argument_tag_open,
			$.name_attribute,
			optional($.default_attribute),
			optional($.locale_attribute),
			choice(
				seq(
					$.value_attribute,
					$.self_closing_tag_end,
				),
				seq(
					$.text_attribute,
					$.self_closing_tag_end,
				),
				seq(
					$.expression_attribute,
					$.self_closing_tag_end,
				),
				seq(
					$.condition_attribute,
					$.self_closing_tag_end,
				),
				seq(
					$.object_attribute,
					$.self_closing_tag_end,
				),
				seq(
					'>',
					$.text,
					$.argument_tag_close,
				),
			),
		),
		argument_tag_open: $ => '<sp:argument',
		argument_tag_close: $ => '</sp:argument>',

		condition_tag: $ => seq(
			$.condition_tag_open,
			'>',
			$.if_tag,
			repeat(
				$.elseif_tag,
			),
			optional(
				$.else_tag,
			),
			$.condition_tag_close,
		),
		condition_tag_open: $ => '<sp:condition',
		condition_tag_close: $ => '</sp:condition>',

		else_tag: $ => seq(
			$.else_tag_open,
			'>',
			repeat(
				$._top_level_tag,
			),
			$.else_tag_close,
		),
		else_tag_open: $ => '<sp:else',
		else_tag_close: $ => '</sp:else>',

		elseif_tag: $ => seq(
			$.elseif_tag_open,
			choice(
				$.condition_attribute,
				seq(
					$.name_attribute,
					optional(
						choice(
							$.isNull_attribute,
							seq(
								choice(
									$.contains_attribute,
									$.eq_attribute,
									$.neq_attribute,
									$.gt_attribute,
									$.gte_attribute,
									$.lt_attribute,
									$.lte_attribute,
								),
								optional(
									$.ic_attribute
								),
							),
						),
					),
				),
			),
			optional($.locale_attribute),
			'>',
			repeat(
				$._top_level_tag,
			),
			$.elseif_tag_close,
		),
		elseif_tag_open: $ => '<sp:elseif',
		elseif_tag_close: $ => '</sp:elseif>',

		if_tag: $ => seq(
			$.if_tag_open,
			choice(
				$.condition_attribute,
				seq(
					$.name_attribute,
					optional(
						choice(
							$.isNull_attribute,
							seq(
								choice(
									$.contains_attribute,
									$.eq_attribute,
									$.neq_attribute,
									$.gt_attribute,
									$.gte_attribute,
									$.lt_attribute,
									$.lte_attribute,
								),
								optional(
									$.ic_attribute
								),
							),
						),
					),
				),
			),
			optional($.locale_attribute),
			'>',
			repeat(
				$._top_level_tag,
			),
			$.if_tag_close,
		),
		if_tag_open: $ => '<sp:if',
		if_tag_close: $ => '</sp:if>',

		include_tag: $ => seq(
			$.include_tag_open,
			optional($.module_attribute),
			choice(
				$.anchor_attribute,
				$.template_attribute,
				$.uri_attribute
			),
			optional($.return_attribute),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($.argument_tag),
					$.include_tag_close,
				),
			),
		),
		include_tag_open: $ => '<sp:include',
		include_tag_close: $ => '</sp:include>',

		self_closing_tag_end: $ => '/>',

		// attributes
		
		anchor_attribute: $ => seq(
			'anchor=',
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

		default_attribute: $ => seq(
			'default=',
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

		isNull_attribute: $ => seq(
			'isNull=',
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

		return_attribute: $ => seq(
			'return=',
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

		string: $ => /"[^"]*"/,

		text: $ => /[^<>]+/,
	}
});
