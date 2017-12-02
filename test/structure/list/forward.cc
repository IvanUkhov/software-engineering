#include "gtest/gtest.h"
#include "structure/list/forward.h"

typedef structure::list::Forward<int> Node;;

std::vector<int> Collect(Node& node);

TEST(ListTest, ForwardAppend) {
  Node root(1);
  root.Append(2).Append(3).Append(4).Append(5);
  ASSERT_EQ(Collect(root), std::vector<int>({1, 2, 3, 4, 5}));
}

std::vector<int> Collect(Node& root) {
  std::vector<int> data;
  for (Node& node : root) data.push_back(node.value());
  return data;
}
