#ifndef STRUCTURE_TREE_HEAP_H_
#define STRUCTURE_TREE_HEAP_H_

#include <utility>
#include <vector>

namespace structure { namespace tree {

namespace internal {

template <typename T>
void Down(T data[], int i, int size) {
  using std::swap;
  while (true) {
    int j = 2 * i + 1;
    if (j >= size) return;
    int k = j + 1;
    if (k < size && data[k] > data[j]) j = k;
    if (data[i] >= data[j]) return;
    swap(data[i], data[j]);
    i = j;
  }
}

template <typename T>
void Up(T data[], int i) {
  using std::swap;
  while (i > 0) {
    int j = (i - 1) / 2;
    if (data[i] <= data[j]) return;
    swap(data[i], data[j]);
    i = j;
  }
}

} // namespace internal

template <typename T>
class BinaryHeap {
 public:
  BinaryHeap() {}

  BinaryHeap(std::vector<T> data) : data_(std::move(data)) {
    Order();
  }

  void Order();
  void Sort();
  T Pop();
  void Push(T value);

  typename std::vector<T>::size_type Size() const {
    return data_.size();
  }

  operator std::vector<T>() {
    return std::move(data_);
  }

 private:
  std::vector<T> data_;
};

template <typename T>
void BinaryHeap<T>::Order() {
  int size = Size();
  for (int i = (size - 1 - 1) / 2; i >= 0; --i) {
    internal::Down(data_.data(), i, size);
  }
}

template <typename T>
void BinaryHeap<T>::Sort() {
  using std::swap;
  int size = Size();
  for (int i = size - 1; i > 0; --i) {
    swap(data_[0], data_[i]);
    internal::Down(data_.data(), 0, i);
  }
}

template <typename T>
T BinaryHeap<T>::Pop() {
  int size = Size() - 1;
  T value = data_[0];
  data_[0] = data_[size];
  data_.pop_back();
  internal::Down(data_.data(), 0, size);
  return value;
}

template <typename T>
void BinaryHeap<T>::Push(T value) {
  data_.push_back(value);
  internal::Up(data_.data(), Size() - 1);
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_HEAP_H_
