#ifndef STRUCTURE_TREE_SEARCH_H_
#define STRUCTURE_TREE_SEARCH_H_

#include <memory>
#include <utility>

namespace structure { namespace tree {

template <typename T>
class BinarySearch {
 public:
  class Node;

  Node* Root() const {
    return root_.get();
  }

  BinarySearch& Insert(std::unique_ptr<Node> node);

  BinarySearch& Insert(T value) {
    return Insert(std::unique_ptr<Node>(new Node(std::move(value))));
  }

  Node* Search(const T& value) const;

 private:
  std::unique_ptr<Node> root_;
};

template <typename T>
class BinarySearch<T>::Node {
  friend class BinarySearch;

 public:
  const T& Value() const {
    return value_;
  }

  Node* Left() const {
    return left_.get();
  }

  Node* Right() const {
    return right_.get();
  }

  template <typename U>
  bool Accept(U& visitor) const;

 private:
  Node(T value) : value_(std::move(value)) {}

  T value_;
  std::unique_ptr<Node> left_;
  std::unique_ptr<Node> right_;
};

template <typename T>
BinarySearch<T>& BinarySearch<T>::Insert(std::unique_ptr<Node> node) {
  auto* target = &root_;
  while (*target) {
    auto parent = target->get();
    if (parent->value_ < node->value_) target = &parent->right_;
    else target = &parent->left_;
  }
  *target = std::move(node);
  return *this;
}

template <typename T>
typename BinarySearch<T>::Node* BinarySearch<T>::Search(const T& value) const {
  auto current = this->root_.get();
  while (current) {
    if (value < current->value_) current = current->Left();
    else if (current->value_ < value) current = current->Right();
    else return current;
  }
  return nullptr;
}

template <typename T>
template <typename U>
bool BinarySearch<T>::Node::Accept(U& visitor) const {
  if (left_ && !left_->Accept(visitor)) return false;
  if (!visitor.Visit(this)) return false;
  if (right_ && !right_->Accept(visitor)) return false;
  return true;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_SEARCH_H_
