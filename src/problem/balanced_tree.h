#ifndef PROBLEM_BALANCED_TREE_H_
#define PROBLEM_BALANCED_TREE_H_

#include <algorithm>

namespace problem {

namespace internal {

const int kAbort = -1;
const int kDifference = 1;

template <typename T>
int BalancedTree(const T* node) {
  if (!node) return 0;
  int left = BalancedTree(node->Left());
  if (left == kAbort) return kAbort;
  int right = BalancedTree(node->Right());
  if (right == kAbort) return kAbort;
  if (left > right) return (left - right > kDifference) ? kAbort : left + 1;
  else return (right - left > kDifference) ? kAbort : right + 1;
}

} // namespace internal

// Implement a function to check if a binary tree is balanced. For the purposes
// of this question, a balanced tree is defined to be a tree such that the
// heights of the two subtrees of any node never differ by more than one.
template <typename T>
bool BalancedTree(const T& tree) {
  return internal::BalancedTree(tree.Root()) != internal::kAbort;
}

} // namespace problem

#endif // PROBLEM_BALANCED_TREE_H_
