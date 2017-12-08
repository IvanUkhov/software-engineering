#ifndef STRUCTURE_TREE_SEARCH_H_
#define STRUCTURE_TREE_SEARCH_H_

#include <memory>
#include <utility>

namespace structure { namespace tree {

template <typename K, typename V>
class BinarySearch {
 public:
  struct Node {
   public:
    Node(K key, V value) : key(key), value(std::move(value)) {}

    K key;
    V value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
  };

  void Insert(std::unique_ptr<Node> node);

  void Insert(K key, V value) {
    Insert(std::unique_ptr<Node>(new Node(key, std::move(value))));
  }

  template <typename T>
  void Accept(T& visitor) const {
    if (root_) Accept(visitor, root_.get());
  }

  Node* Search(K key) const;

  Node* root() const {
    return root_.get();
  }

 private:
  template <typename T>
  bool Accept(T& visitor, Node* node) const;

  std::unique_ptr<Node> root_;
};

template <typename K, typename V>
void BinarySearch<K, V>::Insert(std::unique_ptr<Node> node) {
  auto* target = &root_;
  while (*target) {
    Node* parent = target->get();
    if (node->key <= parent->key) target = &parent->left;
    else target = &parent->right;
  }
  *target = std::move(node);
}

template <typename K, typename V>
typename BinarySearch<K, V>::Node* BinarySearch<K, V>::Search(K key) const {
  auto current = this->root_.get();
  while (current) {
    if (key < current->key) current = current->left.get();
    else if (key > current->key) current = current->right.get();
    else return current;
  }
  return nullptr;
}

template <typename K, typename V>
template <typename T>
bool BinarySearch<K, V>::Accept(T& visitor, Node* node) const {
  if (node->left && !Accept(visitor, node->left.get())) return false;
  if (!visitor.Visit(node)) return false;
  if (node->right && !Accept(visitor, node->right.get())) return false;
  return true;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_SEARCH_H_
