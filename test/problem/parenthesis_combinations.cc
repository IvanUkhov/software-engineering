#include "fixture.h"
#include "gtest/gtest.h"
#include "problem/parenthesis_combinations.h"

TEST(ProblemTest, ParenthesisCombinations) {
  std::stringstream buffer;
  problem::ParenthesisCombinations(3, buffer);
  std::string actual = fixture::Sort(buffer.str());
  std::string expected = fixture::Clean(R"(
((()))
(()())
(())()
()(())
()()()
)");
  ASSERT_EQ(actual, expected);
}
