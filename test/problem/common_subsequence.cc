#include "gtest/gtest.h"
#include "problem/common_subsequence.h"

TEST(ProblemTest, CommonSubsequence) {
  {
    std::vector<int> one = {0, 1, 2, 3, 4};
    std::vector<int> other = {5, 6, 7, 8, 9};
    ASSERT_EQ(problem::CommonSubsequence(one, other), std::make_pair(-1, -1));
  }
  {
    std::vector<int> one = {0, 1, 2, 3, 4};
    std::vector<int> other = {5, 2, 6, 7, 8, 9};
    ASSERT_EQ(problem::CommonSubsequence(one, other), std::make_pair(2, 1));
  }
  {
    std::vector<int> one = {0, 1, 2, 3, 1, 2, 1, 2, 1, 2, 1, 3, 1, 2};
    std::vector<int> other = {1, 2, 4, 1, 2, 1, 2, 1, 2, 1, 4, 3, 1, 2, 3};
    ASSERT_EQ(problem::CommonSubsequence(one, other), std::make_pair(4, 3));
  }
}
