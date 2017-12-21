#include <cstddef>
#include <utility>

#include "problem/string_permutations.h"

namespace problem {

namespace internal {

using std::size_t;

void StringPermutations(std::string& string, size_t begin, size_t end,
                        std::ostream& output) {
  using std::swap;
  if (begin + 1 == end) {
    output << string << '\n';
    return;
  }
  for (size_t i = begin; i < end; ++i) {
    swap(string[begin], string[i]);
    StringPermutations(string, begin + 1, end, output);
    swap(string[begin], string[i]);
  }
}

} // namespace internal

void StringPermutations(std::string string, std::ostream& output) {
  internal::StringPermutations(string, 0, string.size(), output);
}

} // namespace problem
