#include "algorithm/sort/tree.h"
#include "assess.h"

TEST(SortTest, BinaryTree) {
  assess::Sort<int>(algorithm::sort::BinaryTree<int>);
}
