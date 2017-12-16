#ifndef STRUCTURE_TREE_RED_BLACK_H_
#define STRUCTURE_TREE_RED_BLACK_H_

#include <memory>
#include <utility>

namespace structure { namespace tree {

template <typename T>
class RedBlack {
 public:
  class Node;

  void Insert(T value) {
    auto node = Insert(std::unique_ptr<Node>(new Node(std::move(value))));
    Repair(node);
  }

  Node* Root() const {
    return root_.get();
  }

 private:
  Node* Insert(std::unique_ptr<Node> node);
  void Repair(Node* node);

  void RotateLeft(Node* node) {
    auto root = std::move(node->right_);
    auto root_ptr = root.get();
    node->right_ = std::move(root->left_);
    root->parent_ = node->parent_;
    if (node->IsLeft()) {
      root->left_ = std::move(node->parent_->left_);
      node->parent_->left_ = std::move(root);
    } else if (node->IsRight()) {
      root->left_ = std::move(node->parent_->right_);
      node->parent_->right_ = std::move(root);
    } else {
      root->left_ = std::move(root_);
      root_ = std::move(root);
    }
    node->parent_ = root_ptr;
  }

  void RotateRight(Node* node) {
    auto root = std::move(node->left_);
    auto root_ptr = root.get();
    node->left_ = std::move(root->right_);
    root->parent_ = node->parent_;
    if (node->IsLeft()) {
      root->right_ = std::move(node->parent_->left_);
      node->parent_->left_ = std::move(root);
    } else if (node->IsRight()) {
      root->right_ = std::move(node->parent_->right_);
      node->parent_->right_ = std::move(root);
    } else {
      root->right_ = std::move(root_);
      root_ = std::move(root);
    }
    node->parent_ = root_ptr;
  }

  std::unique_ptr<Node> root_;
};

template <typename T>
class RedBlack<T>::Node {
  friend class RedBlack;

 public:
  Node(T value) : value_(std::move(value)), red_(true), parent_(nullptr) {}

  const T& Value() const {
    return value_;
  }

  Node* Left() {
    return left_.get();
  }

  Node* Right() {
    return right_.get();
  }

private:
  Node* Grandparent() const {
    if (parent_) return parent_->parent_;
    return nullptr;
  }

  Node* Sibling() const {
    if (IsLeft()) return parent_->Right();
    if (IsRight()) return parent_->Left();
    return nullptr;
  }

  Node* Uncle() const {
    if (parent_) return parent_->Sibling();
    return nullptr;
  }

  bool IsLeft() const {
    return parent_ && parent_->Left() == this;
  }

  bool IsRight() const {
    return parent_ && parent_->Right() == this;
  }

  bool IsInnerLeft() const {
    auto node = Grandparent();
    if (!node || !node->left_) return false;
    return node->left_->Right() == this;
  }

  bool IsInnerRight() const {
    auto node = Grandparent();
    if (!node || !node->right_) return false;
    return node->right_->Left() == this;
  }

  bool IsBlack() const {
    return !red_;
  }

  bool IsRed() const {
    return red_;
  }

  void MakeBlack() {
    red_ = false;
  }

  void MakeRed() {
    red_ = true;
  }

  T value_;
  bool red_;
  Node* parent_;
  std::unique_ptr<Node> left_;
  std::unique_ptr<Node> right_;
};

template <typename T>
typename RedBlack<T>::Node* RedBlack<T>::Insert(std::unique_ptr<Node> node) {
  Node* parent = nullptr;
  auto* target = &root_;
  while (*target) {
    parent = target->get();
    if (parent->value_ < node->value_) target = &parent->right_;
    else target = &parent->left_;
  }
  node->parent_ = parent;
  *target = std::move(node);
  return target->get();
}

template <typename T>
void RedBlack<T>::Repair(Node* node) {
  if (!node->parent_) {
    node->MakeBlack();
    return;
  }
  if (node->parent_->IsBlack()) return;
  if (node->Uncle() && node->Uncle()->IsRed()) {
    node->parent_->MakeBlack();
    node->Uncle()->MakeBlack();
    node->Grandparent()->MakeRed();
    Repair(node->Grandparent());
    return;
  }
  if (node->IsInnerLeft()) {
    RotateLeft(node->parent_);
    node = node->Left();
  } else if (node->IsInnerRight()) {
    RotateRight(node->parent_);
    node = node->Right();
  }
  node->parent_->MakeBlack();
  node->Grandparent()->MakeRed();
  if (node->IsLeft()) RotateRight(node->Grandparent());
  else RotateLeft(node->Grandparent());
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_RED_BLACK_H_
