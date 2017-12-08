#include "gtest/gtest.h"
#include "structure/tree/red_black.h"

typedef structure::tree::RedBlack<int, int> Tree;

TEST(TreeTest, RedBlackRotateLeft) {
  Tree tree;
  tree.Insert(1, 0);
  ASSERT_EQ(tree.Root()->Key(), 1);
  tree.Insert(2, 0);
  ASSERT_EQ(tree.Root()->Right()->Key(), 2);
  tree.Insert(3, 0);
  ASSERT_EQ(tree.Root()->Key(), 2);
  ASSERT_EQ(tree.Root()->Right()->Key(), 3);
  tree.Insert(4, 0);
  ASSERT_EQ(tree.Root()->Right()->Right()->Key(), 4);
  tree.Insert(5, 0);
  ASSERT_EQ(tree.Root()->Right()->Right()->Key(), 5);
}

TEST(TreeTest, RedBlackRotateRight) {
  Tree tree;
  tree.Insert(5, 0);
  ASSERT_EQ(tree.Root()->Key(), 5);
  tree.Insert(4, 0);
  ASSERT_EQ(tree.Root()->Left()->Key(), 4);
  tree.Insert(3, 0);
  ASSERT_EQ(tree.Root()->Key(), 4);
  ASSERT_EQ(tree.Root()->Left()->Key(), 3);
  tree.Insert(2, 0);
  ASSERT_EQ(tree.Root()->Left()->Left()->Key(), 2);
  tree.Insert(1, 0);
  ASSERT_EQ(tree.Root()->Left()->Left()->Key(), 1);
}
