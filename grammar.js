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
			$.attribute_tag,
			$.barcode_tag,
			$.break_tag,
			$.calendarsheet_tag,
			$.checkbox_tag,
			$.code_tag,
			$.collection_tag,
			$.comment,
			$.condition_tag,
			$.diff_tag,
			$.error_tag,
			$.expire_tag,
			$.filter_tag,
			$.for_tag,
			$.form_tag,
			$.hidden_tag,
			$.if_tag,
			$.include_tag,
			$.io_tag,
			$.iterator_tag,
			$.json_tag,
			$.linktree_tag,
			$.livetree_tag,
			$.log_tag,
			$.login_tag,
			$.loop_tag,
			$.map_tag,
			$.option_tag,
			$.print_tag,
			$.radio_tag,
			$.range_tag,
			$.return_tag,
			$.sass_tag,
			$.scaleimage_tag,
			$.scope_tag,
			$.select_tag,
			$.set_tag,
			$.sort_tag,
			$.subinformation_tag,
			$.tagbody_tag,
			$.text,
			$.text_tag,
			$.textarea_tag,
			$.textimage_tag,
			$.upload_tag,
			$.url_tag,
			$.warning_tag,
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
					repeat($._top_level_tag),
					$.argument_tag_close,
				),
			),
		),
		argument_tag_open: $ => '<sp:argument',
		argument_tag_close: $ => '</sp:argument>',

		attribute_tag: $ => seq(
			$.attribute_tag_open,
			repeat(
				choice(
					$.condition_attribute,
					$.dynamics_attribute,
					$.expression_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.object_attribute,
					$.text_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		attribute_tag_open: $ => '<sp:attribute',

		barcode_tag: $ => seq(
			$.barcode_tag_open,
			repeat(
				choice(
					$.height_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.scope_attribute,
					$.text_attribute,
					$.type_attribute,
					$.width_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		barcode_tag_open: $ => '<sp:barcode',

		break_tag: $ => seq(
			$.break_tag_open,
			$.self_closing_tag_end,
		),
		break_tag_open: $ => '<sp:break',

		calendarsheet_tag: $ => seq(
			$.calendarsheet_tag_open,
			repeat(
				choice(
					$.action_attribute,
					$.date_attribute,
					$.from_attribute,
					$.mode_attribute,
					$.name_attribute,
					$.object_attribute,
					$.scope_attribute,
					$.to_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.calendarsheet_tag_close,
				),
			),
		),
		calendarsheet_tag_open: $ => '<sp:calendarsheet',
		calendarsheet_tag_close: $ => '</sp:calendarsheet>',

		checkbox_tag: $ => seq(
			$.checkbox_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.checked_attribute,
					$.disabled_attribute,
					$.dynamics_attribute,
					$.format_attribute,
					$.hidden_attribute,
					$.id_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.personalization_attribute,
					$.readonly_attribute,
					$.type_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.checkbox_tag_close,
				),
			),
		),
		checkbox_tag_open: $ => '<sp:checkbox',
		checkbox_tag_close: $ => '</sp:checkbox>',

		code_tag: $ => seq(
			$.code_tag_open,
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.code_tag_close,
				),
			),
		),
		code_tag_open: $ => '<sp:code',
		code_tag_close: $ => '</sp:code>',

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
					repeat($._top_level_tag),
					$.collection_tag_close,
				),
			),
		),
		collection_tag_open: $ => '<sp:collection',
		collection_tag_close: $ => '</sp:collection>',

		condition_tag: $ => seq(
			$.condition_tag_open,
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat(
						choice(
							$._top_level_tag,
							$.elseif_tag,
							$.else_tag,
						),
					),
					$.condition_tag_close,
				),
			),
		),
		condition_tag_open: $ => '<sp:condition',
		condition_tag_close: $ => '</sp:condition>',

		diff_tag: $ => seq(
			$.diff_tag_open,
			repeat(
				choice(
					$.from_attribute,
					$.information_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.original_attribute,
					$.revised_attribute,
					$.to_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.diff_tag_close,
				),
			),
		),
		diff_tag_open: $ => '<sp:diff',
		diff_tag_close: $ => '</sp:diff>',

		else_tag: $ => seq(
			$.else_tag_open,
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.else_tag_close,
				),
			),
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
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.elseif_tag_close,
				),
			),
		),
		elseif_tag_open: $ => '<sp:elseif',
		elseif_tag_close: $ => '</sp:elseif>',

		error_tag: $ => seq(
			$.error_tag_open,
			repeat($.code_attribute),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.error_tag_close,
				),
			),
		),
		error_tag_open: $ => '<sp:error',
		error_tag_close: $ => '</sp:error>',

		expire_tag: $ => seq(
			$.expire_tag_open,
			repeat($.date_attribute),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.expire_tag_close,
				),
			),
		),
		expire_tag_open: $ => '<sp:expire',
		expire_tag_close: $ => '</sp:expire>',

		filter_tag: $ => seq(
			$.filter_tag_open,
			repeat(
				choice(
					$.collection_attribute,
					$.filter_attribute,
					$.format_attribute,
					$.from_attribute,
					$.ic_attribute,
					$.invert_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.mode_attribute,
					$.name_attribute,
					$.scope_attribute,
					$.to_attribute,
					$.type_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.filter_tag_close,
				),
			),
		),
		filter_tag_open: $ => '<sp:filter',
		filter_tag_close: $ => '</sp:filter>',

		for_tag: $ => seq(
			$.for_tag_open,
			repeat(
				choice(
					$.condition_attribute,
					$.from_attribute,
					$.index_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.step_attribute,
					$.to_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.for_tag_close,
				),
			),
		),
		for_tag_open: $ => '<sp:for',
		for_tag_close: $ => '</sp:for>',

		form_tag: $ => seq(
			$.form_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.command_attribute,
					$.context_attribute,
					$.handler_attribute,
					$.host_attribute,
					$.id_attribute,
					$.module_attribute,
					$.nameencoding_attribute,
					$.template_attribute,
					$.uri_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.form_tag_close,
				),
			),
		),
		form_tag_open: $ => '<sp:form',
		form_tag_close: $ => '</sp:form>',

		hidden_tag: $ => seq(
			$.hidden_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.dynamics_attribute,
					$.fixvalue_attribute,
					$.format_attribute,
					$.id_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.personalization_attribute,
					$.type_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.hidden_tag_close,
				),
			),
		),
		hidden_tag_open: $ => '<sp:hidden',
		hidden_tag_close: $ => '</sp:hidden>',

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
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.if_tag_close,
				),
			),
		),
		if_tag_open: $ => '<sp:if',
		if_tag_close: $ => '</sp:if>',

		include_tag: $ => seq(
			$.include_tag_open,
			repeat(
				choice(
					$.anchor_attribute,
					$.arguments_attribute,
					$.context_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.mode_attribute,
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
							$._top_level_tag,
							$.argument_tag,
						),
					),
					$.include_tag_close,
				),
			),
		),
		include_tag_open: $ => '<sp:include',
		include_tag_close: $ => '</sp:include>',

		io_tag: $ => seq(
			$.io_tag_open,
			repeat(
				choice(
					$.contenttype_attribute,
					$.type_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.io_tag_close,
				),
			),
		),
		io_tag_open: $ => '<sp:io',
		io_tag_close: $ => '</sp:io>',

		iterator_tag: $ => seq(
			$.iterator_tag_open,
			repeat(
				choice(
					$.collection_attribute,
					$.item_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.max_attribute,
					$.min_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.iterator_tag_close,
				),
			),
		),
		iterator_tag_open: $ => '<sp:iterator',
		iterator_tag_close: $ => '</sp:iterator>',

		json_tag: $ => seq(
			$.json_tag_open,
			repeat(
				choice(
					$.indent_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.object_attribute,
					$.overwrite_attribute,
					$.scope_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.json_tag_close,
				),
			),
		),
		json_tag_open: $ => '<sp:json',
		json_tag_close: $ => '</sp:json>',

		linktree_tag: $ => seq(
			$.linktree_tag_open,
			repeat(
				choice(
					$.arg_attribute,
					$.attributes_attribute,
					$.childrenlink_attribute,
					$.locale_attribute,
					$.localelink_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.parentlink_attribute,
					$.rootelement_attribute,
					$.sortkeys_attribute,
					$.sortsequences_attribute,
					$.sorttypes_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.linktree_tag_close,
				),
			),
		),
		linktree_tag_open: $ => '<sp:linktree',
		linktree_tag_close: $ => '</sp:linktree>',

		livetree_tag: $ => seq(
			$.livetree_tag_open,
			repeat(
				choice(
					$.action_attribute,
					$.childrenlink_attribute,
					$.leaflink_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.node_attribute,
					$.parentlink_attribute,
					$.publisher_attribute,
					$.rootelement_attribute,
					$.sortkeys_attribute,
					$.sortsequences_attribute,
					$.sorttypes_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		livetree_tag_open: $ => '<sp:livetree',

		log_tag: $ => seq(
			$.log_tag_open,
			repeat($.level_attribute),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.log_tag_close,
				),
			),
		),
		log_tag_open: $ => '<sp:log',
		log_tag_close: $ => '</sp:log>',

		login_tag: $ => seq(
			$.login_tag_open,
			repeat(
				choice(
					$.client_attribute,
					$.gui_attribute,
					$.login_attribute,
					$.namespace_attribute,
					$.password_attribute,
					$.scope_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		login_tag_open: $ => '<sp:login',

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
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.loop_tag_close,
				),
			),
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
					repeat($._top_level_tag),
					$.map_tag_close,
				),
			),
		),
		map_tag_open: $ => '<sp:map',
		map_tag_close: $ => '</sp:map>',

		option_tag: $ => seq(
			$.option_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.disabled_attribute,
					$.id_attribute,
					$.selected_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.option_tag_close,
				),
			),
		),
		option_tag_open: $ => '<sp:option',
		option_tag_close: $ => '</sp:option>',

		set_tag: $ => seq(
			$.set_tag_open,
			repeat(
				choice(
					$.condition_attribute,
					$.contentType_attribute,
					$.dateformat_attribute,
					$.decimalformat_attribute,
					$.default_attribute,
					$.expression_attribute,
					$.insert_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.object_attribute,
					$.overwrite_attribute,
					$.scope_attribute,
					$.tagScope_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
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
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.print_tag_close,
				),
			),
		),
		print_tag_open: $ => '<sp:print',
		print_tag_close: $ => '</sp:print>',

		radio_tag: $ => seq(
			$.radio_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.checked_attribute,
					$.disabled_attribute,
					$.dynamics_attribute,
					$.format_attribute,
					$.hidden_attribute,
					$.id_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.personalization_attribute,
					$.readonly_attribute,
					$.type_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.radio_tag_close,
				),
			),
		),
		radio_tag_open: $ => '<sp:radio',
		radio_tag_close: $ => '</sp:radio>',

		range_tag: $ => seq(
			$.range_tag_open,
			repeat(
				choice(
					$.collection_attribute,
					$.name_attribute,
					$.range_attribute,
					$.scope_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.range_tag_close,
				),
			),
		),
		range_tag_open: $ => '<sp:range',
		range_tag_close: $ => '</sp:range>',

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
					repeat($._top_level_tag),
					$.return_tag_close,
				),
			),
		),
		return_tag_open: $ => '<sp:return',
		return_tag_close: $ => '</sp:return>',

		select_tag: $ => seq(
			$.select_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.disabled_attribute,
					$.dynamics_attribute,
					$.format_attribute,
					$.hidden_attribute,
					$.id_attribute,
					$.locale_attribute,
					$.multiple_attribute,
					$.name_attribute,
					$.personalization_attribute,
					$.type_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.select_tag_close,
				),
			),
		),
		select_tag_open: $ => '<sp:select',
		select_tag_close: $ => '</sp:select>',

		scaleimage_tag: $ => seq(
			$.scaleimage_tag_open,
			repeat(
				choice(
					$.background_attribute,
					$.format_attribute,
					$.height_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.object_attribute,
					$.options_attribute,
					$.padding_attribute,
					$.processor_attribute,
					$.quality_attribute,
					$.scalesteps_attribute,
					$.scope_attribute,
					$.width_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		scaleimage_tag_open: $ => '<sp:scaleimage',

		scope_tag: $ => seq(
			$.scope_tag_open,
			repeat($.scope_attribute),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.scope_tag_close,
				),
			),
		),
		scope_tag_open: $ => '<sp:scope',
		scope_tag_close: $ => '</sp:scope>',

		sort_tag: $ => seq(
			$.sort_tag_open,
			repeat(
				choice(
					$.collection_attribute,
					$.keys_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.scope_attribute,
					$.sequences_attribute,
					$.types_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.sort_tag_close,
				),
			),
		),
		sort_tag_open: $ => '<sp:sort',
		sort_tag_close: $ => '</sp:sort>',

		sass_tag: $ => seq(
			$.sass_tag_open,
			repeat(
				choice(
					$.name_attribute,
					$.options_attribute,
					$.source_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.sass_tag_close,
				),
			),
		),
		sass_tag_open: $ => '<sp:sass',
		sass_tag_close: $ => '</sp:sass>',

		subinformation_tag: $ => seq(
			$.subinformation_tag_open,
			repeat(
				choice(
					$.locale_attribute,
					$.name_attribute,
					$.type_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.subinformation_tag_close,
				),
			),
		),
		subinformation_tag_open: $ => '<sp:subinformation',
		subinformation_tag_close: $ => '</sp:subinformation>',

		tagbody_tag: $ => seq(
			$.tagbody_tag_open,
			$.self_closing_tag_end,
		),
		tagbody_tag_open: $ => '<sp:tagbody',

		text_tag: $ => seq(
			$.text_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.disabled_attribute,
					$.dynamics_attribute,
					$.fixvalue_attribute,
					$.format_attribute,
					$.hidden_attribute,
					$.id_attribute,
					$.inputType_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.personalization_attribute,
					$.readonly_attribute,
					$.type_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.text_tag_close,
				),
			),
		),
		text_tag_open: $ => '<sp:text',
		text_tag_close: $ => '</sp:text>',

		textarea_tag: $ => seq(
			$.textarea_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.disabled_attribute,
					$.dynamics_attribute,
					$.fixvalue_attribute,
					$.format_attribute,
					$.hidden_attribute,
					$.id_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.personalization_attribute,
					$.readonly_attribute,
					$.type_attribute,
					$.value_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.textarea_tag_close,
				),
			),
		),
		textarea_tag_open: $ => '<sp:textarea',
		textarea_tag_close: $ => '</sp:textarea>',

		textimage_tag: $ => seq(
			$.textimage_tag_open,
			repeat(
				choice(
					$.background_attribute,
					$.fontcolor_attribute,
					$.fontname_attribute,
					$.fontsize_attribute,
					$.fontstyle_attribute,
					$.gravity_attribute,
					$.height_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.name_attribute,
					$.offset_attribute,
					$.processor_attribute,
					$.scope_attribute,
					$.text_attribute,
					$.transform_attribute,
					$.width_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		textimage_tag_open: $ => '<sp:textimage',

		upload_tag: $ => seq(
			$.upload_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.dynamics_attribute,
					$.fixvalue_attribute,
					$.hidden_attribute,
					$.id_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.personalization_attribute,
					$.type_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.upload_tag_close,
				),
			),
		),
		upload_tag_open: $ => '<sp:upload',
		upload_tag_close: $ => '</sp:upload>',

		url_tag: $ => seq(
			$.url_tag_open,
			repeat(
				choice(
					$.absolute_attribute,
					$.command_attribute,
					$.context_attribute,
					$.gui_attribute,
					$.handler_attribute,
					$.information_attribute,
					$.locale_attribute,
					$.lookup_attribute,
					$.module_attribute,
					$.path_attribute,
					$.publisher_attribute,
					$.template_attribute,
					$.uri_attribute,
					$.window_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.url_tag_close,
				),
			),
		),
		url_tag_open: $ => '<sp:url',
		url_tag_close: $ => '</sp:url>',

		warning_tag: $ => seq(
			$.warning_tag_open,
			repeat($.code_attribute),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.warning_tag_close,
				),
			),
		),
		warning_tag_open: $ => '<sp:warning',
		warning_tag_close: $ => '</sp:warning>',

		self_closing_tag_end: $ => '/>',

		// attributes

		dynamic_attribute: $ => seq(
			/\w+=/,
			$.string,
		),

		absolute_attribute: $ => seq(
			'absolute=',
			$.string,
		),

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

		arguments_attribute: $ => seq(
			'arguments=',
			$.string,
		),

		attributes_attribute: $ => seq(
			'attributes=',
			$.string,
		),

		background_attribute: $ => seq(
			'background=',
			$.string,
		),

		checked_attribute: $ => seq(
			'checked=',
			$.string,
		),

		childrenlink_attribute: $ => seq(
			'childrenlink=',
			$.string,
		),

		client_attribute: $ => seq(
			'client=',
			$.string,
		),

		code_attribute: $ => seq(
			'code=',
			$.string,
		),

		collection_attribute: $ => seq(
			'collection=',
			$.string,
		),

		command_attribute: $ => seq(
			'command=',
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

		contenttype_attribute: $ => seq(
			'contenttype=',
			$.string,
		),

		context_attribute: $ => seq(
			'context=',
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

		date_attribute: $ => seq(
			'date=',
			$.string,
		),

		dateformat_attribute: $ => seq(
			'dateformat=',
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

		disabled_attribute: $ => seq(
			'disabled=',
			$.string,
		),

		dynamics_attribute: $ => seq(
			'dynamics=',
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

		filter_attribute: $ => seq(
			'filter=',
			$.string,
		),

		fixvalue_attribute: $ => seq(
			'fixvalue=',
			$.string,
		),

		fontcolor_attribute: $ => seq(
			'fontcolor=',
			$.string,
		),

		fontname_attribute: $ => seq(
			'fontname=',
			$.string,
		),

		fontsize_attribute: $ => seq(
			'fontsize=',
			$.string,
		),

		fontstyle_attribute: $ => seq(
			'fontstyle=',
			$.string,
		),

		format_attribute: $ => seq(
			'format=',
			$.string,
		),

		from_attribute: $ => seq(
			'from=',
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

		gravity_attribute: $ => seq(
			'gravity=',
			$.string,
		),

		gui_attribute: $ => seq(
			'gui=',
			$.string,
		),

		handler_attribute: $ => seq(
			'handler=',
			$.string,
		),

		height_attribute: $ => seq(
			'height=',
			$.string,
		),

		hidden_attribute: $ => seq(
			'hidden=',
			$.string,
		),

		host_attribute: $ => seq(
			'host=',
			$.string,
		),

		ic_attribute: $ => seq(
			'ic=',
			$.string,
		),

		id_attribute: $ => seq(
			'id=',
			$.string,
		),

		indent_attribute: $ => seq(
			'indent=',
			$.string,
		),

		index_attribute: $ => seq(
			'index=',
			$.string,
		),

		information_attribute: $ => seq(
			'information=',
			$.string,
		),

		insert_attribute: $ => seq(
			'insert=',
			$.string,
		),

		inputType_attribute: $ => seq(
			'inputType=',
			$.string,
		),

		invert_attribute: $ => seq(
			'invert=',
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

		keys_attribute: $ => seq(
			'keys=',
			$.string,
		),

		language_attribute: $ => seq(
			'language=',
			$.string,
		),

		leaflink_attribute: $ => seq(
			'leaflink=',
			$.string,
		),

		level_attribute: $ => seq(
			'level=',
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

		localelink_attribute: $ => seq(
			'localelink=',
			$.string,
		),

		login_attribute: $ => seq(
			'login=',
			$.string,
		),

		lookup_attribute: $ => seq(
			'lookup=',
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

		max_attribute: $ => seq(
			'max=',
			$.string,
		),

		min_attribute: $ => seq(
			'min=',
			$.string,
		),

		mode_attribute: $ => seq(
			'mode=',
			$.string,
		),

		module_attribute: $ => seq(
			'module=',
			$.string,
		),

		multiple_attribute: $ => seq(
			'multiple=',
			$.string,
		),

		name_attribute: $ => seq(
			'name=',
			$.string,
		),

		nameencoding_attribute: $ => seq(
			'nameencoding=',
			$.string,
		),

		namespace_attribute: $ => seq(
			'namespace=',
			$.string,
		),

		neq_attribute: $ => seq(
			'neq=',
			$.string,
		),

		node_attribute: $ => seq(
			'node=',
			$.string,
		),

		object_attribute: $ => seq(
			'object=',
			$.string,
		),

		offset_attribute: $ => seq(
			'offset=',
			$.string,
		),

		options_attribute: $ => seq(
			'options=',
			$.string,
		),

		original_attribute: $ => seq(
			'original=',
			$.string,
		),

		overwrite_attribute: $ => seq(
			'overwrite=',
			$.string,
		),

		padding_attribute: $ => seq(
			'padding=',
			$.string,
		),

		pageEncoding_attribute: $ => seq(
			'pageEncoding=',
			$.string,
		),

		parentlink_attribute: $ => seq(
			'parentlink=',
			$.string,
		),

		password_attribute: $ => seq(
			'password=',
			$.string,
		),

		path_attribute: $ => seq(
			'path=',
			$.string,
		),

		personalization_attribute: $ => seq(
			'personalization=',
			$.string,
		),

		prefix_attribute: $ => seq(
			'prefix=',
			$.string,
		),

		processor_attribute: $ => seq(
			'processor=',
			$.string,
		),

		publisher_attribute: $ => seq(
			'publisher=',
			$.string,
		),

		quality_attribute: $ => seq(
			'quality=',
			$.string,
		),

		query_attribute: $ => seq(
			'query=',
			$.string,
		),

		range_attribute: $ => seq(
			'range=',
			$.string,
		),

		readonly_attribute: $ => seq(
			'readonly=',
			$.string,
		),

		return_attribute: $ => seq(
			'return=',
			$.string,
		),

		revised_attribute: $ => seq(
			'revised=',
			$.string,
		),

		rootelement_attribute: $ => seq(
			/root[eE]lement=/,
			$.string,
		),

		scalesteps_attribute: $ => seq(
			'scalesteps=',
			$.string,
		),

		scope_attribute: $ => seq(
			'scope=',
			$.string,
		),

		selected_attribute: $ => seq(
			'selected=',
			$.string,
		),

		separator_attribute: $ => seq(
			'separator=',
			$.string,
		),

		sequences_attribute: $ => seq(
			'sequences=',
			$.string,
		),

		sortkeys_attribute: $ => seq(
			'sortkeys=',
			$.string,
		),

		sortsequences_attribute: $ => seq(
			'sortsequences=',
			$.string,
		),

		sorttypes_attribute: $ => seq(
			'sorttypes=',
			$.string,
		),

		source_attribute: $ => seq(
			'source=',
			$.string,
		),

		step_attribute: $ => seq(
			'step=',
			$.string,
		),

		tagdir_attribute: $ => seq(
			'tagdir=',
			$.string,
		),

		tagScope_attribute: $ => seq(
			'tagScope=',
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

		to_attribute: $ => seq(
			'to=',
			$.string,
		),

		transform_attribute: $ => seq(
			'transform=',
			$.string,
		),

		type_attribute: $ => seq(
			'type=',
			$.string,
		),

		types_attribute: $ => seq(
			'types=',
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

		width_attribute: $ => seq(
			'width=',
			$.string,
		),

		window_attribute: $ => seq(
			'window=',
			$.string,
		),

		// other

		string: $ => seq(
			'"',
			repeat(
				choice(
					/[^"$]+/,
					prec(1, $.interpolated_string),
					prec(2, '$'),
				),
			),
			'"',
		),

		interpolated_string: $ => seq(
			'${',
			repeat(
				choice(
					/[^"$!\}]+/,
					prec(1, $.interpolated_string),
					prec(2, $.interpolated_anchor),
					prec(3, '$'),
					prec(4, '!'),
				),
			),
			'}',
		),

		interpolated_anchor: $ => seq(
			'!{',
			repeat(
				choice(
					/[^"$\}]+/,
					prec(1, $.interpolated_string),
					prec(2, '$'),
				),
			),
			'}',
		),

		text: $ => /[^<>]+/,

		comment: $ => /<%--[^-]*-(?:(?:[^-]|-+[^-%]|-+%[^>])[^-]*-)*-+%>/,
	}
});
