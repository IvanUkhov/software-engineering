#include <utility>

#include "problem/free_fields.h"

std::size_t problem::FreeFields(const std::vector<bool>& board,
                                std::size_t rows, std::size_t columns) {
  std::size_t max_size = 0;
  for (std::size_t i = 0; i < rows; ++i) {
    for (std::size_t j = 0; j < columns; ++j) {
      auto limit = std::min(rows - i, columns - j);
      bool stop = limit < max_size;
      for (std::size_t size = 1; !stop && size <= limit; ++size) {
        for (auto k = 0; !stop && k < size; ++k) {
          stop = !board[(i + size - 1) * columns + (j + k)] ||
                 !board[(i + k) * columns + (j + size - 1)];
        }
        max_size = std::max(max_size, size - (stop ? 1 : 0));
      }
    }
  }
  return max_size;
}
