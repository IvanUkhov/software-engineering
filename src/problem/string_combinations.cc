#include <cstddef>
#include <iostream>
#include <string>

#include "problem/string_combinations.h"

namespace problem {

namespace internal {

void StringCombinations(
    const std::string& string, std::size_t begin, std::size_t end,
    std::string& work, std::ostream& output) {
  for (std::size_t i = begin; i < end; ++i) {
    work.push_back(string[i]);
    output << work << std::endl;
    StringCombinations(string, i + 1, end, work, output);
    work.pop_back();
  }
}

} // namespace internal

void StringCombinations(const std::string& string, std::ostream& output) {
  std::string work;
  internal::StringCombinations(string, 0, string.size(), work, output);
}

} // namespace problem
