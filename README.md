# tree-sitter-spml

SPML grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter).

## features

- Parser for SPML Syntax Trees
- Syntax highlighting
- Can use [tree-sitter-java](https://github.com/tree-sitter/tree-sitter-java), [tree-sitter-javascript](https://github.com/tree-sitter/tree-sitter-javascript) and [tree-sitter-css](https://github.com/tree-sitter/tree-sitter-css) for the respective embedded languages.

## install

### neovim

- install [nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter)
- make sure `*.spml` files are associated with the `spml` filetype

```lua
vim.filetype.add({
  extension = {
    spml = "spml",
  },
})
```

- add the a cutom parser

```lua
vim.api.nvim_create_autocmd("User", {
	pattern = "TSUpdate",
	callback = function()
		require("nvim-treesitter.parsers").spml = {
			tier = 0,
			install_info = {
				url = "https://github.com/DrWursterich/tree-sitter-spml",
				revision = "main",
				-- if you have a local copy you can also do this instead
				-- path = '<path-to>/tree-sitter-spml',
				queries = 'queries',
			},
		}
	end,
})
```

- install it `nvim -c 'TSInstall spml java javascript css' -c 'TSUpdate'`

