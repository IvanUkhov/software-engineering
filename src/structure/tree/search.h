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

  void Insert(std::unique_ptr<Node> node);

  void Insert(T value) {
    Insert(std::unique_ptr<Node>(new Node(std::move(value))));
  }

  Node* Find(const T& value) const;

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
  bool AcceptInOrder(U& visitor) const;

 private:
  Node(T value) : value_(std::move(value)) {}

  T value_;
  std::unique_ptr<Node> left_;
  std::unique_ptr<Node> right_;
};

template <typename T>
void BinarySearch<T>::Insert(std::unique_ptr<Node> node) {
  auto* target = &root_;
  while (*target) {
    auto parent = target->get();
    if (parent->value_ < node->value_) target = &parent->right_;
    else target = &parent->left_;
  }
  *target = std::move(node);
}

template <typename T>
typename BinarySearch<T>::Node* BinarySearch<T>::Find(const T& value) const {
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
bool BinarySearch<T>::Node::AcceptInOrder(U& visitor) const {
  if (left_ && !left_->AcceptInOrder(visitor)) return false;
  if (!visitor.Visit(this)) return false;
  if (right_ && !right_->AcceptInOrder(visitor)) return false;
  return true;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_SEARCH_H_
