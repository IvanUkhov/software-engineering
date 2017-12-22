#include <vector>

#include "problem/two_permutations.h"

bool problem::TwoPermutations(std::string one, std::string other,
                              char begin, char end) {
  if (one.size() != other.size()) return false;
  std::vector<int> counts(end - begin);
  for (auto glyph : one) ++counts[glyph - begin];
  for (auto glyph : other) {
    --counts[glyph - begin];
    if (counts[glyph - begin] < 0) return false;
  }
  for (auto count : counts) {
    if (count != 0) return false;
  }
  return true;
}
