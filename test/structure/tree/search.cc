#include "gtest/gtest.h"
#include "structure/tree/search.h"

typedef structure::tree::BinarySearch<int, const char*> Tree;

void Populate(Tree& tree) {
  tree.Insert(8, "a");
  tree.Insert(3, "b");
  tree.Insert(1, "c");
  tree.Insert(6, "d");
  tree.Insert(4, "e");
  tree.Insert(7, "f");
  tree.Insert(10, "g");
  tree.Insert(14, "h");
  tree.Insert(13, "i");
}

TEST(TreeTest, BinarySearchInsert) {
  Tree tree;
  Populate(tree);
  ASSERT_EQ(tree.Root()->Right()->Right()->Left()->Key(), 13);
}

TEST(TreeTest, BinarySearchSearch) {
  Tree tree;
  Populate(tree);
  ASSERT_EQ(tree.Search(10)->Value(), "g");
}
