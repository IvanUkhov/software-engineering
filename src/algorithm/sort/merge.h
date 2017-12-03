#ifndef ALGORITHM_SORT_MERGE_H_
#define ALGORITHM_SORT_MERGE_H_

#include <cstddef>
#include <vector>

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
void Merge(std::vector<T>& input, std::size_t left, std::size_t middle,
           std::size_t right, std::vector<T>& output) {
  std::size_t i = left, j = middle;
  for (std::size_t k = left; k < right; ++k) {
    if (i < middle && (j >= right || input[i] < input[j])) {
      output[k] = input[i];
      ++i;
    } else {
      output[k] = input[j];
      ++j;
    }
  }
}

template <typename T>
void SplitMerge(std::vector<T>& input, std::size_t left, std::size_t right,
                std::vector<T>& output) {
  if (right - left < 2) return;
  std::size_t middle = (right + left) / 2;
  SplitMerge(output, left, middle, input);
  SplitMerge(output, middle, right, input);
  Merge(input, left, middle, right, output);
}

} // namespace internal

template <typename T>
void Merge(std::vector<T>& data, std::vector<T>& work) {
  work = data;
  internal::SplitMerge(work, 0, data.size(), data);
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_MERGE_H_
