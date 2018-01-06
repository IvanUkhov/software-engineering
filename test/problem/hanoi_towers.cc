#include <vector>

#include "gtest/gtest.h"
#include "problem/hanoi_towers.h"

using problem::Stack;
using Vector = std::vector<std::size_t>;

static Vector Drain(Stack& stack) {
  Vector vector;
  while (!stack.IsEmpty()) vector.push_back(stack.Pop());
  return vector;
}

void Assess(std::size_t count) {
  Stack a, b, c;
  Vector expected;
  for (std::size_t i = 0; i < count; ++i) {
    a.Push(count - i);
    expected.push_back(i + 1);
  }
  problem::HanoiTowers(a, b, c);
  ASSERT_EQ(Drain(a), Vector());
  ASSERT_EQ(Drain(b), Vector());
  ASSERT_EQ(Drain(c), expected);
}

TEST(ProblemTest, HanoiTowers) {
  Assess(10);
  Assess(11);
}
