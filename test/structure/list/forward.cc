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

TEST(ListTest, ForwardInsertAfter) {
  Node head(1);
  head.InsertAfter(2).InsertAfter(3).InsertAfter(4).InsertAfter(5);
  ASSERT_EQ(Collect(head), std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(ListTest, ForwardPushBack) {
  Node head1(1);
  auto& tail1 = head1.InsertAfter(2).InsertAfter(3);
  auto head2 = std::unique_ptr<Node>(new Node(4));
  head2->InsertAfter(5).InsertAfter(6);
  tail1.InsertAfter(std::move(head2)).PushBack(7);
  ASSERT_EQ(Collect(head1), std::vector<int>({1, 2, 3, 4, 5, 6, 7}));
}

TEST(DISABLED_ListTest, ForwardPrune) {
  Node head(0);
  Node* current = &head;
  for (std::size_t i = 1; i < kCount; ++i) {
    current = &current->InsertAfter(0);
  }
  head.Prune();
}
