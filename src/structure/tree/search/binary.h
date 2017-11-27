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
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
  };

  void Insert(T value);
  std::shared_ptr<Node> root() const;

 private:
  std::shared_ptr<Node> root_;
};

template <typename T>
std::shared_ptr<typename Binary<T>::Node> Binary<T>::root() const {
  return this->root_;
}

template <typename T>
void Binary<T>::Insert(T value) {
  if (!this->root_) {
    this->root_ = std::shared_ptr<Node>(new Node(value));
    return;
  }
  std::shared_ptr<Node> current = this->root_;
  while (true) {
    if (value <= current->value) {
      if (current->left) {
        current = current->left;
      } else {
        current->left = std::shared_ptr<Node>(new Node(value));
        return;
      }
    } else {
      if (current->right) {
        current = current->right;
      } else {
        current->right = std::shared_ptr<Node>(new Node(value));
        return;
      }
    }
  }
}

} } } // namespace structure::tree::search

#endif // STRUCTURE_TREE_SEARCH_BINARY_H_
