#include <cstddef>

#include "problem/check_palindrome.h"

bool problem::CheckPalindrome(const std::string& string) {
  std::size_t counts[26] = {};
  for (auto glyph : string) {
    if (glyph >= 'A' && glyph <= 'Z') ++counts[glyph - 'A'];
    else if (glyph >= 'a' && glyph <= 'z') ++counts[glyph - 'a'];
  }
  std::size_t odds = 0;
  for (auto count : counts) {
    if (count % 2 == 1) ++odds;
    if (odds > 1) return false;
  }
  return true;
}
