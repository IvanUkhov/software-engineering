#include "gtest/gtest.h"
#include "problem/zero_matrix.h"

TEST(ProblemTest, ZeroMatrix) {
  std::vector<int> actual = {
    1, 1, 1, 1, 1, 1, 1, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
  };
  const std::vector<int> expected = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 1, 1, 0, 1, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 1, 1, 0, 1, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  };
  problem::ZeroMatrix(actual, 5, 10);
  ASSERT_EQ(actual, expected);
}
