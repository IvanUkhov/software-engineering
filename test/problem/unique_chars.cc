#include "gtest/gtest.h"
#include "problem/unique_chars.h"

TEST(ProblemTest, UniqueChars) {
  ASSERT_TRUE(problem::UniqueChars("abcde"));
  ASSERT_FALSE(problem::UniqueChars("abcdea"));
}
