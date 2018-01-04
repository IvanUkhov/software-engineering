#include "gtest/gtest.h"
#include "problem/power_set.h"

TEST(ProblemTest, PowerSet) {
  auto actual = problem::PowerSet<int>({1, 2, 3});
  std::vector<std::unordered_set<int>> expected = {
    {}, {1}, {2}, {2, 1}, {3}, {3, 1}, {3, 2}, {3, 2, 1}};
  ASSERT_EQ(actual, expected);
}
