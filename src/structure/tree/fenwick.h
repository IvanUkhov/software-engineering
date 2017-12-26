#ifndef STRUCTURE_TREE_FENWICK_H_
#define STRUCTURE_TREE_FENWICK_H_

#include <cstddef>
#include <vector>

namespace structure { namespace tree {

template <typename T, typename SumType = T>
class Fenwick {
 public:
  Fenwick(std::vector<T> data) : data_(std::move(data)) {}

  SumType Sum(std::size_t i, std::size_t j) const {
    return {};
  }

 private:
  std::vector<T> data_;
};

} } // namespace structure::tree

#endif // STRUCTURE_TREE_FENWICK_H_
