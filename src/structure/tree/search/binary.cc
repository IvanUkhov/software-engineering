#include "structure/tree/search/binary.h"

Binary::~Binary() {
  if (this->root_) delete this->root_;
}

Node* Binary::root() const {
  return this->root_;
}

void Binary::Insert(int value) {
  if (!this->root_) {
    this->root_ = new Node(value);
  } else {
    Node *current = this->root_;
    while (true) {
      if (value <= current->value) {
        if (current->left) {
          current = current->left;
        } else {
          current->left = new Node(value);
          return;
        }
      } else {
        if (current->right) {
          current = current->right;
        } else {
          current->right = new Node(value);
          return;
        }
      }
    }
  }
}

Node::~Node() {
  if (this->left) delete this->left;
  if (this->right) delete this->right;
}
