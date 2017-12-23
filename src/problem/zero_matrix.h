#ifndef PROBLEM_ZERO_MATRIX_H_
#define PROBLEM_ZERO_MATRIX_H_

#include <vector>

namespace problem {

// Write an algorithm such that if an element of an MxN matrix is 0, its entire
// row and column are set to zero.
template <typename T>
void ZeroMatrix(std::vector<T>& data, std::size_t rows, std::size_t columns) {
  std::vector<bool> zero_rows(rows);
  std::vector<bool> zero_columns(columns);
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      if (data[i * columns + j] == 0) {
        zero_rows[i] = true;
        zero_columns[j] = true;
      }
    }
  }
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      if (zero_rows[i] || zero_columns[j]) data[i * columns + j] = 0;
    }
  }
}

} // namespace problem

#endif // PROBLEM_ZERO_MATRIX_H_
