#include <sstream>

#include "gtest/gtest.h"
#include "problem/eight_queens.h"

TEST(ProblemTest, EightQueens) {
  std::stringstream output;
  problem::EightQueens(output);
}
