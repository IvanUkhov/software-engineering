#include "gtest/gtest.h"
#include "structure/tree/search/binary.h"

using namespace structure::tree::search;

typedef Binary<int, const char*> Tree;

Tree Create();

TEST(TreeTest, BinaryInsert) {
  auto tree = Create();
  ASSERT_EQ(tree.root()->right()->right()->left()->key(), 13);
}

Tree Create() {
  Tree tree;
  tree.Insert(8, "a");
  tree.Insert(3, "b");
  tree.Insert(1, "c");
  tree.Insert(6, "d");
  tree.Insert(4, "e");
  tree.Insert(7, "f");
  tree.Insert(10, "g");
  tree.Insert(14, "h");
  tree.Insert(13, "i");
  return tree;
}
