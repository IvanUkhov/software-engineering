#include "gtest/gtest.h"
#include "structure/stack/list.h"

const std::size_t kCount = 100;

typedef structure::stack::List<int> Stack;

TEST(StackTest, ListPushPop) {
  Stack stack;
  for (int i = 0; i < kCount; ++i) {
    stack.Push(i);
  }
  for (int i = kCount - 1; i >= 0; --i) {
    ASSERT_EQ(stack.Pop(), i);
  }
  ASSERT_TRUE(stack.IsEmpty());
}
