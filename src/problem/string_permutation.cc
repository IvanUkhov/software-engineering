#include <cstddef>
#include <utility>

#include "problem/string_permutation.h"

namespace problem {

namespace internal {

using std::size_t;

void StringPermutation(std::string& string, size_t begin, size_t end,
                       std::ostream& output) {
  using std::swap;
  if (begin + 1 == end) {
    output << string << std::endl;
  } else {
    for (size_t i = begin; i < end; ++i) {
      swap(string[begin], string[i]);
      StringPermutation(string, begin + 1, end, output);
      swap(string[begin], string[i]);
    }
  }
}

} // namespace internal

void StringPermutation(std::string string, std::ostream& output) {
  internal::StringPermutation(string, 0, string.size(), output);
}

} // namespace problem
