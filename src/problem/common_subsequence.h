#ifndef PROBLEM_COMMON_SUBSEQUENCE_H_
#define PROBLEM_COMMON_SUBSEQUENCE_H_

#include <cstddef>
#include <utility>
#include <vector>

namespace problem {

// Find the longest common subsequence between two arrays.
template <typename T>
std::pair<int, int> CommonSubsequence(const std::vector<T>& one,
                                      const std::vector<T>& other) {
  auto one_size = one.size();
  auto other_size = other.size();
  auto overlap = [&](std::size_t i, std::size_t j) {
    std::size_t count = 0;
    while (i < one_size && j < other_size && one[i++] == other[j++]) ++count;
    return count;
  };
  auto result = std::make_pair(-1, -1);
  int max_count = 0;
  for (std::size_t i = 0; i < one_size; ++i) {
    for (std::size_t j = 0; j < other_size; ++j) {
      auto count = overlap(i, j);
      if (count > max_count) {
        max_count = count;
        result.first = i;
        result.second = j;
      }
    }
  }
  return result;
}

} // namespace problem

#endif // PROBLEM_COMMON_SUBSEQUENCE_H_
