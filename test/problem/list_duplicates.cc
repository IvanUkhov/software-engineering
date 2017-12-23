#include "gtest/gtest.h"
#include "problem/list_duplicates.h"
#include "structure/list/assess.h"

using Node = structure::list::Forward<int>;

TEST(ProblemTest, ListDuplicates) {
  Node head(0);
  head.InsertAfter(1)
      .InsertAfter(2)
      .InsertAfter(2)
      .InsertAfter(1)
      .InsertAfter(0)
      .InsertAfter(3)
      .InsertAfter(1);
  problem::ListDuplicates(head);
  ASSERT_EQ(structure::list::Collect(head), std::vector<int>({0, 1, 2, 3}));
}
