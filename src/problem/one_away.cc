#include <cstddef>

#include "problem/one_away.h"

bool OneAway(const std::string& a, const std::string& b) {
  auto a_size = a.size();
  auto b_size = b.size();
  switch (b_size - a_size) {
    case 0: {
      for (std::size_t i = 0, count = 0; i < a_size; ++i) {
        if (a[i] != b[i]) {
          if (++count > 1) return false;
        }
      }
      return true;
    }
    case 1: {
      for (std::size_t i = 0, j = 0, count = 0; j < b_size; ++j) {
        if (a[i] != b[j]) {
          if (++count > 1) return false;
        } else {
          ++i;
        }
      }
      return true;
    }
    default: {
      return false;
    }
  }
}

bool problem::OneAway(const std::string& one, const std::string& other) {
  if (one.size() < other.size()) return ::OneAway(one, other);
  else return ::OneAway(other, one);
}
