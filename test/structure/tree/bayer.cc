#include "gtest/gtest.h"
#include "structure/tree/bayer.h"

using Tree = structure::tree::Bayer<int, 2>;

TEST(TreeTest, Bayer) {
  Tree tree;
  auto location1 = tree.Insert(42);
  auto location2 = tree.Search(42);
  ASSERT_EQ(location1, location2);
}
