#ifndef PROBLEM_COMMON_SUBSEQUENCE_H_
#define PROBLEM_COMMON_SUBSEQUENCE_H_

#include <utility>
#include <vector>

namespace problem {

// Find the longest common subsequence between two arrays.
template <typename T>
std::pair<int, int> CommonSubsequence(const std::vector<T>& one,
                                      const std::vector<T>& other) {
  return {-1, -1};
}

} // namespace problem

#endif // PROBLEM_COMMON_SUBSEQUENCE_H_
