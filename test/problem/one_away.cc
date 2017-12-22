#include "gtest/gtest.h"
#include "problem/one_away.h"

TEST(ProblemTest, OneAway) {
  ASSERT_TRUE(problem::OneAway("pale", "ple"));
  ASSERT_TRUE(problem::OneAway("pales", "pale"));
  ASSERT_TRUE(problem::OneAway("pale", "bale"));
  ASSERT_FALSE(problem::OneAway("pale", "bake"));
}
