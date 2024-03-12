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

	extras: $ => [
		$.comment,
		/\s+/,
	],

	word: $ => $._word,

	externals: $ => [
		$.html_option_tag_close,
		$.html_option_tag_open,
		$.html_tag_close,
		$.html_tag_open,
		$.html_void_tag_open,
	],

	rules: {

		document: $ => seq(
			repeat(
				choice(
					$.comment,
					$.import_header,
				),
			),
			choice(
				$.page_header,
				$.taglib_header,
			),
			repeat(
				seq(
					optional($.comment),
					choice(
						$.import_header,
						$.page_header,
						$.taglib_header,
					),
				),
			),
			repeat($._top_level_tag),
		),

		_word: $ => /[a-zA-Z_0-9]*[a-zA-Z_][a-zA-Z_0-9]*/,

		_top_level_tag: $ => choice(
			$._top_level_sp_tag,
			$.comment,
			$.html_doctype,
			$.html_option_tag,
			$.html_tag,
			$.html_void_tag,
			$.java_tag,
			$.script_tag,
			$.style_tag,
			$.text,
			$.xml_comment,
			$.xml_entity,
		),

		_top_level_sp_tag: $ => choice(
			$.attribute_tag,
			$.barcode_tag,
			$.break_tag,
			$.calendarsheet_tag,
			$.checkbox_tag,
			$.code_tag,
			$.collection_tag,
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
			$.linkedInformation_tag,
			$.linktree_tag,
			$.livetree_tag,
			$.log_tag,
			$.login_tag,
			$.loop_tag,
			$.map_tag,
			$.option_tag,
			$.password_tag,
			$.print_tag,
			$.querytree_tag,
			$.radio_tag,
			$.range_tag,
			$.return_tag,
			$.sass_tag,
			$.scaleimage_tag,
			$.scope_tag,
			$.search_tag,
			$.select_tag,
			$.set_tag,
			$.sort_tag,
			$.subinformation_tag,
			$.tagbody_tag,
			$.text_tag,
			$.textarea_tag,
			$.textimage_tag,
			$.throw_tag,
			$.toggle_tag,
			$.upload_tag,
			$.url_tag,
			$.warning_tag,
			$.worklist_tag,
			$.zip_tag,
			$.spt_counter_tag,
			$.spt_date_tag,
			$.spt_diff_tag,
			$.spt_email2img_tag,
			$.spt_encryptemail_tag,
			$.spt_escapeemail_tag,
			$.spt_formsolutions_tag,
			$.spt_id2url_tag,
			$.spt_ilink_tag,
			$.spt_imageeditor_tag,
			$.spt_imp_tag,
			$.spt_iterator_tag,
			$.spt_link_tag,
			$.spt_number_tag,
			$.spt_personalization_tag,
			$.spt_prehtml_tag,
			$.spt_smarteditor_tag,
			$.spt_spml_tag,
			$.spt_text_tag,
			$.spt_textarea_tag,
			$.spt_timestamp_tag,
			$.spt_tinymce_tag,
			$.spt_updown_tag,
			$.spt_upload_tag,
			$.spt_worklist_tag,
		),

		import_header: $ => seq(
			$.header_open,
			'page',
			$.import_attribute,
			$.header_close,
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

		// sp tags

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

		linkedInformation_tag: $ => seq(
			$.linkedInformation_tag_open,
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
					$.linkedInformation_tag_close,
				),
			),
		),
		linkedInformation_tag_open: $ => '<sp:linkedInformation',
		linkedInformation_tag_close: $ => '</sp:linkedInformation>',

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

		password_tag: $ => seq(
			$.password_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.disabled_attribute,
					$.dynamics_attribute,
					$.fixvalue_attribute,
					$.format_attribute,
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
					$.password_tag_close,
				),
			),
		),
		password_tag_open: $ => '<sp:password',
		password_tag_close: $ => '</sp:password>',

		print_tag: $ => seq(
			$.print_tag_open,
			repeat(
				choice(
					$.arg_attribute,
					$.condition_attribute,
					$.convert_attribute,
					$.cryptkey_attribute,
					$.dateformat_attribute,
					$.decimalformat_attribute,
					$.decoding_attribute,
					$.decrypt_attribute,
					$.default_attribute,
					$.encoding_attribute,
					$.encrypt_attribute,
					$.expression_attribute,
					$.locale_attribute,
					$.lookup_attribute,
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

		querytree_tag: $ => seq(
			$.querytree_tag_open,
			repeat(
				choice(
					$.attributes_attribute,
					$.item_attribute,
					$.name_attribute,
					$.query_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.querytree_tag_close,
				),
			),
		),
		querytree_tag_open: $ => '<sp:querytree',
		querytree_tag_close: $ => '</sp:querytree>',

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

		search_tag: $ => seq(
			$.search_tag_open,
			repeat(
				choice(
					$.name_attribute,
					$.time_attribute,
					$.type_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.search_tag_close,
				),
			),
		),
		search_tag_open: $ => '<sp:search',
		search_tag_close: $ => '</sp:search>',

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

		throw_tag: $ => seq(
			$.throw_tag_open,
			repeat(
				choice(
					$.locale_attribute,
					$.lookup_attribute,
					$.message_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		throw_tag_open: $ => '<sp:throw',

		toggle_tag: $ => seq(
			$.toggle_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.disabled_attribute,
					$.dynamics_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.offvalue_attribute,
					$.onvalue_attribute,
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
					$.toggle_tag_close,
				),
			),
		),
		toggle_tag_open: $ => '<sp:toggle',
		toggle_tag_close: $ => '</sp:toggle>',

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

		worklist_tag: $ => seq(
			$.worklist_tag_open,
			repeat(
				choice(
					$.element_attribute,
					$.name_attribute,
					$.role_attribute,
					$.type_attribute,
					$.user_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.worklist_tag_close,
				),
			),
		),
		worklist_tag_open: $ => '<sp:worklist',
		worklist_tag_close: $ => '</sp:worklist>',

		zip_tag: $ => seq(
			$.zip_tag_open,
			repeat(
				choice(
					$.directory_attribute,
					$.files_attribute,
					$.name_attribute,
					$.return_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.zip_tag_close,
				),
			),
		),
		zip_tag_open: $ => '<sp:zip',
		zip_tag_close: $ => '</sp:zip>',

		self_closing_tag_end: $ => '/>',

		// spt tags

		spt_counter_tag: $ => seq(
			$.spt_counter_tag_open,
			repeat(
				choice(
					$.language_attribute,
					$.mode_attribute,
					$.name_attribute,
					$.varname_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_counter_tag_open: $ => '<spt:counter',

		spt_date_tag: $ => seq(
			$.spt_date_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.disabled_attribute,
					$.fixvalue_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.nowButton_attribute,
					$.placeholder_attribute,
					$.readonly_attribute,
					$.size_attribute,
					$.type_attribute,
					$.value_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_date_tag_open: $ => '<spt:date',

		spt_diff_tag: $ => seq(
			$.spt_diff_tag_open,
			repeat(
				choice(
					$.from_attribute,
					$.style_attribute,
					$.to_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_diff_tag_open: $ => '<spt:diff',

		spt_email2img_tag: $ => seq(
			$.spt_email2img_tag_open,
			repeat(
				choice(
					$.alt_attribute,
					$.bgcolor_attribute,
					$.bgcolor2_attribute,
					$.color_attribute,
					$.color2_attribute,
					$.font_attribute,
					$.font2_attribute,
					$.fontsize_attribute,
					$.fontsize2_attribute,
					$.fontweight_attribute,
					$.fontweight2_attribute,
					$.form_attribute,
					$.linkcolor_attribute,
					$.name_attribute,
					$.object_attribute,
					$.onclick_attribute,
					$.popupheight_attribute,
					$.popupwidth_attribute,
					$.title_attribute,
					$.urlparam_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_email2img_tag_open: $ => '<spt:email2img',

		spt_encryptemail_tag: $ => seq(
			$.spt_encryptemail_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.form_attribute,
					$.name_attribute,
					$.object_attribute,
					$.popupheight_attribute,
					$.popupwidth_attribute,
					$.urlparam_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_encryptemail_tag_open: $ => '<spt:encryptemail',

		spt_escapeemail_tag: $ => seq(
			$.spt_escapeemail_tag_open,
			repeat(
				choice(
					$.alt_attribute,
					$.bgcolor_attribute,
					$.color_attribute,
					$.font_attribute,
					$.fontsize_attribute,
					$.fontweight_attribute,
					$.form_attribute,
					$.name_attribute,
					$.object_attribute,
					$.onclick_attribute,
					$.popupheight_attribute,
					$.popupwidth_attribute,
					$.title_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_escapeemail_tag_open: $ => '<spt:escapeemail',

		spt_formsolutions_tag: $ => seq(
			$.spt_formsolutions_tag_open,
			repeat(
				choice(
					$.name_attribute,
					$.locale_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_formsolutions_tag_open: $ => '<spt:formsolutions',

		spt_id2url_tag: $ => seq(
			$.spt_id2url_tag_open,
			repeat(
				choice(
					$.classname_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.object_attribute,
					$.querystring_attribute,
					$.url_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_id2url_tag_open: $ => '<spt:id2url',

		spt_ilink_tag: $ => seq(
			$.spt_ilink_tag_open,
			repeat(
				choice(
					$.action_attribute,
					$.information_attribute,
					$.step_attribute,
					$.value_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_ilink_tag_open: $ => '<spt:ilink',

		spt_imageeditor_tag: $ => seq(
			$.spt_imageeditor_tag_open,
			repeat(
				choice(
					$.delete_attribute,
					$.focalpoint_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.object_attribute,
					$.width_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_imageeditor_tag_open: $ => '<spt:imageeditor',

		spt_imp_tag: $ => seq(
			$.spt_imp_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.alt_attribute,
					$.background_attribute,
					$.color_attribute,
					$.excerpt_attribute,
					$.font_attribute,
					$.font_size_attribute,
					$.font_weight_attribute,
					$.fontcolor_attribute,
					$.fontname_attribute,
					$.fontsize_attribute,
					$.fontweight_attribute,
					$.format_attribute,
					$.gravity_attribute,
					$.height_attribute,
					$.image_attribute,
					$.manipulate_attribute,
					$.offset_attribute,
					$.padding_attribute,
					$.paddingcolor_attribute,
					$.scalesteps_attribute,
					$.text_attribute,
					$.text_transform_attribute,
					$.transform_attribute,
					$.urlonly_attribute,
					$.width_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_imp_tag_open: $ => '<spt:imp',

		spt_iterator_tag: $ => seq(
			$.spt_iterator_tag_open,
			repeat(
				choice(
					$.disabled_attribute,
					$.invert_attribute,
					$.item_attribute,
					$.itemtext_attribute,
					$.layout_attribute,
					$.max_attribute,
					$.min_attribute,
					$.name_attribute,
					$.readonly_attribute,
				),
			),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat($._top_level_tag),
					$.spt_iterator_tag_close,
				),
			),
		),
		spt_iterator_tag_open: $ => '<spt:iterator',
		spt_iterator_tag_close: $ => '</spt:iterator>',

		spt_link_tag: $ => seq(
			$.spt_link_tag_open,
			repeat(
				choice(
					$.filter_attribute,
					$.filterattribute_attribute,
					$.filteric_attribute,
					$.filterinvert_attribute,
					$.filtermode_attribute,
					$.filterquery_attribute,
					$.fixvalue_attribute,
					$.height_attribute,
					$.hidden_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.pools_attribute,
					$.previewimage_attribute,
					$.showtree_attribute,
					$.size_attribute,
					$.type_attribute,
					$.value_attribute,
					$.width_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_link_tag_open: $ => '<spt:link',

		spt_number_tag: $ => seq(
			$.spt_number_tag_open,
			repeat(
				choice(
					$.align_attribute,
					$.disabled_attribute,
					$.fixvalue_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.readonly_attribute,
					$.size_attribute,
					$.value_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_number_tag_open: $ => '<spt:number',

		spt_personalization_tag: $ => seq(
			$.spt_personalization_tag_open,
			repeat(
				choice(
					$.information_attribute,
					$.mode_attribute,
					$.name_attribute,
					$.publisher_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_personalization_tag_open: $ => '<spt:personalization',

		spt_prehtml_tag: $ => seq(
			$.spt_prehtml_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.name_attribute,
					$.object_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_prehtml_tag_open: $ => '<spt:prehtml',

		spt_smarteditor_tag: $ => seq(
			$.spt_smarteditor_tag_open,
			repeat(
				choice(
					$.cols_attribute,
					$.hide_attribute,
					$.name_attribute,
					$.options_attribute,
					$.rows_attribute,
					$.textlabel_attribute,
					$.value_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_smarteditor_tag_open: $ => '<spt:smarteditor',

		spt_spml_tag: $ => seq(
			$.spt_spml_tag_open,
			repeat($.api_attribute),
			$.self_closing_tag_end,
		),
		spt_spml_tag_open: $ => '<spt:spml',

		spt_text_tag: $ => seq(
			$.spt_text_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.disabled_attribute,
					$.editablePlaceholder_attribute,
					$.fixvalue_attribute,
					$.format_attribute,
					$.hyphenEditor_attribute,
					$.inputType_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.readonly_attribute,
					$.size_attribute,
					$.type_attribute,
					$.value_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_text_tag_open: $ => '<spt:text',

		spt_textarea_tag: $ => seq(
			$.spt_textarea_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.disabled_attribute,
					$.editablePlaceholder_attribute,
					$.fixvalue_attribute,
					$.hyphenEditor_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.readonly_attribute,
					$.type_attribute,
					$.value_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_textarea_tag_open: $ => '<spt:textarea',

		spt_timestamp_tag: $ => seq(
			$.spt_timestamp_tag_open,
			repeat($.connect_attribute),
			$.self_closing_tag_end,
		),
		spt_timestamp_tag_open: $ => '<spt:timestamp',

		spt_tinymce_tag: $ => seq(
			$.spt_tinymce_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.cols_attribute,
					$.config_attribute,
					$.configextension_attribute,
					$.configvalues_attribute,
					$.disabled_attribute,
					$.fixvalue_attribute,
					$.name_attribute,
					$.pools_attribute,
					$.readonly_attribute,
					$.rows_attribute,
					$.theme_attribute,
					$.toggle_attribute,
					$.type_attribute,
					$.value_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_tinymce_tag_open: $ => '<spt:tinymce',

		spt_updown_tag: $ => seq(
			$.spt_updown_tag_open,
			repeat(
				choice(
					$.from_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.to_attribute,
					$.value_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_updown_tag_open: $ => '<spt:updown',

		spt_upload_tag: $ => seq(
			$.spt_upload_tag_open,
			repeat(
				choice(
					$.dynamic_attribute,
					$.locale_attribute,
					$.name_attribute,
					$.previewimage_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_upload_tag_open: $ => '<spt:upload',

		spt_worklist_tag: $ => seq(
			$.spt_worklist_tag_open,
			repeat(
				choice(
					$.command_attribute,
					$.informationID_attribute,
					$.poolID_attribute,
					$.worklistID_attribute,
				),
			),
			$.self_closing_tag_end,
		),
		spt_worklist_tag_open: $ => '<spt:worklist',

		// attributes

		dynamic_attribute: $ => seq(
			$.attribute_name,
			optional(
				seq(
					'=',
					$.html_string,
				),
			),
		),
		attribute_name: $ => $._word,

		absolute_attribute: $ => seq(
			'absolute',
			'=',
			$.string,
		),

		action_attribute: $ => seq(
			'action',
			'=',
			$.string,
		),

		align_attribute: $ => seq(
			'align',
			'=',
			$.string,
		),

		alt_attribute: $ => seq(
			'alt',
			'=',
			$.string,
		),

		anchor_attribute: $ => seq(
			'anchor',
			'=',
			$.string,
		),

		api_attribute: $ => seq(
			'api',
			'=',
			$.string,
		),

		arg_attribute: $ => seq(
			'arg',
			'=',
			$.string,
		),

		arguments_attribute: $ => seq(
			'arguments',
			'=',
			$.string,
		),

		attributes_attribute: $ => seq(
			'attributes',
			'=',
			$.string,
		),

		background_attribute: $ => seq(
			'background',
			'=',
			$.string,
		),

		bgcolor_attribute: $ => seq(
			'bgcolor',
			'=',
			$.string,
		),

		bgcolor2_attribute: $ => seq(
			'bgcolor2',
			'=',
			$.string,
		),

		checked_attribute: $ => seq(
			'checked',
			'=',
			$.string,
		),

		childrenlink_attribute: $ => seq(
			'childrenlink',
			'=',
			$.string,
		),

		classname_attribute: $ => seq(
			'classname',
			'=',
			$.string,
		),

		client_attribute: $ => seq(
			'client',
			'=',
			$.string,
		),

		code_attribute: $ => seq(
			'code',
			'=',
			$.string,
		),

		collection_attribute: $ => seq(
			'collection',
			'=',
			$.string,
		),

		color_attribute: $ => seq(
			'color',
			'=',
			$.string,
		),

		color2_attribute: $ => seq(
			'color2',
			'=',
			$.string,
		),

		cols_attribute: $ => seq(
			'cols',
			'=',
			$.string,
		),

		command_attribute: $ => seq(
			'command',
			'=',
			$.string,
		),

		condition_attribute: $ => seq(
			'condition',
			'=',
			$.string,
		),

		config_attribute: $ => seq(
			'config',
			'=',
			$.string,
		),

		configextension_attribute: $ => seq(
			'configextension',
			'=',
			$.string,
		),

		configvalues_attribute: $ => seq(
			'configvalues',
			'=',
			$.string,
		),

		connect_attribute: $ => seq(
			'connect',
			'=',
			$.string,
		),

		contains_attribute: $ => seq(
			'contains',
			'=',
			$.string,
		),

		contentType_attribute: $ => seq(
			'contentType',
			'=',
			$.string,
		),

		contenttype_attribute: $ => seq(
			'contenttype',
			'=',
			$.string,
		),

		context_attribute: $ => seq(
			'context',
			'=',
			$.string,
		),

		convert_attribute: $ => seq(
			'convert',
			'=',
			$.string,
		),

		cryptkey_attribute: $ => seq(
			'cryptkey',
			'=',
			$.string,
		),

		date_attribute: $ => seq(
			'date',
			'=',
			$.string,
		),

		dateformat_attribute: $ => seq(
			'dateformat',
			'=',
			$.string,
		),

		decimalformat_attribute: $ => seq(
			'decimalformat',
			'=',
			$.string,
		),

		decoding_attribute: $ => seq(
			'decoding',
			'=',
			$.string,
		),

		decrypt_attribute: $ => seq(
			'decrypt',
			'=',
			$.string,
		),

		default_attribute: $ => seq(
			'default',
			'=',
			$.string,
		),

		delete_attribute: $ => seq(
			'delete',
			'=',
			$.string,
		),

		directory_attribute: $ => seq(
			'directory',
			'=',
			$.string,
		),

		disabled_attribute: $ => seq(
			'disabled',
			'=',
			$.string,
		),

		dynamics_attribute: $ => seq(
			'dynamics',
			'=',
			$.string,
		),

		editablePlaceholder_attribute: $ => seq(
			'editablePlaceholder',
			'=',
			$.string,
		),

		element_attribute: $ => seq(
			'element',
			'=',
			$.string,
		),

		encoding_attribute: $ => seq(
			'encoding',
			'=',
			$.string,
		),

		encrypt_attribute: $ => seq(
			'encrypt',
			'=',
			$.string,
		),

		eq_attribute: $ => seq(
			'eq',
			'=',
			$.string,
		),

		excerpt_attribute: $ => seq(
			'excerpt',
			'=',
			$.string,
		),

		expression_attribute: $ => seq(
			'expression',
			'=',
			$.string,
		),

		files_attribute: $ => seq(
			'files',
			'=',
			$.string,
		),

		filter_attribute: $ => seq(
			'filter',
			'=',
			$.string,
		),

		filterattribute_attribute: $ => seq(
			'filterattribute',
			'=',
			$.string,
		),

		filteric_attribute: $ => seq(
			'filteric',
			'=',
			$.string,
		),

		filterinvert_attribute: $ => seq(
			'filterinvert',
			'=',
			$.string,
		),

		filtermode_attribute: $ => seq(
			'filtermode',
			'=',
			$.string,
		),

		filterquery_attribute: $ => seq(
			'filterquery',
			'=',
			$.string,
		),

		fixvalue_attribute: $ => seq(
			'fixvalue',
			'=',
			$.string,
		),

		focalpoint_attribute: $ => seq(
			'focalpoint',
			'=',
			$.string,
		),

		font_attribute: $ => seq(
			'font',
			'=',
			$.string,
		),

		font2_attribute: $ => seq(
			'font2',
			'=',
			$.string,
		),

		font_size_attribute: $ => seq(
			'font-size',
			'=',
			$.string,
		),

		font_weight_attribute: $ => seq(
			'font-weight',
			'=',
			$.string,
		),

		fontcolor_attribute: $ => seq(
			'fontcolor',
			'=',
			$.string,
		),

		fontname_attribute: $ => seq(
			'fontname',
			'=',
			$.string,
		),

		fontsize_attribute: $ => seq(
			'fontsize',
			'=',
			$.string,
		),

		fontsize2_attribute: $ => seq(
			'fontsize2',
			'=',
			$.string,
		),

		fontstyle_attribute: $ => seq(
			'fontstyle',
			'=',
			$.string,
		),

		fontweight_attribute: $ => seq(
			'fontweight',
			'=',
			$.string,
		),

		fontweight2_attribute: $ => seq(
			'fontweight2',
			'=',
			$.string,
		),

		form_attribute: $ => seq(
			'form',
			'=',
			$.string,
		),

		format_attribute: $ => seq(
			'format',
			'=',
			$.string,
		),

		from_attribute: $ => seq(
			'from',
			'=',
			$.string,
		),

		gt_attribute: $ => seq(
			'gt',
			'=',
			$.string,
		),

		gte_attribute: $ => seq(
			'gte',
			'=',
			$.string,
		),

		gravity_attribute: $ => seq(
			'gravity',
			'=',
			$.string,
		),

		gui_attribute: $ => seq(
			'gui',
			'=',
			$.string,
		),

		handler_attribute: $ => seq(
			'handler',
			'=',
			$.string,
		),

		height_attribute: $ => seq(
			'height',
			'=',
			$.string,
		),

		hidden_attribute: $ => seq(
			'hidden',
			'=',
			$.string,
		),

		hide_attribute: $ => seq(
			'hide',
			'=',
			$.string,
		),

		host_attribute: $ => seq(
			'host',
			'=',
			$.string,
		),

		hyphenEditor_attribute: $ => seq(
			'hyphenEditor',
			'=',
			$.string,
		),

		ic_attribute: $ => seq(
			'ic',
			'=',
			$.string,
		),

		id_attribute: $ => seq(
			'id',
			'=',
			$.string,
		),

		image_attribute: $ => seq(
			'image',
			'=',
			$.string,
		),

		import_attribute: $ => seq(
			'import',
			'=',
			$.string,
		),

		indent_attribute: $ => seq(
			'indent',
			'=',
			$.string,
		),

		index_attribute: $ => seq(
			'index',
			'=',
			$.string,
		),

		information_attribute: $ => seq(
			'information',
			'=',
			$.string,
		),

		informationID_attribute: $ => seq(
			'informationID',
			'=',
			$.string,
		),

		insert_attribute: $ => seq(
			'insert',
			'=',
			$.string,
		),

		inputType_attribute: $ => seq(
			'inputType',
			'=',
			$.string,
		),

		invert_attribute: $ => seq(
			'invert',
			'=',
			$.string,
		),

		isNull_attribute: $ => seq(
			'isNull',
			'=',
			$.string,
		),

		item_attribute: $ => seq(
			'item',
			'=',
			$.string,
		),

		itemtext_attribute: $ => seq(
			'itemtext',
			'=',
			$.string,
		),

		key_attribute: $ => seq(
			'key',
			'=',
			$.string,
		),

		keys_attribute: $ => seq(
			'keys',
			'=',
			$.string,
		),

		language_attribute: $ => seq(
			'language',
			'=',
			$.string,
		),

		layout_attribute: $ => seq(
			'layout',
			'=',
			$.string,
		),

		leaflink_attribute: $ => seq(
			'leaflink',
			'=',
			$.string,
		),

		level_attribute: $ => seq(
			'level',
			'=',
			$.string,
		),

		linkcolor_attribute: $ => seq(
			'linkcolor',
			'=',
			$.string,
		),

		list_attribute: $ => seq(
			'list',
			'=',
			$.string,
		),

		locale_attribute: $ => seq(
			'locale',
			'=',
			$.string,
		),

		localelink_attribute: $ => seq(
			'localelink',
			'=',
			$.string,
		),

		login_attribute: $ => seq(
			'login',
			'=',
			$.string,
		),

		lookup_attribute: $ => seq(
			'lookup',
			'=',
			$.string,
		),

		lt_attribute: $ => seq(
			'lt',
			'=',
			$.string,
		),

		lte_attribute: $ => seq(
			'lte',
			'=',
			$.string,
		),

		manipulate_attribute: $ => seq(
			'manipulate',
			'=',
			$.string,
		),

		max_attribute: $ => seq(
			'max',
			'=',
			$.string,
		),

		message_attribute: $ => seq(
			'message',
			'=',
			$.string,
		),

		min_attribute: $ => seq(
			'min',
			'=',
			$.string,
		),

		mode_attribute: $ => seq(
			'mode',
			'=',
			$.string,
		),

		module_attribute: $ => seq(
			'module',
			'=',
			$.string,
		),

		multiple_attribute: $ => seq(
			'multiple',
			'=',
			$.string,
		),

		name_attribute: $ => seq(
			'name',
			'=',
			$.string,
		),

		nameencoding_attribute: $ => seq(
			'nameencoding',
			'=',
			$.string,
		),

		namespace_attribute: $ => seq(
			'namespace',
			'=',
			$.string,
		),

		neq_attribute: $ => seq(
			'neq',
			'=',
			$.string,
		),

		node_attribute: $ => seq(
			'node',
			'=',
			$.string,
		),

		nowButton_attribute: $ => seq(
			'nowButton',
			'=',
			$.string,
		),

		object_attribute: $ => seq(
			'object',
			'=',
			$.string,
		),

		offset_attribute: $ => seq(
			'offset',
			'=',
			$.string,
		),

		offvalue_attribute: $ => seq(
			'offvalue',
			'=',
			$.string,
		),

		onclick_attribute: $ => seq(
			'onclick',
			'=',
			$.string,
		),

		onvalue_attribute: $ => seq(
			'onvalue',
			'=',
			$.string,
		),

		options_attribute: $ => seq(
			'options',
			'=',
			$.string,
		),

		original_attribute: $ => seq(
			'original',
			'=',
			$.string,
		),

		overwrite_attribute: $ => seq(
			'overwrite',
			'=',
			$.string,
		),

		padding_attribute: $ => seq(
			'padding',
			'=',
			$.string,
		),

		paddingcolor_attribute: $ => seq(
			'paddingcolor',
			'=',
			$.string,
		),

		pageEncoding_attribute: $ => seq(
			'pageEncoding',
			'=',
			$.string,
		),

		parentlink_attribute: $ => seq(
			'parentlink',
			'=',
			$.string,
		),

		password_attribute: $ => seq(
			'password',
			'=',
			$.string,
		),

		path_attribute: $ => seq(
			'path',
			'=',
			$.string,
		),

		personalization_attribute: $ => seq(
			'personalization',
			'=',
			$.string,
		),

		placeholder_attribute: $ => seq(
			'placeholder',
			'=',
			$.string,
		),

		poolID_attribute: $ => seq(
			'poolID',
			'=',
			$.string,
		),

		pools_attribute: $ => seq(
			'pools',
			'=',
			$.string,
		),

		popupheight_attribute: $ => seq(
			'popupheight',
			'=',
			$.string,
		),

		popupwidth_attribute: $ => seq(
			'popupwidth',
			'=',
			$.string,
		),

		prefix_attribute: $ => seq(
			'prefix',
			'=',
			$.string,
		),

		previewimage_attribute: $ => seq(
			'previewimage',
			'=',
			$.string,
		),

		processor_attribute: $ => seq(
			'processor',
			'=',
			$.string,
		),

		publisher_attribute: $ => seq(
			'publisher',
			'=',
			$.string,
		),

		quality_attribute: $ => seq(
			'quality',
			'=',
			$.string,
		),

		querystring_attribute: $ => seq(
			'querystring',
			'=',
			$.string,
		),

		query_attribute: $ => seq(
			'query',
			'=',
			$.string,
		),

		range_attribute: $ => seq(
			'range',
			'=',
			$.string,
		),

		readonly_attribute: $ => seq(
			'readonly',
			'=',
			$.string,
		),

		return_attribute: $ => seq(
			'return',
			'=',
			$.string,
		),

		revised_attribute: $ => seq(
			'revised',
			'=',
			$.string,
		),

		role_attribute: $ => seq(
			'role',
			'=',
			$.string,
		),

		rootelement_attribute: $ => seq(
			choice(
				'rootElement',
				'rootelement',
			),
			'=',
			$.string,
		),

		rows_attribute: $ => seq(
			'rows',
			'=',
			$.string,
		),

		scalesteps_attribute: $ => seq(
			'scalesteps',
			'=',
			$.string,
		),

		scope_attribute: $ => seq(
			'scope',
			'=',
			$.string,
		),

		selected_attribute: $ => seq(
			'selected',
			'=',
			$.string,
		),

		separator_attribute: $ => seq(
			'separator',
			'=',
			$.string,
		),

		sequences_attribute: $ => seq(
			'sequences',
			'=',
			$.string,
		),

		showtree_attribute: $ => seq(
			'showtree',
			'=',
			$.string,
		),

		size_attribute: $ => seq(
			'size',
			'=',
			$.string,
		),

		sortkeys_attribute: $ => seq(
			'sortkeys',
			'=',
			$.string,
		),

		sortsequences_attribute: $ => seq(
			'sortsequences',
			'=',
			$.string,
		),

		sorttypes_attribute: $ => seq(
			'sorttypes',
			'=',
			$.string,
		),

		source_attribute: $ => seq(
			'source',
			'=',
			$.string,
		),

		step_attribute: $ => seq(
			'step',
			'=',
			$.string,
		),

		style_attribute: $ => seq(
			'style',
			'=',
			$.string,
		),

		tagdir_attribute: $ => seq(
			'tagdir',
			'=',
			$.string,
		),

		tagScope_attribute: $ => seq(
			'tagScope',
			'=',
			$.string,
		),

		template_attribute: $ => seq(
			'template',
			'=',
			$.string,
		),

		text_attribute: $ => seq(
			'text',
			'=',
			$.string,
		),

		textlabel_attribute: $ => seq(
			'textlabel',
			'=',
			$.string,
		),

		text_transform_attribute: $ => seq(
			'text-transform',
			'=',
			$.string,
		),

		theme_attribute: $ => seq(
			'theme',
			'=',
			$.string,
		),

		time_attribute: $ => seq(
			'time',
			'=',
			$.string,
		),

		title_attribute: $ => seq(
			'title',
			'=',
			$.string,
		),

		to_attribute: $ => seq(
			'to',
			'=',
			$.string,
		),

		toggle_attribute: $ => seq(
			'toggle',
			'=',
			$.string,
		),

		transform_attribute: $ => seq(
			'transform',
			'=',
			$.string,
		),

		type_attribute: $ => seq(
			'type',
			'=',
			$.string,
		),

		types_attribute: $ => seq(
			'types',
			'=',
			$.string,
		),

		uri_attribute: $ => seq(
			'uri',
			'=',
			$.string,
		),

		url_attribute: $ => seq(
			'url',
			'=',
			$.string,
		),

		urlonly_attribute: $ => seq(
			'urlonly',
			'=',
			$.string,
		),

		urlparam_attribute: $ => seq(
			'urlparam',
			'=',
			$.string,
		),

		user_attribute: $ => seq(
			'user',
			'=',
			$.string,
		),

		value_attribute: $ => seq(
			'value',
			'=',
			$.string,
		),

		varname_attribute: $ => seq(
			choice(
				'varname',
				'varName',
			),
			'=',
			$.string,
		),

		worklistID_attribute: $ => seq(
			'worklistID',
			'=',
			$.string,
		),

		width_attribute: $ => seq(
			'width',
			'=',
			$.string,
		),

		window_attribute: $ => seq(
			'window',
			'=',
			$.string,
		),

		// other

		comment: $ => /<%--[^-]*-(?:(?:[^-]|-+[^-%]|-+%[^>])[^-]*-)*-+%>/,

		string: $ => seq(
			'"',
			$.string_content,
			'"',
		),
		string_content: $ => repeat1(
			choice(
				/[^"]+/,
				'\\"',
			),
		),

		html_string: $ => seq(
			'"',
			repeat(
				choice(
					/[^"<]+/,
					$._top_level_sp_tag,
					prec(-1, '\\"'),
					prec(-1, '<'),
				),
			),
			'"',
		),

		text: $ => /[^<>&\s]+(?:[^<>&]+[^<>&\s])?/,

		script_tag: $ => seq(
			'<script',
			repeat($.dynamic_attribute),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat(
						choice(
							$.tag_code,
							prec(1, $._top_level_sp_tag),
							prec(2, $.xml_entity),
						),
					),
					'</script>',
				),
			)
		),

		style_tag: $ => seq(
			'<style',
			repeat($.dynamic_attribute),
			choice(
				$.self_closing_tag_end,
				seq(
					'>',
					repeat(
						choice(
							$.tag_code,
							prec(1, $._top_level_sp_tag),
							prec(2, $.xml_entity),
						),
					),
					'</style>',
				),
			)
		),

		tag_code: $ => seq($._tag_code_text),
		_tag_code_text: $ => choice(
			/[^<>&\s]+(?:[^<>&]+[^<>&\s])?/,
			'<',
			'>',
		),

		java_tag: $ => seq(
			'<%',
			optional($.java_code),
			'%>',
		),
		java_code: $ => /[^%\s]+(?:(?:[^%]+|%+[^>%][^%]+)[^%\s])*/,

		html_tag: $ => seq(
			$.html_tag_open,
			repeat($.dynamic_attribute),
			'>',
			repeat($._top_level_tag),
			$.html_tag_close,
		),

		html_option_tag: $ => prec.left(
			seq(
				$.html_option_tag_open,
				repeat($.dynamic_attribute),
				'>',
				optional(
					seq(
						repeat($._top_level_tag),
						$.html_option_tag_close,
					),
				),
			),
		),

		html_void_tag: $ => seq(
			$.html_void_tag_open,
			repeat($.dynamic_attribute),
			choice(
				'>',
				$.self_closing_tag_end,
			),
		),

		html_doctype: $ => seq(
			'<!',
			/[Dd][Oo][Cc][Tt][Yy][Pp][Ee]/,
			'html',
			optional(
				choice(
					'"about:legacy-compat"',
					'\'about:legacy-compat\'',
				),
			),
			'>',
		),

		xml_comment: $ => seq(
			'<!--',
			repeat(
				choice(
					$._top_level_sp_tag,
					$.comment,
					/[^-<]+/,
					'-',
					'<',
				),
			),
			'-->',
		),

		xml_entity: $ => /&(#([xX][0-9a-fA-F]{1,6}|[0-9]{1,5})|[A-Za-z]{1,30});/,
	}
});
