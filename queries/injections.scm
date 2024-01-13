((script_tag
  (text) @injection.content)
 (#set! injection.language "javascript"))

((style_tag
  (text) @injection.content)
 (#set! injection.language "css"))
