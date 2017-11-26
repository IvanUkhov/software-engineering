#include "structure/tree/heap/binary.h"

Binary::Binary(std::vector<int> data) : data_(data) {
  this->Arrange();
}

void Binary::Arrange() {
  for (int i = ((int)this->Size() - 1 - 1) / 2; i >= 0; i--) this->Down(i);
}

int Binary::Pop() {
  int value = this->data_.front();
  this->data_[0] = this->data_.back();
  this->data_.pop_back();
  this->Down(0);
  return value;
}

void Binary::Push(int value) {
  this->data_.push_back(value);
  this->Up((int)this->Size() - 1);
}

size_t Binary::Size() const {
  return this->data_.size();
}

void Binary::Down(int i) {
  int size = (int)this->Size();
  while (true) {
    int j = 2 * i + 1;
    if (j >= size) break;
    int k = j + 1;
    if (k < size && this->data_[k] > this->data_[j]) j = k;
    int value = this->data_[i];
    if (this->data_[j] <= value) break;
    this->data_[i] = this->data_[j];
    this->data_[j] = value;
    i = j;
  }
}

void Binary::Up(int i) {
  while (i > 0) {
    int j = (i - 1) / 2;
    int value = this->data_[i];
    if (this->data_[j] >= value) break;
    this->data_[i] = this->data_[j];
    this->data_[j] = value;
    i = j;
  }
}
