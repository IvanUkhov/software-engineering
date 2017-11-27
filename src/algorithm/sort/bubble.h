#ifndef ALGORITHM_SORT_BUBBLE_H_
#define ALGORITHM_SORT_BUBBLE_H_

#include <utility>

namespace algorithm { namespace sort {

template <typename T>
void Bubble(std::vector<T>& data) {
  typedef typename std::vector<T>::size_type size_t;
  size_t size = data.size();
  for (size_t i = 1; i < size; i++) {
    bool swapped = false;
    for (size_t j = 0; j < size - i; j++) {
      if (data[j] > data[j + 1]) {
        std::swap(data[j], data[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      return;
    }
  }
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_BUBBLE_H_
