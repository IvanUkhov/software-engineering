#include <cstddef>
#include <utility>

#include "problem/list_permutations.h"

namespace problem {

namespace internal {

using std::size_t;

void ListPermutations(std::string& string, size_t start, size_t finish,
                      std::ostream& output) {
  using std::swap;
  if (start + 1 == finish) {
    output << string << std::endl;
  } else {
    for (size_t i = start; i < finish; ++i) {
      swap(string[start], string[i]);
      ListPermutations(string, start + 1, finish, output);
      swap(string[start], string[i]);
    }
  }
}

} // namespace internal

void ListPermutations(std::string string, std::ostream& output) {
  internal::ListPermutations(string, 0, string.size(), output);
}

} // namespace problem
