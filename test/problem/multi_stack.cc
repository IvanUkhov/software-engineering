#include "gtest/gtest.h"
#include "problem/multi_stack.h"

typedef problem::MultiStack<int> Stack;

std::vector<int> Drain(Stack& stack, std::size_t index) {
  std::vector<int> data;
  while (!stack.IsEmpty(index)) data.push_back(stack.Pop(index));
  return data;
}

TEST(ProblemTest, MultiStack) {
  Stack stack(3);
  stack.Push(1, 21);
  stack.Push(1, 22);
  stack.Push(1, 23);
  stack.Push(0, 11);
  stack.Push(0, 12);
  stack.Push(0, 13);
  ASSERT_EQ(Drain(stack, 1), std::vector<int>({23, 22, 21}));
  stack.Push(2, 31);
  stack.Push(2, 32);
  stack.Push(2, 33);
  ASSERT_EQ(Drain(stack, 0), std::vector<int>({13, 12, 11}));
  ASSERT_EQ(Drain(stack, 2), std::vector<int>({33, 32, 31}));
}
