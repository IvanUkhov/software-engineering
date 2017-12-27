#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "problem/stack_sort.h"

const std::size_t kCount = 100;

using Stack = structure::stack::List<int>;

TEST(ProblemTest, StackSort) {
  const auto data = fixture::Generate<int>(kCount);
  auto expected = data;
  std::sort(expected.begin(), expected.end());
  Stack stack;
  std::vector<int> actual;
  for (auto value : data) stack.Push(value);
  problem::StackSort<int>(stack);
  while (!stack.IsEmpty()) actual.push_back(stack.Pop());
  ASSERT_EQ(actual, expected);
}
