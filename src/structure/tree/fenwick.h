#ifndef STRUCTURE_TREE_FENWICK_H_
#define STRUCTURE_TREE_FENWICK_H_

#include <cstddef>
#include <vector>

namespace structure { namespace tree {

template <typename T>
class Fenwick {
 public:
  Fenwick(std::vector<T> data);

  T Sum(std::size_t i) const {
    T result = {};
    for (; i > 0; i -= i & -i) result += data_[i - 1];
    return result;
  }

  T Sum(std::size_t i, std::size_t j) const {
    T result = {};
    for (; j > i; j -= j & -j) result += data_[j - 1];
    for (; i > j; i -= i & -i) result -= data_[i - 1];
    return result;
  }

  void Add(std::size_t i, T delta) {
    auto size = data_.size();
    for (++i; i <= size; i += i & -i) data_[i - 1] += delta;
  }

 private:
  std::vector<T> data_;
};

template <typename T>
Fenwick<T>::Fenwick(std::vector<T> data) : data_(std::move(data)) {
  auto size = data_.size();
  for (std::size_t i = 1; i <= size; ++i) {
    auto j = i + (i & -i);
    if (j <= size) data_[j - 1] += data_[i - 1];
  }
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_FENWICK_H_
