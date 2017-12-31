#ifndef ALGORITHM_SORT_TREE_H_
#define ALGORITHM_SORT_TREE_H_

#include <vector>

#include "structure/tree/search.h"

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
using Tree = structure::tree::BinarySearch<T>;

template <typename T>
class Visitor {
 public:
  Visitor(std::vector<T>& data) : data_(data) {}

  bool Visit(const typename Tree<T>::Node* node) {
    data_.push_back(node->Value());
    return true;
  }

 private:
  std::vector<T>& data_;
};

} // namespace internal

template <typename T>
void BinaryTree(std::vector<T>& data) {
  if (data.empty()) return;
  internal::Tree<T> tree;
  for (auto value : data) tree.Insert(value);
  data.resize(0);
  internal::Visitor<T> visitor(data);
  tree.Root()->Accept(visitor);
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_TREE_H_
