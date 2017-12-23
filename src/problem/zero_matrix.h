#ifndef PROBLEM_ZERO_MATRIX_H_
#define PROBLEM_ZERO_MATRIX_H_

#include <unordered_set>

namespace problem {

// Write an algorithm such that if an element of an MxN matrix is 0, its entire
// row and column are set to zero.
template <typename T>
void ZeroMatrix(std::vector<T>& data, std::size_t rows, std::size_t columns) {
  std::unordered_set<std::size_t> zero_rows;
  std::unordered_set<std::size_t> zero_columns;
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      if (data[i * columns + j] == 0) {
        zero_rows.insert(i);
        zero_columns.insert(j);
      }
    }
  }
  for (auto i : zero_rows) {
    for (std::size_t j = 0; j < columns; ++j) {
      data[i * columns + j] = 0;
    }
  }
  for (auto j : zero_columns) {
    for (std::size_t i = 0; i < rows; ++i) {
      data[i * columns + j] = 0;
    }
  }
}

} // namespace problem

#endif // PROBLEM_ZERO_MATRIX_H_
