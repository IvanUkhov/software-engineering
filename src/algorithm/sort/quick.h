#ifndef ALGORITHM_SORT_QUICK_H_
#define ALGORITHM_SORT_QUICK_H_

#include <cstddef>
#include <utility>
#include <vector>

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
int Partition(std::vector<T>& data, int begin, int end) {
  using std::swap;
  T pivot = data[begin];
  int i = begin - 1, j = end;
  while (true) {
    while (data[++i] < pivot) {}
    while (data[--j] > pivot) {}
    if (i < j) swap(data[i], data[j]);
    else return j + 1;
  }
}

template <typename T>
void Quick(std::vector<T>& data, std::size_t begin, std::size_t end) {
  if (begin + 2 > end) return;
  int middle = Partition(data, begin, end);
  Quick(data, begin, middle);
  Quick(data, middle, end);
}

} // namespace internal

template <typename T>
void Quick(std::vector<T>& data) {
  internal::Quick(data, 0, data.size());
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_QUICK_H_
