# tree-sitter-spml

SPML grammar for [tree-sitter](https://github.com/tree-sitter/tree-sitter).

## features

- Parser for SPML Syntax Trees
- Syntax highlighting
- Can use [tree-sitter-java](https://github.com/tree-sitter/tree-sitter-java), [tree-sitter-javascript](https://github.com/tree-sitter/tree-sitter-javascript) and [tree-sitter-css](https://github.com/tree-sitter/tree-sitter-css) for the respective embedded languages.

## build

depending on what you intend to use it for you may build it with one of the following tools:
- `make`
- `npm`
- `cargo`

## install

### neovim

- install [nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter)
- build `tree-sitter-spml` with `make`
- copy or link the build `libtree-sitter-spml.so` into the `nvim-treesitter/parsers/` directory under the name `spml`
- copy or link all `.scm` files inside of the `queries/` directory into a new `nvim-treesitter/queries/spml` directory
- optionally invoke `:TSInstall java`, `:TSInstall javascript` and `:TSInstall css` from inside neovim

