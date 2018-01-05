#include <cstddef>
#include <unordered_map>
#include <utility>

#include "problem/string_permutations.h"

void StringPermutationsUniqueChars(std::string& string, std::size_t begin,
                                   std::size_t end, std::ostream& output) {
  using std::swap;
  for (std::size_t i = begin; i < end; ++i) {
    swap(string[begin], string[i]);
    if (begin + 2 >= end) output << string << '\n';
    else StringPermutationsUniqueChars(string, begin + 1, end, output);
    swap(string[begin], string[i]);
  }
}

void StringPermutationsNonuniqueChars(
    std::string& string, std::size_t begin, std::size_t end,
    std::unordered_map<char, std::size_t>& choice, std::ostream& output) {
  for (auto& pair : choice) {
    if (pair.second == 0) continue;
    string[begin] = pair.first;
    if (begin + 1 >= end) output << string << '\n';
    else {
      --pair.second;
      StringPermutationsNonuniqueChars(string, begin + 1, end, choice, output);
      ++pair.second;
    }
  }
}

void problem::StringPermutationsUniqueChars(std::string string,
                                            std::ostream& output) {
  ::StringPermutationsUniqueChars(string, 0, string.size(), output);
}

void problem::StringPermutationsNonuniqueChars(std::string string,
                                               std::ostream& output) {
  std::unordered_map<char, std::size_t> choice;
  for (auto glyph : string) ++choice[glyph];
  ::StringPermutationsNonuniqueChars(string, 0, string.size(), choice, output);
}
