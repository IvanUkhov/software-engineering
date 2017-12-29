#include "gtest/gtest.h"
#include "structure/tree/bayer.h"

using Tree = structure::tree::Bayer<int, 1>;

TEST(TreeTest, Bayer) {
  Tree tree;
  for (int i = 1; i <= 7; ++i) tree.Insert(i);
}
