#ifndef ALGORITHM_SORT_QUICK_H_
#define ALGORITHM_SORT_QUICK_H_

#include <vector>

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
void Quick(std::vector<T>& data, int i, int j) {
}

} // namespace internal

template <typename T>
void Quick(std::vector<T>& data) {
  internal::Quick(data, 0, data.size());
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_QUICK_H_
