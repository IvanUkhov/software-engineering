#include "structure/tree/search/binary.h"

using namespace structure::tree::search;

std::shared_ptr<Binary::Node> Binary::root() const {
  return this->root_;
}

void Binary::Insert(int value) {
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
