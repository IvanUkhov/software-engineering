#ifndef ALGORITHM_SORT_RADIX_H_
#define ALGORITHM_SORT_RADIX_H_

#include <cstddef>
#include <type_traits>
#include <utility>
#include <vector>

#include "algorithm/sort/count.h"

namespace algorithm { namespace sort {

template <typename T>
void Radix(std::vector<T>& data, T range, std::size_t base = 10) {
  for (std::size_t power = 1; power < range; power *= base) {
    Count<std::size_t, T>(
        data, base, [base, power](const T& value) {
          return (value / power) % base;
        });
  }
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_RADIX_H_
