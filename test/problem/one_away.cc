#include "gtest/gtest.h"
#include "problem/one_away.h"

TEST(ProblemTest, OneAway) {
  ASSERT_TRUE(problem::OneAway("pale", "bale"));
  ASSERT_TRUE(problem::OneAway("pale", "pale"));
  ASSERT_TRUE(problem::OneAway("pale", "pales"));
  ASSERT_TRUE(problem::OneAway("pale", "ple"));
  ASSERT_FALSE(problem::OneAway("pale", "bake"));
  ASSERT_FALSE(problem::OneAway("pale", "paleee"));
}
