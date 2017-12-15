#include "gtest/gtest.h"
#include "problem/factorial_zeros.h"

TEST(ProblemTest, FactorialZeros) {
  ASSERT_EQ(problem::FactorialZeros(19), 3);
}
