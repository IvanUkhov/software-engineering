#ifndef ALGORITHM_SORT_SELECTION_H_
#define ALGORITHM_SORT_SELECTION_H_

#include <vector>

namespace algorithm { namespace sort {

template <typename T>
void Selection(std::vector<T>& data) {
  using std::swap;
  auto size = data.size();
  for (int i = 0; i < size - 1; i++) {
    int k = i;
    for (int j = i + 1; j < size; j++) {
      if (data[k] > data[j]) k = j;
    }
    swap(data[i], data[k]);
  }
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_SELECTION_H_
