#ifndef ALGORITHM_SORT_MERGE_H_
#define ALGORITHM_SORT_MERGE_H_

#include <cstddef>
#include <vector>

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
void Merge(std::vector<T>& input, std::size_t begin, std::size_t middle,
           std::size_t end, std::vector<T>& output) {
  std::size_t i = begin, j = middle;
  for (std::size_t k = begin; k < end; ++k) {
    if (i < middle && (j >= end || input[i] < input[j])) {
      output[k] = input[i];
      ++i;
    } else {
      output[k] = input[j];
      ++j;
    }
  }
}

template <typename T>
void SplitMerge(std::vector<T>& input, std::size_t begin, std::size_t end,
                std::vector<T>& output) {
  if (begin + 2 > end) return;
  std::size_t middle = (end + begin) / 2;
  SplitMerge(output, begin, middle, input);
  SplitMerge(output, middle, end, input);
  Merge(input, begin, middle, end, output);
}

} // namespace internal

template <typename T>
void Merge(std::vector<T>& data, std::vector<T>& work) {
  work = data;
  internal::SplitMerge(work, 0, data.size(), data);
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_MERGE_H_
