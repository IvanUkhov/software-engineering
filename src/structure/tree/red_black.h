#ifndef STRUCTURE_TREE_RED_BLACK_H_
#define STRUCTURE_TREE_RED_BLACK_H_

#include <memory>
#include <utility>

namespace structure { namespace tree {

template <typename K, typename V>
class RedBlack {
 public:
  class Node {
    friend class RedBlack;

   public:
    Node(K key, V value)
      : key_(key), value_(std::move(value)), red_(true), parent_(nullptr) {}

    V& Value() {
      return value_;
    }

    Node* Left() {
      return left_.get();
    }

    Node* Right() {
      return right_.get();
    }

  private:
    Node* Parent() const {
      return parent_;
    }

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

    K key_;
    V value_;
    bool red_;
    Node* parent_;
    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;
  };

  void Insert(K key, V value) {
    auto node = Append(std::unique_ptr<Node>(new Node(key, std::move(value))));
    Repair(node);
  }

  Node* Root() const {
    return root_.get();
  }

 private:
  Node* Append(std::unique_ptr<Node> node);
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

template <typename K, typename V>
typename RedBlack<K, V>::Node* RedBlack<K, V>::Append(
    std::unique_ptr<Node> node) {
  auto node_ptr = node.get();
  if (!root_) {
    std::swap(root_, node);
    return node_ptr;
  }
  auto current = root_.get();
  while (true) {
    if (node->key_ <= current->key_) {
      if (current->left_) {
        current = current->Left();
      } else {
        node->parent_ = current;
        std::swap(current->left_, node);
        break;
      }
    } else {
      if (current->right_) {
        current = current->Right();
      } else {
        node->parent_ = current;
        std::swap(current->right_, node);
        break;
      }
    }
  }
  return node_ptr;
}

template <typename K, typename V>
void RedBlack<K, V>::Repair(Node* node) {
  if (!node->Parent()) {
    node->MakeBlack();
    return;
  }
  if (node->Parent()->IsBlack()) return;
  if (node->Uncle() && node->Uncle()->IsRed()) {
    node->Parent()->MakeBlack();
    node->Uncle()->MakeBlack();
    node->Grandparent()->MakeRed();
    Repair(node->Grandparent());
    return;
  }
  if (node->IsInnerLeft()) {
    RotateLeft(node->Parent());
    node = node->Left();
  } else if (node->IsInnerRight()) {
    RotateRight(node->Parent());
    node = node->Right();
  }
  node->Parent()->MakeBlack();
  node->Grandparent()->MakeRed();
  if (node->IsLeft()) RotateRight(node->Grandparent());
  else RotateLeft(node->Grandparent());
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_RED_BLACK_H_
