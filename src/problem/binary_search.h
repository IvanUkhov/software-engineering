#ifndef PROBLEM_BINARY_SEARCH_H_
#define PROBLEM_BINARY_SEARCH_H_

namespace problem {

namespace internal {

template <typename T, typename U>
bool BinarySearch(const U& node, const T* minimum, const T* maximum) {
  if (!node) return true;
  if (minimum && node->Value() <= *minimum) return false;
  if (maximum && node->Value() > *maximum) return false;
  return BinarySearch(node->Left(), minimum, &node->Value()) &&
         BinarySearch(node->Right(), &node->Value(), maximum);
}

} // namespace internal

// Implement a function to check if a binary tree is a binary search tree.
template <typename T, typename U>
bool BinarySearch(const U& tree) {
  return internal::BinarySearch<T>(tree.Root(), nullptr, nullptr);
}

}

#endif // PROBLEM_BINARY_SEARCH_H_
