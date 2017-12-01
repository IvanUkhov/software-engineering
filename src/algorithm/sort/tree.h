#ifndef ALGORITHM_SORT_TREE_H_
#define ALGORITHM_SORT_TREE_H_

#include <vector>

#include "structure/tree/search/binary.h"

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
using Tree = structure::tree::search::Binary<T, bool>;

template <typename T>
class Visitor {
 public:
   Visitor(std::vector<T>& data) : data_(data) {
     data_.resize(0);
   }

   void Visit(typename Tree<T>::Node* node) {
     data_.push_back(node->key);
   }

 private:
   std::vector<T>& data_;
};

} // namespace internal

template <typename T>
void BinaryTree(std::vector<T>& data) {
  internal::Tree<T> tree;
  for (auto key : data) tree.Insert(key, false);
  internal::Visitor<T> visitor(data);
  tree.Accept(visitor);
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_TREE_H_
