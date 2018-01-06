#include "gtest/gtest.h"
#include "problem/hanoi_towers.h"

using problem::Stack;

static const std::size_t kCount = 10;

TEST(ProblemTest, HanoiTowers) {
  Stack a;
  for (std::size_t i = 0; i < kCount; ++i) a.Push(kCount - 1);
  Stack b, c;
  problem::HanoiTowers(kCount, a, b, c);
  ASSERT_TRUE(a.IsEmpty());
  ASSERT_TRUE(b.IsEmpty());
  for (std::size_t i = 0; i < kCount; ++i) ASSERT_EQ(c.Pop(), i + 1);
  ASSERT_TRUE(c.IsEmpty());
}
