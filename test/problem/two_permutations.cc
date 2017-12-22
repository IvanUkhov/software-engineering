#include "gtest/gtest.h"
#include "problem/two_permutations.h"

TEST(ProblemTest, TwoPermutations) {
  ASSERT_TRUE(problem::TwoPermutations("abc", "cba"));
  ASSERT_FALSE(problem::TwoPermutations("abc", "abd"));
}
