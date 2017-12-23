#include "gtest/gtest.h"
#include "problem/list_tail.h"
#include "structure/list/assess.h"

using Node = structure::list::Forward<int>;

TEST(ProblemTest, ListTail) {
  Node head(0);
  head.InsertAfter(1)
      .InsertAfter(2)
      .InsertAfter(3)
      .InsertAfter(4)
      .InsertAfter(5)
      .InsertAfter(6)
      .InsertAfter(7)
      .InsertAfter(8)
      .InsertAfter(9);
  ASSERT_EQ(problem::ListTail(head, 3)->Value(), 6);
}
