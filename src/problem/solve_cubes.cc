#include <list>
#include <unordered_map>
#include <utility>

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
  std::unordered_map<std::size_t, std::list<std::pair<std::size_t, std::size_t>>> map;
  std::size_t count = 0;
  for (std::size_t i = start; i <= end; ++i) {
    for (std::size_t j = i; j <= end; ++j) {
      auto result = i * i * i + j * j * j;
      map[result].push_back({i, j});
    }
  }
  for (auto& entry : map) {
    for (auto& pair1 : entry.second) {
      for (auto& pair2 : entry.second) {
        count += internal::Print(output, pair1.first, pair1.second,
                                         pair2.first, pair2.second);
      }
    }
  }
  return count;
}

} // namespace problem
