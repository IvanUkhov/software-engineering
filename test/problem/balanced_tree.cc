#include "gtest/gtest.h"
#include "problem/balanced_tree.h"
#include "structure/tree/search.h"

using Tree = structure::tree::BinarySearch<int>;

TEST(ProblemTest, BalancedTree) {
  {
    Tree tree;
    tree.Insert(8)
        .Insert(3)
        .Insert(1)
        .Insert(6)
        .Insert(4)
        .Insert(7)
        .Insert(10)
        .Insert(14)
        .Insert(13);
    ASSERT_FALSE(problem::BalancedTree(tree));
  }
  {
    Tree tree;
    tree.Insert(8)
        .Insert(3)
        .Insert(1)
        .Insert(6)
        .Insert(4)
        .Insert(7)
        .Insert(10)
        .Insert(9);
    ASSERT_TRUE(problem::BalancedTree(tree));
  }
}
