#ifndef ALGORITHM_SORT_QUICK_H_
#define ALGORITHM_SORT_QUICK_H_

#include <vector>

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
int Partition(std::vector<T>& data, int left, int right) {
  using std::swap;
  T pivot = data[left];
  int i = left, j = right;
  while (true) {
    while (data[i] < pivot) {
      ++i;
    }
    while (data[j] > pivot) {
      --j;
    }
    if (i < j) {
      swap(data[i], data[j]);
    } else {
      return j;
    }
  }
}

template <typename T>
void Quick(std::vector<T>& data, int left, int right) {
  if (left < right) {
    int middle = Partition(data, left, right);
    Quick(data, left, middle);
    Quick(data, middle + 1, right);
  }
}

} // namespace internal

template <typename T>
void Quick(std::vector<T>& data) {
  internal::Quick(data, 0, data.size() - 1);
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_QUICK_H_
