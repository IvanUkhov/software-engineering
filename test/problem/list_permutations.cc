#include <sstream>

#include "gtest/gtest.h"
#include "problem/list_permutations.h"

TEST(ProblemTest, ListPermutations) {
  std::stringstream actual;
  problem::ListPermutations("abc", actual);
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
