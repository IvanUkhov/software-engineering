#include "gtest/gtest.h"
#include "problem/bit_insertion.h"

TEST(ProblemTest, BitInsertion) {
  ASSERT_EQ(problem::BitInsertion(0b0100'0000'0000, 0b0000'0001'0011, 2, 6),
            0b0100'0100'1100);
  ASSERT_EQ(problem::BitInsertion(0b0100'0111'1100, 0b0000'0001'0011, 2, 6),
            0b0100'0100'1100);
  ASSERT_EQ(problem::BitInsertion(0b0100'0000'0000, 0b0000'0001'0011, 0, 4),
            0b0100'0001'0011);
}
