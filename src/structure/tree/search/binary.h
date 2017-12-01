#ifndef STRUCTURE_TREE_SEARCH_BINARY_H_
#define STRUCTURE_TREE_SEARCH_BINARY_H_

#include <memory>

namespace structure { namespace tree { namespace search {

template <typename K, typename V>
class Binary {
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
  Node* Search(K key) const;

  void Insert(K key, V value) {
    Insert(std::unique_ptr<Node>(new Node(key, std::move(value))));
  }

  Node* root() const {
    return root_.get();
  }

 protected:
  std::unique_ptr<Node> root_;
};

template <typename K, typename V>
void Binary<K, V>::Insert(std::unique_ptr<Node> node) {
  if (!root_) {
    std::swap(root_, node);
    return;
  }
  auto current = root_.get();
  while (true) {
    if (node->key <= current->key) {
      if (current->left) {
        current = current->left.get();
      } else {
        std::swap(current->left, node);
        return;
      }
    } else {
      if (current->right) {
        current = current->right.get();
      } else {
        std::swap(current->right, node);
        return;
      }
    }
  }
}

template <typename K, typename V>
typename Binary<K, V>::Node* Binary<K, V>::Search(K key) const {
  auto current = this->root_.get();
  while (current) {
    if (key < current->key) current = current->left.get();
    else if (key > current->key) current = current->right.get();
    else return current;
  }
  return nullptr;
}

} } } // namespace structure::tree::search

#endif // STRUCTURE_TREE_SEARCH_BINARY_H_
