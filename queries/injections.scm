((script_tag
  (tag_code) @injection.content)
 (#set! injection.language "javascript"))

((style_tag
  (tag_code) @injection.content)
 (#set! injection.language "css"))

((java_tag
  (java_code) @injection.content)
 (#set! injection.language "java"))


((sass_tag
  (text) @injection.content)
 (#set! injection.language "scss")
 (#set! injection.combined))

((json_tag
  (text) @injection.content)
 (#set! injection.language "json"))

((dynamic_attribute
  (attribute_name) @_name
  (html_string
    (string_content) @injection.content))
 (#eq? @_name "style")
 (#set! injection.language "css"))

((dynamic_attribute
  (attribute_name) @_name
  (html_string
    (string_content) @injection.content))
 (#match? @_name "^on[a-z]+$")
 (#set! injection.language "javascript"))

([
  (comment)
  (xml_comment)
] @injection.content
 (#set! injection.language "comment"))
