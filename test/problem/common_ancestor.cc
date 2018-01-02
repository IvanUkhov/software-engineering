#include "gtest/gtest.h"
#include "problem/common_ancestor.h"
#include "structure/tree/search.h"

using Tree = structure::tree::BinarySearch<int>;

TEST(ProblemTest, CommonAncestor) {
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
  auto& root = *tree.Root();
  auto& one = *tree.Search(1);
  auto& three = *tree.Search(3);
  auto& seven = *tree.Search(7);
  ASSERT_EQ(*problem::CommonAncestor(root, one, seven), three);
  ASSERT_EQ(*problem::CommonAncestor(root, three, seven), three);
}
