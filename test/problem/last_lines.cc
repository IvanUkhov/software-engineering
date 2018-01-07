#include <sstream>

#include "gtest/gtest.h"
#include "problem/last_lines.h"

static const std::size_t kCount = 10;

TEST(ProblemTest, LastLinesWithFinalNewLine) {
  std::stringstream input, output;
  for (std::size_t i = kCount; i > 0; --i) input << i << '\n';
  problem::LastLines(3, input, output);
  ASSERT_EQ(output.str(), "3\n2\n1\n");
}

TEST(ProblemTest, LastLinesWithoutFinalNewLine) {
  std::stringstream input, output;
  for (std::size_t i = kCount; i > 0; --i) input << i << '\n';
  input.str(input.str().substr(0, static_cast<std::size_t>(input.tellp()) - 1));
  problem::LastLines(3, input, output);
  ASSERT_EQ(output.str(), "3\n2\n1\n");
}

TEST(ProblemTest, LastLinesTooFew) {
  std::stringstream input, output;
  for (std::size_t i = kCount; i > 0; --i) input << i << '\n';
  problem::LastLines(2 * kCount, input, output);
  ASSERT_EQ(output.str(), "10\n9\n8\n7\n6\n5\n4\n3\n2\n1\n");
}
