#include "gtest/gtest.h"
#include "problem/build_order.h"

TEST(ProblemTest, BuildOrder) {
  auto actual = problem::BuildOrder(
      {0, 1, 2, 3, 4, 5}, {{0, 3}, {1, 3}, {3, 2}, {5, 0}, {5, 1}});
  std::vector<std::size_t> expected = {4, 5, 0, 1, 3, 2};
  ASSERT_EQ(actual, expected);
}
