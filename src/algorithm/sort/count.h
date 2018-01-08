#ifndef ALGORITHM_SORT_COUNT_H_
#define ALGORITHM_SORT_COUNT_H_

#include <functional>
#include <type_traits>
#include <utility>
#include <vector>

#include "structure/tree/search.h"

namespace algorithm { namespace sort {

namespace internal {

template <typename T>
T ValueKey(const T& value) {
  return value;
}

} // namespace internal

template <typename K, typename V>
void Count(std::vector<V>& data, K range,
           std::function<K(const V&)> key = internal::ValueKey<V>) {
  using std::swap;
  static_assert(std::is_unsigned<K>::value, "Count requires unsigned integers");
  std::vector<K> counts(range);
  for (auto& value : data) ++counts[key(value)];
  K total = {};
  for (auto& count : counts) {
    total += count;
    count = total - count;
  }
  std::vector<V> work(total);
  for (auto& value : data) swap(value, work[counts[key(value)]++]);
  std::swap(data, work);
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_COUNT_H_
