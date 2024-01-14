((script_tag
  (tag_code) @injection.content)
 (#set! injection.language "javascript"))

((style_tag
  (tag_code) @injection.content)
 (#set! injection.language "css"))

((java_tag
  (java_code) @injection.content)
 (#set! injection.language "java"))

