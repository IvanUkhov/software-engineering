#include "gtest/gtest.h"
#include "structure/stack/array.h"

const std::size_t kCount = 100;

typedef structure::stack::Array<int> Stack;

TEST(StackTest, ArrayPushPop) {
  Stack stack;
  for (int i = 0; i < kCount; ++i) {
    stack.Push(i);
  }
  ASSERT_EQ(stack.Size(), kCount);
  for (int i = kCount - 1; i >= 0; --i) {
    ASSERT_EQ(stack.Pop(), i);
  }
  ASSERT_EQ(stack.Size(), 0);
}
