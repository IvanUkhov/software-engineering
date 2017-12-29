#include <vector>

#include "gtest/gtest.h"
#include "structure/tree/bayer.h"

using Tree = structure::tree::Bayer<int, 1>;

void Collect(Tree::Node& node, std::size_t depth, std::vector<int>& output) {
  if (depth > 0) {
    for (auto& child : node.Children()) {
      if (child) Collect(*child, depth - 1, output);
    }
  } else {
    for (auto& key : node.Keys()) {
      output.push_back(key);
    }
  }
}

std::vector<int> Collect(Tree& tree, std::size_t depth) {
  std::vector<int> result;
  Collect(tree.Root(), depth, result);
  return result;
}

TEST(TreeTest, Bayer) {
  Tree tree;
  for (int i = 1; i <= 7; ++i) tree.Insert(i);
  ASSERT_EQ(Collect(tree, 0), std::vector<int>({4, 0}));
  ASSERT_EQ(Collect(tree, 1), std::vector<int>({2, 0, 6, 0}));
  ASSERT_EQ(Collect(tree, 2), std::vector<int>({1, 0, 3, 0, 5, 0, 7, 0}));
}
