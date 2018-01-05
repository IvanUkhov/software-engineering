#include "fixture.h"
#include "gtest/gtest.h"
#include "problem/string_combinations.h"

TEST(ProblemTest, StringCombinations) {
  std::stringstream output;
  problem::StringCombinations("abc", output);
  std::string actual = fixture::Sort(output.str());
  std::string expected = fixture::Clean(R"(
a
ab
abc
ac
b
bc
c
)");
  ASSERT_EQ(actual, expected);
}
