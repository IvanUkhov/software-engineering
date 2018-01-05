#include "fixture.h"
#include "gtest/gtest.h"
#include "problem/string_permutations.h"

TEST(ProblemTest, StringPermutationsUniqueChars) {
  std::stringstream buffer;
  problem::StringPermutationsUniqueChars("abc", buffer);
  std::string actual = fixture::Sort(buffer.str());
  std::string expected = fixture::Clean(R"(
abc
acb
bac
bca
cab
cba
)");
  ASSERT_EQ(actual, expected);
}

TEST(ProblemTest, StringPermutationsNonuniqueChars) {
}
