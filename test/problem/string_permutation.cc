#include <sstream>

#include "gtest/gtest.h"
#include "problem/string_permutation.h"

TEST(ProblemTest, StringPermutation) {
  std::stringstream actual;
  problem::StringPermutation("abc", actual);
  const std::string expected = R"(
abc
acb
bac
bca
cba
cab
)";
  ASSERT_EQ(actual.str(), expected.substr(1));
}
