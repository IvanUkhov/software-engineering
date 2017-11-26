#include "structure/tree/heap/binary.h"

void Down(std::vector<int>& data, int i, int size);
void Up(std::vector<int>& data, int i);

Binary::Binary(std::vector<int> data) : data_(data) {
  this->Arrange();
}

void Binary::Arrange() {
  int size = (int)this->Size();
  for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
    Down(this->data_, i, size);
  }
}

int Binary::Pop() {
  int size = (int)this->Size() - 1;
  int value = this->data_[0];
  this->data_[0] = this->data_[size];
  this->data_.pop_back();
  Down(this->data_, 0, size);
  return value;
}

void Binary::Push(int value) {
  this->data_.push_back(value);
  Up(this->data_, (int)this->Size() - 1);
}

size_t Binary::Size() const {
  return this->data_.size();
}

void Down(std::vector<int>& data, int i, int size) {
  while (true) {
    int j = 2 * i + 1;
    if (j >= size) {
      return;
    }
    int k = j + 1;
    if (k < size && data[k] > data[j]) {
      j = k;
    }
    int value = data[i];
    if (data[j] <= value) {
      return;
    }
    data[i] = data[j];
    data[j] = value;
    i = j;
  }
}

void Up(std::vector<int>& data, int i) {
  while (i > 0) {
    int j = (i - 1) / 2;
    int value = data[i];
    if (data[j] >= value) {
      return;
    }
    data[i] = data[j];
    data[j] = value;
    i = j;
  }
}
