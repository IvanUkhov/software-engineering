#include <sstream>

#include "gtest/gtest.h"
#include "problem/string_permutations.h"

TEST(ProblemTest, StringPermutations) {
  std::stringstream actual;
  problem::StringPermutations("abc", actual);
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
