package tree_sitter_spml_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-spml"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_spml.Language())
	if language == nil {
		t.Errorf("Error loading Spml grammar")
	}
}
