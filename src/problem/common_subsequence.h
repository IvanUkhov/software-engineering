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
  struct Problem {
    const std::vector<T>& one;
    const std::vector<T>& other;
    const std::size_t one_size;
    const std::size_t other_size;
    std::vector<int> solutions;

    Problem(const std::vector<T>& one, const std::vector<T>& other)
        : one(one),
          other(other),
          one_size(one.size()),
          other_size(other.size()),
          solutions(one_size * other_size, -1) {
    }

    std::size_t Compute(std::size_t i, std::size_t j) {
      auto k = i * other_size + j;
      if (k > one_size * other_size) return 0;
      if (solutions[k] != -1) return solutions[k];
      solutions[k] = (one[i] == other[j]) ? 1 + Compute(i + 1, j + 1) : 0;
      return solutions[k];
    }
  };
  Problem problem(one, other);
  std::size_t max_count = 0;
  auto result = std::make_pair(-1, -1);
  for (std::size_t i = 0; i + max_count < problem.one_size; ++i) {
    for (std::size_t j = 0; j + max_count < problem.other_size; ++j) {
      auto count = problem.Compute(i, j);
      if (count <= max_count) continue;
      max_count = count;
      result.first = i;
      result.second = j;
    }
  }
  return result;
}

} // namespace problem

#endif // PROBLEM_COMMON_SUBSEQUENCE_H_
