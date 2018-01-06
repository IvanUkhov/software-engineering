#include "gtest/gtest.h"
#include "problem/triple_step.h"

TEST(ProblemTest, TripleStep) {
  ASSERT_EQ(problem::TripleStep(0), 1);
  ASSERT_EQ(problem::TripleStep(1), 1);
  ASSERT_EQ(problem::TripleStep(2), 2);
  ASSERT_EQ(problem::TripleStep(3), 4);
  ASSERT_EQ(problem::TripleStep(4), 7);
  ASSERT_EQ(problem::TripleStep(5), 13);
  ASSERT_EQ(problem::TripleStep(6), 24);
  ASSERT_EQ(problem::TripleStep(7), 44);
}
