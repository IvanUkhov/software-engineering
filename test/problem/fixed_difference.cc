#include <algorithm>

#include "gtest/gtest.h"
#include "problem/fixed_difference.h"

TEST(ProblemTest, FixedDifference) {
  const std::vector<std::pair<int, int>> expected = {{1, 3}, {3, 5}, {5, 7}, {7, 9}};
  auto actual = problem::FixedDifference({1, 7, 5, 9, 2, 12, 3}, 2);
  std::sort(actual.begin(), actual.end());
  ASSERT_EQ(actual, expected);
}
