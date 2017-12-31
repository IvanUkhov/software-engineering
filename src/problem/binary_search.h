#ifndef PROBLEM_BINARY_SEARCH_H_
#define PROBLEM_BINARY_SEARCH_H_

#include <algorithm>
#include <utility>

namespace problem {

namespace internal {

template <typename T, typename U>
std::pair<bool, std::pair<T, T>> BinarySearch(const U* node) {
  auto range = std::make_pair(node->Value(), node->Value());
  if (node->Left()) {
    auto other = BinarySearch<T, U>(node->Left());
    if (!other.first) return other;
    if (other.second.second > node->Value()) return {false, {}};
    range.first = std::min(range.first, other.second.first);
    range.second = std::max(range.second, other.second.second);
  }
  if (node->Right()) {
    auto other = BinarySearch<T, U>(node->Right());
    if (!other.first) return other;
    if (other.second.first <= node->Value()) return {false, {}};
    range.first = std::min(range.first, other.second.first);
    range.second = std::max(range.second, other.second.second);
  }
  return {true, range};
}

} // namespace internal

// Implement a function to check if a binary tree is a binary search tree.
template <typename T, typename U>
bool BinarySearch(const U& tree) {
  return !tree.Root() || internal::BinarySearch<T>(tree.Root()).first;
}

}

#endif // PROBLEM_BINARY_SEARCH_H_
