#include "fixture.h"
#include "gtest/gtest.h"
#include "problem/string_combinations.h"

TEST(ProblemTest, StringCombinations) {
  std::stringstream buffer;
  problem::StringCombinations("abc", buffer);
  std::string actual = fixture::Sort(buffer.str());
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
