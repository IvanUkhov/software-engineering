#include <vector>

#include "problem/unique_chars.h"

bool problem::UniqueChars(const std::string& string, char begin, char end) {
  std::vector<bool> seen(end - begin);
  for (auto glyph : string) {
    if (seen[glyph - begin]) return false;
    seen[glyph - begin] = true;
  }
  return true;
}
