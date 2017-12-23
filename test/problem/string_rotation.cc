#include "gtest/gtest.h"
#include "problem/string_rotation.h"

TEST(ProblemTest, StringRotation) {
  ASSERT_TRUE(problem::StringRotation("waterbottle", "erbottlewat"));
}
