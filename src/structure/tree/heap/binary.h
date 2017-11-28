#ifndef STRUCTURE_TREE_HEAP_BINARY_H_
#define STRUCTURE_TREE_HEAP_BINARY_H_

#include <utility>
#include <vector>

namespace structure { namespace tree { namespace heap {

namespace internal {

template <typename T>
void Down(std::vector<T>& data, int i, int size);

template <typename T>
void Up(std::vector<T>& data, int i);

template <typename T>
void Down(std::vector<T>& data, int i, int size) {
  while (true) {
    int j = 2 * i + 1;
    if (j >= size) {
      return;
    }
    int k = j + 1;
    if (k < size && data[k] > data[j]) {
      j = k;
    }
    if (data[i] >= data[j]) {
      return;
    }
    std::swap(data[i], data[j]);
    i = j;
  }
}

template <typename T>
void Up(std::vector<T>& data, int i) {
  while (i > 0) {
    int j = (i - 1) / 2;
    if (data[i] <= data[j]) {
      return;
    }
    std::swap(data[i], data[j]);
    i = j;
  }
}

} // namespace internal

template <typename T>
class Binary {
 public:
  Binary() {}
  Binary(std::vector<T> data);

  void Order();
  void Sort();
  T Pop();
  void Push(T value);
  typename std::vector<T>::size_type Size() const;

  operator std::vector<T>();

 private:
  std::vector<T> data_;
};

template <typename T>
Binary<T>::Binary(std::vector<T> data) : data_(std::move(data)) {
  this->Order();
}

template <typename T>
void Binary<T>::Order() {
  int size = this->Size();
  for (int i = (size - 1 - 1) / 2; i >= 0; --i) {
    internal::Down(this->data_, i, size);
  }
}

template <typename T>
void Binary<T>::Sort() {
  int size = this->Size();
  for (int i = size - 1; i > 0; --i) {
    std::swap(this->data_[0], this->data_[i]);
    internal::Down(this->data_, 0, i);
  }
}

template <typename T>
T Binary<T>::Pop() {
  int size = (int)this->Size() - 1;
  T value = this->data_[0];
  this->data_[0] = this->data_[size];
  this->data_.pop_back();
  internal::Down(this->data_, 0, size);
  return value;
}

template <typename T>
void Binary<T>::Push(T value) {
  this->data_.push_back(value);
  internal::Up(this->data_, (int)this->Size() - 1);
}

template <typename T>
typename std::vector<T>::size_type Binary<T>::Size() const {
  return this->data_.size();
}

template <typename T>
Binary<T>::operator std::vector<T>() {
  return std::move(this->data_);
}

} } } // namespace structure::tree::heap

#endif // STRUCTURE_TREE_HEAP_BINARY_H_
