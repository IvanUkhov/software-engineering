#include "gtest/gtest.h"
#include "structure/tree/red_black.h"

typedef structure::tree::RedBlack<int> Tree;

void Populate(Tree& tree) {
  for (auto i : {1, 6, 8, 11, 13, 15, 17, 22, 25, 27}) {
    tree.Insert(i);
  }
}

TEST(TreeTest, RedBlackInsert) {
  Tree tree;
  Populate(tree);
}
