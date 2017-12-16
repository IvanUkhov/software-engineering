#include <cstddef>

#include "problem/minimal_tree.h"

namespace problem {

namespace internal {

void Insert(Tree& tree, const std::vector<int>& data,
            std::size_t begin, std::size_t end) {
  if (begin < end) {
    auto i = (begin + end) / 2;
    tree.Insert(data[i]);
    Insert(tree, data, begin, i);
    Insert(tree, data, i + 1, end);
  }
}

} // namespace internal

Tree MinimalTree(const std::vector<int>& data) {
  Tree tree;
  internal::Insert(tree, data, 0, data.size());
  return tree;
}

} // namespace problem
