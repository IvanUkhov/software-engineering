#include "structure/tree/heap/binary.h"

Binary::Binary(std::vector<int> data) : data_(data) {
  this->Arrange();
}

void Binary::Arrange() {
}

int Binary::Pop() {
  int value = this->data_.back();
  this->data_.pop_back();
  return value;
}

void Binary::Push(int value) {
  this->data_.push_back(value);
}

size_t Binary::Size() const {
  return this->data_.size();
}
