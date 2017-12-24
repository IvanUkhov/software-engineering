#ifndef ALGORITHM_SORT_QUICK_H_
#define ALGORITHM_SORT_QUICK_H_

#include <utility>
#include <vector>

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
int Partition(std::vector<T>& data, int begin, int end) {
  using std::swap;
  T pivot = data[begin];
  auto i = begin - 1, j = end;
  while (true) {
    while (data[++i] < pivot) {}
    while (data[--j] > pivot) {}
    if (i >= j) return j;
    swap(data[i], data[j]);
  }
}

template <typename T>
void Quick(std::vector<T>& data, int begin, int end) {
  if (end - begin < 2) return;
  auto middle = Partition(data, begin, end) + 1;
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
