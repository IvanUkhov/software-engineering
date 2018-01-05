#include <cstddef>
#include <utility>

#include "problem/string_permutations.h"

using std::size_t;

void StringPermutationsUniqueChars(std::string& string, size_t begin,
                                   size_t end, std::ostream& output) {
  using std::swap;
  if (begin + 1 == end) output << string << '\n';
  else {
    for (size_t i = begin; i < end; ++i) {
      swap(string[begin], string[i]);
      StringPermutationsUniqueChars(string, begin + 1, end, output);
      swap(string[begin], string[i]);
    }
  }
}

void problem::StringPermutationsUniqueChars(std::string string,
                                            std::ostream& output) {
  ::StringPermutationsUniqueChars(string, 0, string.size(), output);
}

void problem::StringPermutationsNonuniqueChars(std::string string,
                                               std::ostream& output) {
}
