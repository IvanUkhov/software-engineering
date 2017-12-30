#include <unordered_map>
#include <vector>

#include "gtest/gtest.h"
#include "structure/tree/bayer.h"

using Tree = structure::tree::Bayer<int, 1>;
using Map = std::unordered_map<std::size_t, std::vector<int>>;

void Collect(Tree::Node& node, std::size_t depth, Map& keys) {
  for (auto& key : node.Keys()) {
    if (!key) break;
    keys[depth].push_back(key);
  }
  for (auto& child : node.Children()) {
    if (!child) break;
    Collect(*child, depth + 1, keys);
  }
}

TEST(TreeTest, Bayer) {
  Map keys;
  Tree tree;
  for (int i = 1; i <= 7; ++i) tree.Insert(i);
  Collect(tree.Root(), 0, keys);
  ASSERT_EQ(keys.size(), 3);
  ASSERT_EQ(keys[0], std::vector<int>({4}));
  ASSERT_EQ(keys[1], std::vector<int>({2, 6}));
  ASSERT_EQ(keys[2], std::vector<int>({1, 3, 5, 7}));
}
