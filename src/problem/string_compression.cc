#include <cstddef>
#include <sstream>

#include "problem/string_compression.h"

std::string problem::StringCompression(const std::string& string) {
  auto size = string.size();
  std::stringstream result;
  for (std::size_t i = 1, count = 1; i <= size; ++i, ++count) {
    if (i == size || string[i - 1] != string[i]) {
      result << string[i - 1] << count;
      if (result.tellg() > size) return string;
      count = 0;
    }
  }
  return result.str();
}
