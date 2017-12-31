#include "gtest/gtest.h"
#include "problem/binary_search.h"
#include "structure/tree/search.h"

using Tree = structure::tree::BinarySearch<const int&>;

TEST(ProblemTest, BinarySearchFailure) {
  int ten = 10;
  Tree tree;
  tree.Insert(8)
      .Insert(3)
      .Insert(1)
      .Insert(6)
      .Insert(4)
      .Insert(7)
      .Insert(ten)
      .Insert(14)
      .Insert(13);
  ten = 2;
  ASSERT_FALSE(problem::BinarySearch<int>(tree));
}

TEST(ProblemTest, BinarySearchSuccess) {
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
  ASSERT_TRUE(problem::BinarySearch<int>(tree));
}
