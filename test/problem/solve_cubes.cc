#include <fstream>

#include "gtest/gtest.h"
#include "problem/solve_cubes.h"

TEST(DISABLED_ProblemTest, SolveCubes) {
  std::ofstream output("/dev/null");
  ASSERT_EQ(problem::SolveCubes(1, 1000, output), 2011808);
}
