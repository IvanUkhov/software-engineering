#ifndef ALGORITHM_SORT_INSERTION_H_
#define ALGORITHM_SORT_INSERTION_H_

#include <vector>

namespace algorithm { namespace sort {

template <typename T>
void Insertion(std::vector<T>& data) {
  using std::swap;
  auto size = data.size();
  for (int i = 1; i < size; ++i) {
    for (int j = i; j > 0; --j) {
      if (data[j - 1] > data[j]) swap(data[j - 1], data[j]);
      else break;
    }
  }
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_INSERTION_H_
