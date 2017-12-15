#include <fstream>

#include "gtest/gtest.h"
#include "problem/four_cubes.h"

TEST(DISABLED_ProblemTest, FourCubes) {
  std::ofstream output("/dev/null");
  ASSERT_EQ(problem::FourCubes(1, 1000, output), 2011808);
}
