#include <cstddef>

#include "gtest/gtest.h"
#include "structure/list/forward.h"

const std::size_t kCount = 1 << 20;

typedef structure::list::Forward<int> Node;

std::vector<int> Collect(Node& root) {
  std::vector<int> data;
  for (Node& node : root) data.push_back(node.value());
  return data;
}

TEST(ListTest, ForwardAppend) {
  Node root(1);
  root.Append(2).Append(3).Append(4).Append(5);
  ASSERT_EQ(Collect(root), std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(DISABLED_ListTest, ForwardPrune) {
  Node root(0);
  Node* current = &root;
  for (std::size_t i = 1; i < kCount; ++i) {
    current = &current->Append(0);
  }
  root.Prune();
}
