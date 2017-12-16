#include <numeric>

#include "gtest/gtest.h"
#include "problem/minimal_tree.h"

const std::size_t kCount = 20;

template <typename T>
std::size_t Depth(const T* node) {
  if (!node) return 0;
  std::size_t left = Depth(node->Left());
  std::size_t right = Depth(node->Right());
  return 1 + ((left < right) ? right : left);
}

std::size_t MinimalDepth(std::size_t size) {
  std::size_t depth = 0;
  while (size > 0) {
    size >>= 1;
    ++depth;
  }
  return depth;
}

TEST(ProblemTest, MinimalDepth) {
  ASSERT_EQ(MinimalDepth(0), 0);
  ASSERT_EQ(MinimalDepth(1), 1);
  ASSERT_EQ(MinimalDepth(2), 2);
  ASSERT_EQ(MinimalDepth(3), 2);
  ASSERT_EQ(MinimalDepth(7), 3);
  ASSERT_EQ(MinimalDepth(8), 4);
}

TEST(ProblemTest, MinimalTree) {
  for (std::size_t i = 0; i < kCount; ++i) {
    std::vector<int> data(i);
    std::iota(data.begin(), data.end(), 0);
    auto tree = problem::MinimalTree(data);
    ASSERT_EQ(Depth(tree.Root()), MinimalDepth(data.size()));
  }
}
