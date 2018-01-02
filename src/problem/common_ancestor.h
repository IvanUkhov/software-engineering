#ifndef PROBLEM_COMMON_ANCESTOR_H_
#define PROBLEM_COMMON_ANCESTOR_H_

namespace problem {

namespace internal {

template <typename T>
const T* CommonAncestor(const T* root, const T* one, const T* other) {
  if (!root || root == one || root == other) return root;
  auto left = CommonAncestor(root->Left().get(), one, other);
  auto right = CommonAncestor(root->Right().get(), one, other);
  if (left && right) return root;
  return left ? left : right;
}

} // namespace internal

// Design an algorithm and write code to find the first common ancestor of two
// nodes in a binary tree. Avoid storing additional nodes in a data structure.
// Note: This is not necessarily a binary search tree.
template <typename T>
const T* CommonAncestor(const T& root, const T& one, const T& other) {
  return internal::CommonAncestor(&root, &one, &other);
}

}

#endif // PROBLEM_COMMON_ANCESTOR_H_
