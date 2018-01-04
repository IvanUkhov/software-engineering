#include "gtest/gtest.h"
#include "problem/magic_index.h"

TEST(ProblemTest, MagicIndex) {
  ASSERT_EQ(problem::MagicIndex({1, 2, 5, 9, 10}), -1);
  ASSERT_EQ(problem::MagicIndex({-5, -1, 1, 3, 9, 10}), 3);
}
