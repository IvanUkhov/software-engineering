#ifndef STRUCTURE_STACK_ARRAY_H_
#define STRUCTURE_STACK_ARRAY_H_

#include <cstddef>
#include <utility>
#include <vector>

namespace structure { namespace stack {

template <typename T>
class Array {
 public:
  void Push(T value) {
    data_.push_back(std::move(value));
  }

  T Pop() {
    T value = std::move(data_.back());
    data_.pop_back();
    return value;
  }

  std::size_t Size() const {
    return data_.size();
  }

 private:
  std::vector<T> data_;
};

} } // namespace structure::stack

#endif // STRUCTURE_STACK_ARRAY_H_
