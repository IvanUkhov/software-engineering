#ifndef STRUCTURE_TREE_HEAP_H_
#define STRUCTURE_TREE_HEAP_H_

#include <functional>
#include <utility>
#include <vector>

namespace structure { namespace tree {

template <typename T, typename C>
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

  bool IsEmpty() const {
    return data_.empty();
  }

  operator std::vector<T>() {
    return std::move(data_);
  }

 private:
  void Down(T data[], int i, int size);
  void Up(T data[], int i);

  C compare_;
  std::vector<T> data_;
};

template <typename T>
using MaxHeap = BinaryHeap<T, std::greater<T>>;

template <typename T>
using MinHeap = BinaryHeap<T, std::less<T>>;

template <typename T, typename C>
void BinaryHeap<T, C>::Order() {
  int size = data_.size();
  for (int i = (size - 1 - 1) / 2; i >= 0; --i) {
    Down(data_.data(), i, size);
  }
}

template <typename T, typename C>
void BinaryHeap<T, C>::Sort() {
  using std::swap;
  int size = data_.size();
  for (int i = size - 1; i > 0; --i) {
    swap(data_[0], data_[i]);
    Down(data_.data(), 0, i);
  }
}

template <typename T, typename C>
T BinaryHeap<T, C>::Pop() {
  int size = data_.size() - 1;
  T value = data_[0];
  data_[0] = data_[size];
  data_.pop_back();
  Down(data_.data(), 0, size);
  return value;
}

template <typename T, typename C>
void BinaryHeap<T, C>::Push(T value) {
  data_.push_back(std::move(value));
  Up(data_.data(), data_.size() - 1);
}

template <typename T, typename C>
void BinaryHeap<T, C>::Down(T data[], int i, int size) {
  using std::swap;
  while (true) {
    int j = 2 * i + 1;
    if (j >= size) return;
    int k = j + 1;
    if (k < size && compare_(data[k], data[j])) j = k;
    if (!compare_(data[j], data[i])) return;
    swap(data[i], data[j]);
    i = j;
  }
}

template <typename T, typename C>
void BinaryHeap<T, C>::Up(T data[], int i) {
  using std::swap;
  while (i > 0) {
    int j = (i - 1) / 2;
    if (!compare_(data[i], data[j])) return;
    swap(data[i], data[j]);
    i = j;
  }
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_HEAP_H_
