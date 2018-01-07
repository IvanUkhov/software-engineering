#include <sstream>

#include "gtest/gtest.h"
#include "problem/last_lines.h"

static const std::size_t kLast = 3;
static const std::size_t kTotal = 10;

std::string Enumerate(std::size_t begin, std::size_t end) {
  std::stringstream output;
  for (std::size_t i = begin; i < end; ++i) output << i << '\n';
  return output.str();
}

TEST(ProblemTest, LastLinesWithFinalNewLine) {
  std::stringstream input(Enumerate(0, kTotal)), output;
  problem::LastLines(kLast, input, output);
  ASSERT_EQ(output.str(), Enumerate(kTotal - kLast, kTotal));
}

TEST(ProblemTest, LastLinesWithoutFinalNewLine) {
  std::stringstream input(Enumerate(0, kTotal)), output;
  input.str(input.str().substr(0, static_cast<std::size_t>(input.tellp()) - 1));
  problem::LastLines(kLast, input, output);
  ASSERT_EQ(output.str(), Enumerate(kTotal - kLast, kTotal));
}

TEST(ProblemTest, LastLinesTooFew) {
  std::stringstream input(Enumerate(0, kTotal)), output;
  problem::LastLines(2 * kTotal, input, output);
  ASSERT_EQ(output.str(), Enumerate(0, kTotal));
}
