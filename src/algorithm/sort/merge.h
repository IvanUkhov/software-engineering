#ifndef ALGORITHM_SORT_MERGE_H_
#define ALGORITHM_SORT_MERGE_H_

#include <vector>

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
void Merge(std::vector<T>& input, int begin, int middle, int end,
           std::vector<T>& output) {
  auto i = begin, j = middle;
  for (auto k = begin; k < end; ++k) {
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
void SplitMerge(std::vector<T>& input, int begin, int end,
                std::vector<T>& output) {
  if (end - begin < 2) return;
  auto middle = (end + begin) / 2;
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
