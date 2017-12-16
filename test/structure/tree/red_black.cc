#include "gtest/gtest.h"
#include "structure/tree/red_black.h"

typedef structure::tree::RedBlack<int> Tree;

TEST(TreeTest, RedBlackRotateLeft) {
  Tree tree;
  tree.Insert(1);
  ASSERT_EQ(tree.Root()->Value(), 1);
  tree.Insert(2);
  ASSERT_EQ(tree.Root()->Right()->Value(), 2);
  tree.Insert(3);
  ASSERT_EQ(tree.Root()->Value(), 2);
  ASSERT_EQ(tree.Root()->Right()->Value(), 3);
  tree.Insert(4);
  ASSERT_EQ(tree.Root()->Right()->Right()->Value(), 4);
  tree.Insert(5);
  ASSERT_EQ(tree.Root()->Right()->Right()->Value(), 5);
}

TEST(TreeTest, RedBlackRotateRight) {
  Tree tree;
  tree.Insert(5);
  ASSERT_EQ(tree.Root()->Value(), 5);
  tree.Insert(4);
  ASSERT_EQ(tree.Root()->Left()->Value(), 4);
  tree.Insert(3);
  ASSERT_EQ(tree.Root()->Value(), 4);
  ASSERT_EQ(tree.Root()->Left()->Value(), 3);
  tree.Insert(2);
  ASSERT_EQ(tree.Root()->Left()->Left()->Value(), 2);
  tree.Insert(1);
  ASSERT_EQ(tree.Root()->Left()->Left()->Value(), 1);
}
