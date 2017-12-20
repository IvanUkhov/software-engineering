#include "gtest/gtest.h"
#include "structure/stack/array.h"

const std::size_t kCount = 100;

using Stack = structure::stack::Array<int>;

TEST(StackTest, ArrayPushPop) {
  Stack stack;
  for (int i = 0; i < kCount; ++i) {
    stack.Push(i);
  }
  ASSERT_EQ(stack.Peek(), kCount - 1);
  for (int i = kCount - 1; i >= 0; --i) {
    ASSERT_EQ(stack.Pop(), i);
  }
  ASSERT_TRUE(stack.IsEmpty());
}
