#include "gtest/gtest.h"
#include "structure/tree/search/binary.h"

TEST(BinaryTest, Query) {
  Binary *tree = new Binary();
  ASSERT_TRUE(tree->Query());
}
