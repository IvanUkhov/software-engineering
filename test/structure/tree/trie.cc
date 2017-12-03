#include "gtest/gtest.h"
#include "structure/tree/trie.h"

typedef structure::tree::Trie<int> Tree;

void Populate(Tree& tree) {
  tree.Insert("A", 15);
  tree.Insert("to", 7);
  tree.Insert("tea", 3);
  tree.Insert("ted", 4);
  tree.Insert("ten", 12);
  tree.Insert("i", 11);
  tree.Insert("in", 5);
  tree.Insert("inn", 9);
}

TEST(TreeTest, TrieSearch) {
  Tree tree;
  Populate(tree);
  ASSERT_EQ(tree.Search("ten"), 12);
  ASSERT_EQ(tree.Search("hello"), 0);
}
