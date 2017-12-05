#include <list>
#include <unordered_map>
#include <utility>

#include "problem/solve_cubes.h"

namespace problem {

namespace internal {

using std::size_t;

size_t Print(std::ostream& output, size_t a, size_t b, size_t c, size_t d) {
  size_t count = 0;
  auto print = [&output, &count](size_t a, size_t b, size_t c, size_t d) {
    output << a << " " << b << " " << c << " " << d << std::endl;
    ++count;
  };
  print(a, b, c, d);
  if (c != d) print(a, b, d, c);
  if (a != b) print(b, a, c, d);
  if (a != b && c != d) print(b, a, d, c);
  return count;
}

} // namespace internal

std::size_t SolveCubes(std::ostream& output, std::size_t start,
                       std::size_t end) {
  typedef std::pair<std::size_t, std::size_t> Pair;
  std::unordered_map<std::size_t, std::list<Pair>> map;
  for (std::size_t i = start; i <= end; ++i) {
    for (std::size_t j = i; j <= end; ++j) {
      auto result = i * i * i + j * j * j;
      map[result].push_back({i, j});
    }
  }
  std::size_t count = 0;
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
