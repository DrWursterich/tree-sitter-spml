
[
  (page_header)
  (taglib_header)
] @include

(page_header
  "page" @keyword
  [
    (language_attribute)
    (pageEncoding_attribute)
    (contentType_attribute)
  ] @field)
(taglib_header
  "taglib" @keyword
  [
    (uri_attribute)
    (tagdir_attribute)
    (prefix_attribute)
  ] @field)

(html_doctype) @tag
(html_tag
  (html_tag_open) @tag
  ">" @tag
  (html_tag_close) @tag)
(html_option_tag
  (html_option_tag_open) @tag
  ">" @tag .)
(html_void_tag
  (html_void_tag_open) @tag
  [
    (self_closing_tag_end)
    ">"
  ] @tag .)
(script_tag
  "<script" @tag
  [
    ">"
    "</script>"
  ] @tag)
(style_tag
  "<style" @tag
  [
    ">"
    "</style>"
  ] @tag)

[
  (attribute_tag
    (attribute_tag_open) @keyword
    [
      (condition_attribute)
      (dynamics_attribute)
      (expression_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (object_attribute)
      (text_attribute)
    ]? @field
    (self_closing_tag_end) @keyword .)
  (barcode_tag
    (barcode_tag_open) @keyword
    [
      (height_attribute)
      (height_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (scope_attribute)
      (text_attribute)
      (type_attribute)
      (width_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (scope_attribute)
      (text_attribute)
      (type_attribute)
      (width_attribute)
    ]? @field
    (self_closing_tag_end) @keyword .)
  (break_tag
    (break_tag_open) @keyword
    (self_closing_tag_end) @keyword .)
  (calendarsheet_tag
    (calendarsheet_tag_open) @keyword
    [
      (action_attribute)
      (date_attribute)
      (from_attribute)
      (mode_attribute)
      (name_attribute)
      (object_attribute)
      (scope_attribute)
      (to_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (calendarsheet_tag_close)
    ] @keyword .)
  (checkbox_tag
    (checkbox_tag_open) @keyword
    [
      (checked_attribute)
      (disabled_attribute)
      (dynamics_attribute)
      (format_attribute)
      (hidden_attribute)
      (id_attribute)
      (locale_attribute)
      (name_attribute)
      (personalization_attribute)
      (readonly_attribute)
      (type_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (checkbox_tag_close)
    ] @keyword .)
  (code_tag
    (code_tag_open) @keyword
    (self_closing_tag_end) @keyword)
  (collection_tag
    (collection_tag_open) @keyword
    [
      (action_attribute)
      (condition_attribute)
      (default_attribute)
      (expression_attribute)
      (index_attribute)
      (locale_attribute)
      (name_attribute)
      (object_attribute)
      (publisher_attribute)
      (query_attribute)
      (scope_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (collection_tag_close)
    ] @keyword .)
  (condition_tag
    (condition_tag_open) @keyword
    (self_closing_tag_end) @keyword)
  (diff_tag
    (diff_tag_open) @keyword
    [
      (from_attribute)
      (information_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (original_attribute)
      (revised_attribute)
      (to_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (diff_tag_close)
    ] @keyword .)
  (else_tag
    (else_tag_open) @keyword
    (self_closing_tag_end) @keyword)
  (elseif_tag
    (elseif_tag_open) @keyword
    [
      (condition_attribute)
      (contains_attribute)
      (eq_attribute)
      (gt_attribute)
      (gte_attribute)
      (ic_attribute)
      (isNull_attribute)
      (locale_attribute)
      (lt_attribute)
      (lte_attribute)
      (name_attribute)
      (neq_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (elseif_tag_close)
    ] @keyword .)
  (error_tag
    (error_tag_open) @keyword
    [
      (code_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (error_tag_close)
    ] @keyword .)
  (expire_tag
    (expire_tag_open) @keyword
    [
      (date_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (expire_tag_close)
    ] @keyword .)
  (filter_tag
    (filter_tag_open) @keyword
    [
      (collection_attribute)
      (filter_attribute)
      (format_attribute)
      (from_attribute)
      (ic_attribute)
      (invert_attribute)
      (locale_attribute)
      (lookup_attribute)
      (mode_attribute)
      (name_attribute)
      (scope_attribute)
      (to_attribute)
      (type_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (filter_tag_close)
    ] @keyword .)
  (for_tag
    (for_tag_open) @keyword
    [
      (condition_attribute)
      (from_attribute)
      (index_attribute)
      (locale_attribute)
      (lookup_attribute)
      (step_attribute)
      (to_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (for_tag_close)
    ] @keyword .)
  (form_tag
    (form_tag_open) @keyword
    [
      (command_attribute)
      (context_attribute)
      (handler_attribute)
      (host_attribute)
      (id_attribute)
      (module_attribute)
      (nameencoding_attribute)
      (template_attribute)
      (uri_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (form_tag_close)
    ] @keyword .)
  (hidden_tag
    (hidden_tag_open) @keyword
    [
      (dynamics_attribute)
      (fixvalue_attribute)
      (format_attribute)
      (id_attribute)
      (locale_attribute)
      (name_attribute)
      (personalization_attribute)
      (type_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (hidden_tag_close)
    ] @keyword .)
  (if_tag
    (if_tag_open) @keyword
    [
      (condition_attribute)
      (contains_attribute)
      (eq_attribute)
      (gt_attribute)
      (gte_attribute)
      (ic_attribute)
      (isNull_attribute)
      (locale_attribute)
      (lt_attribute)
      (lte_attribute)
      (name_attribute)
      (neq_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (if_tag_close)
    ] @keyword .)
  (include_tag
    (include_tag_open) @keyword
    [
      (anchor_attribute)
      (arguments_attribute)
      (context_attribute)
      (locale_attribute)
      (lookup_attribute)
      (mode_attribute)
      (module_attribute)
      (return_attribute)
      (template_attribute)
      (uri_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (include_tag_close)
    ] @keyword .)
  (io_tag
    (io_tag_open) @keyword
    [
      (contenttype_attribute)
      (type_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (io_tag_close)
    ] @keyword .)
  (iterator_tag
    (iterator_tag_open) @keyword
    [
      (collection_attribute)
      (item_attribute)
      (locale_attribute)
      (lookup_attribute)
      (max_attribute)
      (min_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (iterator_tag_close)
    ] @keyword .)
  (json_tag
    (json_tag_open) @keyword
    [
      (indent_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (object_attribute)
      (overwrite_attribute)
      (scope_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (json_tag_close)
    ] @keyword .)
  (linkedInformation_tag
    (linkedInformation_tag_open) @keyword
    [
      (locale_attribute)
      (name_attribute)
      (type_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (linkedInformation_tag_close)
    ] @keyword .)
  (linktree_tag
    (linktree_tag_open) @keyword
    [
      (arg_attribute)
      (attributes_attribute)
      (childrenlink_attribute)
      (locale_attribute)
      (localelink_attribute)
      (lookup_attribute)
      (name_attribute)
      (parentlink_attribute)
      (rootelement_attribute)
      (sortkeys_attribute)
      (sortsequences_attribute)
      (sorttypes_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (linktree_tag_close)
    ] @keyword .)
  (livetree_tag
    (livetree_tag_open) @keyword
    [
      (action_attribute)
      (childrenlink_attribute)
      (leaflink_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (node_attribute)
      (parentlink_attribute)
      (publisher_attribute)
      (rootelement_attribute)
      (sortkeys_attribute)
      (sortsequences_attribute)
      (sorttypes_attribute)
    ]? @field
    (self_closing_tag_end) @keyword .)
  (log_tag
    (log_tag_open) @keyword
    [
      (level_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (log_tag_close)
    ] @keyword .)
  (login_tag
    (login_tag_open) @keyword
    [
      (client_attribute)
      (gui_attribute)
      (login_attribute)
      (namespace_attribute)
      (password_attribute)
      (scope_attribute)
    ]? @field
    (self_closing_tag_end) @keyword .)
  (loop_tag
    (loop_tag_open) @keyword
    [
      (collection_attribute)
      (list_attribute)
      (separator_attribute)
      (item_attribute)
      (locale_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (loop_tag_close)
    ] @keyword .)
  (map_tag
    (map_tag_open) @keyword
    [
      (action_attribute)
      (condition_attribute)
      (default_attribute)
      (expression_attribute)
      (key_attribute)
      (locale_attribute)
      (name_attribute)
      (object_attribute)
      (overwrite_attribute)
      (scope_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (map_tag_close)
    ] @keyword .)
  (option_tag
    (option_tag_open) @keyword
    [
      (disabled_attribute)
      (id_attribute)
      (selected_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (option_tag_close)
    ] @keyword .)
  (password_tag
    (password_tag_open) @keyword
    [
      (disabled_attribute)
      (dynamics_attribute)
      (fixvalue_attribute)
      (format_attribute)
      (id_attribute)
      (locale_attribute)
      (name_attribute)
      (personalization_attribute)
      (readonly_attribute)
      (type_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (password_tag_close)
    ] @keyword .)
  (print_tag
    (print_tag_open) @keyword
    [
      (arg_attribute)
      (condition_attribute)
      (convert_attribute)
      (cryptkey_attribute)
      (dateformat_attribute)
      (decimalformat_attribute)
      (decoding_attribute)
      (decrypt_attribute)
      (default_attribute)
      (encoding_attribute)
      (encrypt_attribute)
      (expression_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (text_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (print_tag_close)
    ] @keyword .)
  (querytree_tag
    (querytree_tag_open) @keyword
    [
      (attributes_attribute)
      (item_attribute)
      (name_attribute)
      (query_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (querytree_tag_close)
    ] @keyword .)
  (radio_tag
    (radio_tag_open) @keyword
    [
      (checked_attribute)
      (disabled_attribute)
      (dynamics_attribute)
      (format_attribute)
      (hidden_attribute)
      (id_attribute)
      (locale_attribute)
      (name_attribute)
      (personalization_attribute)
      (readonly_attribute)
      (type_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (radio_tag_close)
    ] @keyword .)
  (range_tag
    (range_tag_open) @keyword
    [
      (collection_attribute)
      (name_attribute)
      (range_attribute)
      (scope_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (range_tag_close)
    ] @keyword .)
  (return_tag
    (return_tag_open) @keyword
    [
      (condition_attribute)
      (default_attribute)
      (expression_attribute)
      (locale_attribute)
      (object_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (return_tag_close)
    ] @keyword .)
  (sass_tag
    (sass_tag_open) @keyword
    [
      (name_attribute)
      (options_attribute)
      (source_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (sass_tag_close)
    ] @keyword .)
  (scaleimage_tag
    (scaleimage_tag_open) @keyword
    [
      (background_attribute)
      (format_attribute)
      (height_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (object_attribute)
      (options_attribute)
      (padding_attribute)
      (processor_attribute)
      (quality_attribute)
      (scalesteps_attribute)
      (scope_attribute)
      (width_attribute)
    ]? @field
    (self_closing_tag_end) @keyword .)
  (scope_tag
    (scope_tag_open) @keyword
    [
      (scope_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (scope_tag_close)
    ] @keyword .)
  (search_tag
    (search_tag_open) @keyword
    [
      (name_attribute)
      (time_attribute)
      (type_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (search_tag_close)
    ] @keyword .)
  (select_tag
    (select_tag_open) @keyword
    [
      (disabled_attribute)
      (dynamics_attribute)
      (format_attribute)
      (hidden_attribute)
      (id_attribute)
      (locale_attribute)
      (multiple_attribute)
      (name_attribute)
      (personalization_attribute)
      (type_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (select_tag_close)
    ] @keyword .)
  (set_tag
    (set_tag_open) @keyword
    [
      (condition_attribute)
      (contentType_attribute)
      (dateformat_attribute)
      (decimalformat_attribute)
      (default_attribute)
      (expression_attribute)
      (insert_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (object_attribute)
      (overwrite_attribute)
      (scope_attribute)
      (tagScope_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (set_tag_close)
    ] @keyword .)
  (sort_tag
    (sort_tag_open) @keyword
    [
      (collection_attribute)
      (keys_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (scope_attribute)
      (sequences_attribute)
      (types_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (sort_tag_close)
    ] @keyword .)
  (subinformation_tag
    (subinformation_tag_open) @keyword
    [
      (locale_attribute)
      (name_attribute)
      (type_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (subinformation_tag_close)
    ] @keyword .)
  (tagbody_tag
    (tagbody_tag_open) @keyword
    (self_closing_tag_end) @keyword)
  (text_tag
    (text_tag_open) @keyword
    [
      (disabled_attribute)
      (dynamics_attribute)
      (fixvalue_attribute)
      (format_attribute)
      (hidden_attribute)
      (id_attribute)
      (inputType_attribute)
      (locale_attribute)
      (name_attribute)
      (personalization_attribute)
      (readonly_attribute)
      (type_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (text_tag_close)
    ] @keyword .)
  (textarea_tag
    (textarea_tag_open) @keyword
    [
      (disabled_attribute)
      (dynamics_attribute)
      (fixvalue_attribute)
      (format_attribute)
      (hidden_attribute)
      (id_attribute)
      (locale_attribute)
      (name_attribute)
      (personalization_attribute)
      (readonly_attribute)
      (type_attribute)
      (value_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (textarea_tag_close)
    ] @keyword .)
  (textimage_tag
    (textimage_tag_open) @keyword
    [
      (background_attribute)
      (fontcolor_attribute)
      (fontname_attribute)
      (fontsize_attribute)
      (fontstyle_attribute)
      (gravity_attribute)
      (height_attribute)
      (locale_attribute)
      (lookup_attribute)
      (name_attribute)
      (offset_attribute)
      (processor_attribute)
      (scope_attribute)
      (text_attribute)
      (transform_attribute)
      (width_attribute)
    ]? @field
    (self_closing_tag_end) @keyword .)
  (throw_tag
    (throw_tag_open) @keyword
    [
      (locale_attribute)
      (lookup_attribute)
      (message_attribute)
    ]? @field
    (self_closing_tag_end) @keyword .)
  (upload_tag
    (upload_tag_open) @keyword
    [
      (dynamics_attribute)
      (fixvalue_attribute)
      (hidden_attribute)
      (id_attribute)
      (locale_attribute)
      (name_attribute)
      (personalization_attribute)
      (type_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (upload_tag_close)
    ] @keyword .)
  (url_tag
    (url_tag_open) @keyword
    [
      (absolute_attribute)
      (command_attribute)
      (context_attribute)
      (gui_attribute)
      (handler_attribute)
      (information_attribute)
      (locale_attribute)
      (lookup_attribute)
      (module_attribute)
      (path_attribute)
      (publisher_attribute)
      (template_attribute)
      (uri_attribute)
      (window_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (url_tag_close)
    ] @keyword .)
  (warning_tag
    (warning_tag_open) @keyword
    [
      (code_tag)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (warning_tag_close)
    ] @keyword .)
  (worklist_tag
    (worklist_tag_open) @keyword
    [
      (element_attribute)
      (name_attribute)
      (role_attribute)
      (type_attribute)
      (user_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (worklist_tag_close)
    ] @keyword .)
  (zip_tag
    (zip_tag_open) @keyword
    [
      (directory_attribute)
      (files_attribute)
      (name_attribute)
      (return_attribute)
    ]? @field
    .
    ">"? @keyword
    [
      (self_closing_tag_end)
      (zip_tag_close)
    ] @keyword .)
] @asdf

(dynamic_attribute) @attribute

(string) @string
[
  (interpolated_anchor
    "!{" @character.special
    "}" @character.special)
  (interpolated_string
    "${" @character.special
    "}" @character.special)
] @text.reference
(xml_entity) @string.escaped

(xml_comment) @text.reference
(comment) @comment

(ERROR) @error
