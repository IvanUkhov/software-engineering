#include "gtest/gtest.h"
#include "problem/urlify_space.h"

TEST(ProblemTest, UrlifySpace) {
  std::string actual = "Mr John Smith    ";
  problem::UrlifySpace(actual, 13);
  std::string expected = R"(Mr%20John%20Smith)";
  ASSERT_EQ(actual, expected);
}
