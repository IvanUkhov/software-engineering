#ifndef STRUCTURE_TREE_SEARCH_BINARY_H_
#define STRUCTURE_TREE_SEARCH_BINARY_H_

#include <memory>

namespace structure { namespace tree { namespace search {

template <typename K, typename V>
class Binary {
 public:
  class Node {
   friend class Binary;

   public:
    Node(K key, V value)
      : key_(std::move(key)), value_(std::move(value)) {}

    Node* Search(K key) {
      if (key < key_) {
        if (left_) {
          return left_->Search(key);
        } else {
          return nullptr;
        }
      } else if (key > key_) {
        if (right_) {
          return right_->Search(key);
        } else {
          return nullptr;
        }
      } else {
        return this;
      }
    }

    const K& key() const {
      return key_;
    }

    V& value() {
      return value_;
    }

    Node* left() const {
      return left_.get();
    }

    Node* right() const {
      return right_.get();
    }

   private:
    K key_;
    V value_;
    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;
  };

  void Insert(K key, V value);

  Node* root() const {
    return root_.get();
  }

 private:
  std::unique_ptr<Node> root_;
};

template <typename K, typename V>
void Binary<K, V>::Insert(K key, V value) {
  if (!root_) {
    root_ = std::unique_ptr<Node>(new Node(key, value));
    return;
  }
  Node* current = root_.get();
  while (true) {
    if (key <= current->key_) {
      if (current->left_) {
        current = current->left_.get();
      } else {
        current->left_ = std::unique_ptr<Node>(new Node(key, value));
        return;
      }
    } else {
      if (current->right_) {
        current = current->right_.get();
      } else {
        current->right_ = std::unique_ptr<Node>(new Node(key, value));
        return;
      }
    }
  }
}

} } } // namespace structure::tree::search

#endif // STRUCTURE_TREE_SEARCH_BINARY_H_
