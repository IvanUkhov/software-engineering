#ifndef STRUCTURE_TREE_HEAP_BINARY_H_
#define STRUCTURE_TREE_HEAP_BINARY_H_

#include <utility>
#include <vector>

namespace structure { namespace tree { namespace heap {

namespace internal {

template <typename T>
void Down(T data[], int i, int size) {
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
void Up(T data[], int i) {
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
  Order();
}

template <typename T>
void Binary<T>::Order() {
  int size = Size();
  for (int i = (size - 1 - 1) / 2; i >= 0; --i) {
    internal::Down(data_.data(), i, size);
  }
}

template <typename T>
void Binary<T>::Sort() {
  int size = Size();
  for (int i = size - 1; i > 0; --i) {
    std::swap(data_[0], data_[i]);
    internal::Down(data_.data(), 0, i);
  }
}

template <typename T>
T Binary<T>::Pop() {
  int size = (int)Size() - 1;
  T value = data_[0];
  data_[0] = data_[size];
  data_.pop_back();
  internal::Down(data_.data(), 0, size);
  return value;
}

template <typename T>
void Binary<T>::Push(T value) {
  data_.push_back(value);
  internal::Up(data_.data(), (int)Size() - 1);
}

template <typename T>
typename std::vector<T>::size_type Binary<T>::Size() const {
  return data_.size();
}

template <typename T>
Binary<T>::operator std::vector<T>() {
  return std::move(data_);
}

} } } // namespace structure::tree::heap

#endif // STRUCTURE_TREE_HEAP_BINARY_H_
