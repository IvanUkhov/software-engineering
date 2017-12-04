#include "gtest/gtest.h"
#include "problem/count_pairs.h"

TEST(ProblemTest, CountPairs) {
  const std::vector<std::pair<int, int>> expected = {{1, 3}, {3, 5}, {5, 7}, {7, 9}};
  auto actual = problem::CountPairs({1, 7, 5, 9, 2, 12, 3}, 2);
  ASSERT_EQ(actual, expected);
}
