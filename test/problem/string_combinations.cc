#include <sstream>

#include "gtest/gtest.h"
#include "problem/string_combinations.h"

TEST(ProblemTest, StringCombinations) {
  std::stringstream actual;
  problem::StringCombinations("abc", actual);
  const std::string expected = R"(
a
ab
abc
ac
b
bc
c
)";
  ASSERT_EQ(actual.str(), expected.substr(1));
}
