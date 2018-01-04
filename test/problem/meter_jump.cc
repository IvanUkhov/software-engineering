#include "gtest/gtest.h"
#include "problem/meter_jump.h"

TEST(ProblemTest, MeterJump) {
  ASSERT_EQ(problem::MeterJump(0), 1);
  ASSERT_EQ(problem::MeterJump(1), 1);
  ASSERT_EQ(problem::MeterJump(2), 2);
  ASSERT_EQ(problem::MeterJump(3), 4);
  ASSERT_EQ(problem::MeterJump(4), 8);
  ASSERT_EQ(problem::MeterJump(5), 16);
  ASSERT_EQ(problem::MeterJump(6), 31);
  ASSERT_EQ(problem::MeterJump(7), 61);
}
