#ifndef PROBLEM_BINARY_SEARCH_H_
#define PROBLEM_BINARY_SEARCH_H_

#include <algorithm>
#include <limits>
#include <utility>

namespace problem {

namespace internal {

enum class Type {
  Abort,
  Empty,
  Range,
};

template <typename T>
using Range = std::pair<T, T>;

template <typename T>
using Result = std::pair<Type, Range<T>>;

template <typename T, typename U>
Result<T> BinarySearch(const U* node) {
  if (!node) return {Type::Empty, {}};
  Range<T> range = {node->Value(), node->Value()};
  {
    auto other = BinarySearch<T, U>(node->Left());
    if (other.first == Type::Abort) return other;
    else if (other.first == Type::Range) {
      if (other.second.second > node->Value()) return {Type::Abort, {}};
      range.first = std::min(range.first, other.second.first);
      range.second = std::max(range.second, other.second.second);
    }
  }
  {
    auto other = BinarySearch<T, U>(node->Right());
    if (other.first == Type::Abort) return other;
    else if (other.first == Type::Range) {
      if (other.second.first <= node->Value()) return {Type::Abort, {}};
      range.first = std::min(range.first, other.second.first);
      range.second = std::max(range.second, other.second.second);
    }
  }
  return {Type::Range, range};
}

} // namespace internal

template <typename T, typename U>
bool BinarySearch(const U& tree) {
  return internal::BinarySearch<T>(tree.Root()).first != internal::Type::Abort;
}

}

#endif // PROBLEM_BINARY_SEARCH_H_
