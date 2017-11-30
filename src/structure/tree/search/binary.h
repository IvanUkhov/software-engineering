#ifndef STRUCTURE_TREE_SEARCH_BINARY_H_
#define STRUCTURE_TREE_SEARCH_BINARY_H_

#include <memory>

namespace structure { namespace tree { namespace search {

template <typename T>
class Binary {
 public:
  struct Node {
    Node(T value) : value(value) {}

    T value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
  };

  void Insert(T value);
  const Node& root() const;

 private:
  std::unique_ptr<Node> root_;
};

template <typename T>
const typename Binary<T>::Node& Binary<T>::root() const {
  return *root_;
}

template <typename T>
void Binary<T>::Insert(T value) {
  if (!root_) {
    root_ = std::unique_ptr<Node>(new Node(value));
    return;
  }
  Node* current = root_.get();
  while (true) {
    if (value <= current->value) {
      if (current->left) {
        current = current->left.get();
      } else {
        current->left = std::unique_ptr<Node>(new Node(value));
        return;
      }
    } else {
      if (current->right) {
        current = current->right.get();
      } else {
        current->right = std::unique_ptr<Node>(new Node(value));
        return;
      }
    }
  }
}

} } } // namespace structure::tree::search

#endif // STRUCTURE_TREE_SEARCH_BINARY_H_
