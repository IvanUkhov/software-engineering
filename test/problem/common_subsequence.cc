#include "gtest/gtest.h"
#include "problem/common_subsequence.h"

TEST(ProblemTest, CommonSubsequence) {
  const std::string one = "AAACCGTGAGTTATTCGTTCTAGAA";
  const std::string other = "CACCCCTAAGGTACCTTTGGTTC";
  const std::string expected = "ACCTGGTTTTGTTC";
  ASSERT_EQ(problem::CommonSubsequence(one, other), expected);
}
