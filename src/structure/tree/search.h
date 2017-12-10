#ifndef STRUCTURE_TREE_SEARCH_H_
#define STRUCTURE_TREE_SEARCH_H_

#include <memory>
#include <utility>

namespace structure { namespace tree {

template <typename K, typename V>
class BinarySearch {
 public:
  class Node;

  Node* Root() const {
    return root_.get();
  }

  void Insert(std::unique_ptr<Node> node);

  void Insert(K key, V value) {
    Insert(std::unique_ptr<Node>(new Node(key, std::move(value))));
  }

  template <typename T>
  void Accept(T& visitor) const {
    if (root_) Accept(visitor, root_.get());
  }

  Node* Find(K key) const;

 private:
  template <typename T>
  bool Accept(T& visitor, Node* node) const;

  std::unique_ptr<Node> root_;
};

template <typename K, typename V>
class BinarySearch<K, V>::Node {
  friend class BinarySearch;

 public:
  Node(K key, V value) : key_(key), value_(std::move(value)) {}

  const K& Key() const {
    return key_;
  }

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
  K key_;
  V value_;
  std::unique_ptr<Node> left_;
  std::unique_ptr<Node> right_;
};

template <typename K, typename V>
void BinarySearch<K, V>::Insert(std::unique_ptr<Node> node) {
  auto* target = &root_;
  while (*target) {
    auto parent = target->get();
    if (node->key_ <= parent->key_) target = &parent->left_;
    else target = &parent->right_;
  }
  *target = std::move(node);
}

template <typename K, typename V>
typename BinarySearch<K, V>::Node* BinarySearch<K, V>::Find(K key) const {
  auto current = this->root_.get();
  while (current) {
    if (key < current->key_) current = current->Left();
    else if (key > current->key_) current = current->Right();
    else return current;
  }
  return nullptr;
}

template <typename K, typename V>
template <typename T>
bool BinarySearch<K, V>::Accept(T& visitor, Node* node) const {
  if (node->left_ && !Accept(visitor, node->Left())) return false;
  if (!visitor.Visit(node)) return false;
  if (node->right_ && !Accept(visitor, node->Right())) return false;
  return true;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_SEARCH_H_
