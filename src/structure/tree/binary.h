#ifndef STRUCTURE_TREE_BINARY_H_
#define STRUCTURE_TREE_BINARY_H_

#include <memory>
#include <utility>

namespace structure { namespace tree {

template <typename T>
class Binary {
 public:
  class Node;

  auto Root() const {
    return root_.get();
  }

 protected:
  static auto& LeftOwned(std::unique_ptr<Node>& node) {
    return node->left_;
  }

  static auto& RightOwned(std::unique_ptr<Node>& node) {
    return node->right_;
  }

  auto& RootOwned() {
    return root_;
  }

 private:
  std::unique_ptr<Node> root_;
};

template <typename T>
class Binary<T>::Node {
  friend class Binary;

 public:
  Node(T value) : value_(std::move(value)) {}

  const T& Value() const {
    return value_;
  }

  auto Left() const {
    return left_.get();
  }

  auto Right() const {
    return right_.get();
  }

  template <typename U>
  bool Accept(U& visitor) const;

 private:
  T value_;
  std::unique_ptr<Node> left_;
  std::unique_ptr<Node> right_;
};

template <typename T>
template <typename U>
bool Binary<T>::Node::Accept(U& visitor) const {
  if (left_ && !left_->Accept(visitor)) return false;
  if (!visitor.Visit(this)) return false;
  if (right_ && !right_->Accept(visitor)) return false;
  return true;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_BINARY_H_
