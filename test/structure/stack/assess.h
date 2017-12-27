#ifndef ALGORITHM_SORT_ASSESS_H_
#define ALGORITHM_SORT_ASSESS_H_

#include "gtest/gtest.h"

namespace structure { namespace stack {

const std::size_t kCount = 100;

template <typename T>
void Assess() {
  T stack;
  for (int i = 0; i < kCount; ++i) stack.Push(i);
  ASSERT_EQ(stack.Peek(), kCount - 1);
  for (int i = kCount - 1; i >= 0; --i) ASSERT_EQ(stack.Pop(), i);
  ASSERT_TRUE(stack.IsEmpty());
}

} } // namespace structure::stack

#endif // ALGORITHM_SORT_ASSESS_H_
