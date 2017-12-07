#include "gtest/gtest.h"
#include "structure/tree/red_black.h"

typedef structure::tree::RedBlack<int, int> Tree;

TEST(TreeTest, RedBlackInsert) {
  Tree tree;
  tree.Insert(1, 1);
  ASSERT_EQ(tree.Root()->Value(), 1);
  tree.Insert(6, 6);
  ASSERT_EQ(tree.Root()->Right()->Value(), 6);
  tree.Insert(8, 8);
  ASSERT_EQ(tree.Root()->Right()->Value(), 8);
  tree.Insert(11, 11);
  ASSERT_EQ(tree.Root()->Right()->Right()->Value(), 11);
  tree.Insert(13, 13);
  ASSERT_EQ(tree.Root()->Right()->Right()->Value(), 13);
  tree.Insert(15, 15);
  ASSERT_EQ(tree.Root()->Right()->Right()->Right()->Value(), 15);
  tree.Insert(17, 17);
  ASSERT_EQ(tree.Root()->Right()->Right()->Right()->Value(), 17);
  tree.Insert(22, 22);
  ASSERT_EQ(tree.Root()->Value(), 11);
  ASSERT_EQ(tree.Root()->Right()->Right()->Right()->Value(), 22);
  tree.Insert(25, 25);
  ASSERT_EQ(tree.Root()->Right()->Right()->Right()->Value(), 25);
  tree.Insert(27, 27);
  ASSERT_EQ(tree.Root()->Right()->Right()->Right()->Right()->Value(), 27);
}
