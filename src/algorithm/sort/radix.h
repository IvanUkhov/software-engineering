#ifndef ALGORITHM_SORT_RADIX_H_
#define ALGORITHM_SORT_RADIX_H_

#include <type_traits>
#include <utility>
#include <vector>

#include "algorithm/sort/count.h"

namespace algorithm { namespace sort {

template <typename T>
void Radix(std::vector<T>& data, T limit, unsigned base = 10) {
  for (unsigned power = 1; power < limit; power *= base) {
    Count<unsigned, T>(data, base, [base, power](const T& value) -> unsigned {
      return (value / power) % base;
    });
  }
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_RADIX_H_
