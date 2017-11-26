#include "structure/tree/search/binary.h"

std::shared_ptr<Node> Binary::root() const {
  return this->root_;
}

void Binary::Insert(int value) {
  if (!this->root_) {
    this->root_ = std::shared_ptr<Node>(new Node(value));
  } else {
    Node *current = this->root_.get();
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
}
