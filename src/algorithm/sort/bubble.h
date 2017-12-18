#ifndef ALGORITHM_SORT_BUBBLE_H_
#define ALGORITHM_SORT_BUBBLE_H_

#include <cstddef>
#include <utility>
#include <vector>

namespace algorithm { namespace sort {

template <typename T>
void Bubble(std::vector<T>& data) {
  using std::swap;
  auto size = data.size();
  for (std::size_t i = 1; i < size; ++i) {
    bool swapped = false;
    for (std::size_t j = 0; i + j < size; ++j) {
      if (data[j] > data[j + 1]) {
        swap(data[j], data[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) return;
  }
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_BUBBLE_H_
