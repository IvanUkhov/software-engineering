#ifndef ALGORITHM_SORT_COUNT_H_
#define ALGORITHM_SORT_COUNT_H_

#include <type_traits>
#include <vector>

#include "structure/tree/search.h"

namespace algorithm { namespace sort {

template <typename T>
void Count(std::vector<T>& data, T limit) {
  static_assert(std::is_unsigned<T>::value, "Count requires unsigned integers");
  std::vector<T> count(limit);
  for (auto& value : data) ++count[value];
  T value = 0;
  auto size = data.size();
  for (int i = 0; i < size; ++i) {
    while (!count[value]) ++value;
    data[i] = value;
    --count[value];
  }
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_COUNT_H_
