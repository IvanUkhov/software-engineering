#ifndef STRUCTURE_TREE_SEARCH_H_
#define STRUCTURE_TREE_SEARCH_H_

#include "structure/tree/binary.h"

namespace structure { namespace tree {

template <typename T>
class BinarySearch: public Binary<T> {
 public:
  using Node = typename Binary<T>::Node;

  BinarySearch& Insert(T value);

  Node* Search(const T& value) const;
};

template <typename T>
BinarySearch<T>& BinarySearch<T>::Insert(T value) {
  auto target = &this->Root();
  while (*target) {
    if ((*target)->Value() < value) target = &(*target)->Right();
    else target = &(*target)->Left();
  }
  *target = std::unique_ptr<Node>(new Node(std::move(value)));
  return *this;
}

template <typename T>
typename BinarySearch<T>::Node* BinarySearch<T>::Search(const T& value) const {
  auto current = &*this->Root();
  while (current) {
    if (value < current->Value()) current = &*current->Left();
    else if (current->Value() < value) current = &*current->Right();
    else return current;
  }
  return nullptr;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_SEARCH_H_
