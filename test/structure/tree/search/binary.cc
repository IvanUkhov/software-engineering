#include "gtest/gtest.h"
#include "structure/tree/search/binary.h"

void populate(Binary& tree);

TEST(BinaryTest, Query) {
  Binary tree;
  populate(tree);
  ASSERT_EQ(tree.root()->right->right->left->value, 13);
}

void populate(Binary& tree) {
  tree.Insert(8);
  tree.Insert(3);
  tree.Insert(1);
  tree.Insert(6);
  tree.Insert(4);
  tree.Insert(7);
  tree.Insert(10);
  tree.Insert(14);
  tree.Insert(13);
}
