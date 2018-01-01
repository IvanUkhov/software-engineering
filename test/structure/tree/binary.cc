#include <vector>

#include "gtest/gtest.h"
#include "structure/tree/binary.h"

using Tree = structure::tree::Binary<int>;
using Node = Tree::Node;

struct Visitor {
  bool Visit(const Node& node) {
    data.push_back(node.Value());
    return true;
  }

  std::vector<int> data;
};

namespace {

Tree Create() {
  Tree tree;
  tree.Root() = std::make_unique<Node>(1);
  tree.Root()->Left() = std::make_unique<Node>(2);
  tree.Root()->Right() = std::make_unique<Node>(3);
  return tree;
}

} // namespace

TEST(TreeTest, BinaryAccept) {
  Visitor visitor;
  Create().Root()->Accept(visitor);
  ASSERT_EQ(visitor.data, std::vector<int>({2, 1, 3}));
}
