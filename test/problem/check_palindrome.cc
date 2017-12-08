#include "gtest/gtest.h"
#include "problem/check_palindrome.h"

TEST(ProblemTest, CheckPalindrome) {
  ASSERT_TRUE(problem::CheckPalindrome("Tact Coa"));
}
