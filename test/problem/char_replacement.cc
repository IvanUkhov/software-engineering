#include "gtest/gtest.h"
#include "problem/char_replacement.h"

TEST(ProblemTest, CharReplacement) {
  std::string actual = "Mr John Smith      ";
  problem::CharReplacement(actual, 13);
  std::string expected = R"(Mr%20John%20Smith  )";
  ASSERT_EQ(actual, expected);
}
