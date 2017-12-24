#include <algorithm>
#include <cstddef>
#include <vector>

#include "problem/common_subsequence.h"

std::vector<std::size_t> Evaluate(const std::string& one,
                                  const std::string& other) {
  auto rows = one.size() + 1, columns = other.size() + 1;
  std::vector<std::size_t> scores(rows * columns, 0);
  for (std::size_t i = 1; i < rows; ++i) {
    for (std::size_t j = 1; j < columns; ++j) {
      if (one[i - 1] == other[j - 1]) {
        auto diagonal = scores[(i - 1) * columns + (j - 1)];
        scores[i * columns + j] = diagonal + 1;
      } else {
        auto horizontal = scores[i * columns + (j - 1)];
        auto vertical = scores[(i - 1) * columns + j];
        scores[i * columns + j] = std::max(horizontal, vertical);
      }
    }
  }
  return scores;
}

std::string Read(const std::string& one, const std::string& other,
                 const std::vector<std::size_t> scores) {
  auto rows = one.size() + 1, columns = other.size() + 1;
  auto i = rows - 1, j = columns - 1;
  std::string result;
  while (i > 0 && j > 0) {
    if (one[i - 1] == other[j - 1]) {
      result = one[i - 1] + result;
      --i, --j;
    } else {
      auto horizontal = scores[(i - 1) * columns + j];
      auto vertical = scores[i * columns + (j - 1)];
      horizontal < vertical ? --j : --i;
    }
  }
  return result;
}

std::string problem::CommonSubsequence(const std::string& one,
                                       const std::string& other) {
  return Read(one, other, Evaluate(one, other));
}
