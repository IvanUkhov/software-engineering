#include <sstream>

#include "gtest/gtest.h"
#include "problem/string_combinations.h"

TEST(ProblemTest, StringCombinations) {
  std::stringstream actual;
  problem::StringCombinations("abc", actual);
  const std::string expected = R"(
a
b
c
ab
ac
bc
abc
)";
  ASSERT_EQ(actual.str(), expected.substr(1));
}
