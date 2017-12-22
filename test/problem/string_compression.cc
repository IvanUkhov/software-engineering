#include "gtest/gtest.h"
#include "problem/string_compression.h"

TEST(ProblemTest, StringCompression) {
  auto actual = problem::StringCompression("aabcccccaaa");
  const std::string expected = "a2b1c5a3";
  ASSERT_EQ(actual, expected);
}
