#ifndef PROBLEM_MULTI_STACK_H_
#define PROBLEM_MULTI_STACK_H_

#include <cstddef>
#include <utility>
#include <vector>

namespace problem {

// Describe how you could use a single array to implement three stacks.
template <typename T>
class MultiStack {
 public:
  MultiStack(std::size_t count)
      : count_(count + 1), heads_(count_), sizes_(count_), data_(count) {
    for (std::size_t i = 0; i < count_; ++i) heads_[i] = i;
  }

  void Push(std::size_t index, T value) {
    if (heads_[index] >= heads_[index + 1] - sizes_[index + 1]) {
      MoveData(heads_[index], sizes_[index]);
      MoveHeads(index + 1, sizes_[index]);
    }
    data_[heads_[index]] = std::move(value);
    ++heads_[index];
    ++sizes_[index];
  }

  T Pop(std::size_t index) {
    auto value = std::move(data_[heads_[index] - 1]);
    --heads_[index];
    --sizes_[index];
    return value;
  }

  T& Peek(std::size_t index) {
    return data_[heads_[index] - 1];
  }

  bool IsEmpty(std::size_t index) const {
    return sizes_[index] == 0;
  }

 private:
  void MoveData(std::size_t i, std::size_t offset) {
    using std::swap;
    int size = data_.size();
    data_.resize(size + offset);
    for (int j = size - 1; j >= i; --j) {
      swap(data_[j], data_[j + offset]);
    }
  }

  void MoveHeads(std::size_t index, std::size_t offset) {
    for (; index < count_; ++index) heads_[index] += offset;
  }

  std::size_t count_;
  std::vector<std::size_t> heads_;
  std::vector<std::size_t> sizes_;
  std::vector<T> data_;
};

} // namespace problem

#endif // PROBLEM_MULTI_STACK_H_
