#include <cstddef>

#include "gtest/gtest.h"
#include "structure/list/forward.h"

const std::size_t kCount = 1 << 20;

typedef structure::list::Forward<int> Node;

std::vector<int> Collect(Node& head) {
  std::vector<int> data;
  for (Node& node : head) data.push_back(node.Value());
  return data;
}

TEST(ListTest, ForwardAppend) {
  Node head(1);
  head.Append(2).Append(3).Append(4).Append(5);
  ASSERT_EQ(Collect(head), std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(DISABLED_ListTest, ForwardPrune) {
  Node head(0);
  Node* current = &head;
  for (std::size_t i = 1; i < kCount; ++i) {
    current = &current->Append(0);
  }
  head.Prune();
}
