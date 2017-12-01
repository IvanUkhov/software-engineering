#ifndef ALGORITHM_SORT_BUBBLE_H_
#define ALGORITHM_SORT_BUBBLE_H_

#include <utility>
#include <vector>

namespace algorithm { namespace sort {

template <typename T>
void Bubble(std::vector<T>& data) {
  using std::swap;
  auto size = data.size();
  for (int i = 1; i < size; ++i) {
    bool swapped = false;
    for (int j = 0; j < size - i; ++j) {
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
