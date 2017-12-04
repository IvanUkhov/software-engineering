#include "problem/solve_cubes.h"

namespace problem {

namespace internal {

std::size_t Print(std::ostream& output, std::size_t a, std::size_t b,
                  std::size_t c, std::size_t d) {
  std::size_t count = 1;
  output << a << " " << b << " " << c << " " << d << std::endl;
  if (c != d) {
    output << a << " " << b << " " << d << " " << c << std::endl;
    ++count;
  }
  if (a != b) {
    output << b << " " << a << " " << c << " " << d << std::endl;
    ++count;
  }
  if (a != b && c != d) {
    output << b << " " << a << " " << d << " " << c << std::endl;
    ++count;
  }
  return count;
}

} // namespace internal

std::size_t SolveCubes(std::ostream& output, std::size_t start,
                       std::size_t end) {
  std::size_t count = 0;
  for (std::size_t a = start; a <= end; ++a) {
    for (std::size_t b = a; b <= end; ++b) {
      auto left = a * a * a + b * b * b;
      for (auto c = start, d = end; c <= d;) {
        auto right = c * c * c + d * d * d;
        if (left > right) ++c;
        else if (left < right) --d;
        else count += internal::Print(output, a, b, c++, d--);
      }
    }
  }
  return count;
}

} // namespace problem
