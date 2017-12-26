#include <utility>

#include "problem/free_fields.h"

std::size_t problem::FreeFields(const std::vector<bool>& board,
                                std::size_t rows, std::size_t columns) {
  std::size_t max_size = 0;
  std::vector<std::size_t> sizes(rows * columns);
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      if (!board[i * columns + j]) continue;
      auto diagonal = i > 0 && j > 0 ? sizes[(i - 1) * columns + (j + 1)] : 0;
      auto horizontal = i > 0 ? sizes[(i - 1) * columns + j] : 0;
      auto vertical = j > 0 ? sizes[i * columns + (j - 1)] : 0;
      sizes[i * columns + j] =
          1 + std::min(diagonal, std::min(horizontal, vertical));
      max_size = std::max(max_size, sizes[i * columns + j]);
    }
  }
  return max_size;
}
