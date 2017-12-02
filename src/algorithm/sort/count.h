#ifndef ALGORITHM_SORT_COUNT_H_
#define ALGORITHM_SORT_COUNT_H_

#include <functional>
#include <type_traits>
#include <utility>
#include <vector>

#include "structure/tree/search.h"

namespace algorithm { namespace sort {

namespace internal {

template <typename V>
V ValueKey(const V& value) {
  return value;
}

} // namespace internal

template <typename K, typename V>
void Count(std::vector<V>& data, K limit,
           std::function<K(const V&)> key = internal::ValueKey<V>) {
  using std::swap;
  static_assert(std::is_unsigned<K>::value, "Count requires unsigned integers");
  std::vector<K> counts(limit);
  for (auto& value : data) {
    ++counts[key(value)];
  }
  K total = {};
  for (auto& count : counts) {
    K old = total;
    total += count;
    count = old;
  }
  std::vector<V> work(total);
  for (auto& value : data) {
    swap(value, work[counts[key(value)]++]);
  }
  std::swap(data, work);
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_COUNT_H_
