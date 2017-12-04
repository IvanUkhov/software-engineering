#include <fstream>

#include "gtest/gtest.h"
#include "problem/solve_cubes.h"

TEST(DISABLED_ProblemTest, SolveCubes) {
  std::ofstream output("/dev/null");
  ASSERT_EQ(problem::SolveCubes(output), 2011808);
}
