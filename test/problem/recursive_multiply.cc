#include "gtest/gtest.h"
#include "problem/recursive_multiply.h"

TEST(ProblemTest, RecursiveMultiply) {
  ASSERT_EQ(problem::RecursiveMultiply(42, 69), 42 * 69);
}
