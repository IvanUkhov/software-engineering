#include <ctime>

#include "fixture.h"

namespace fixture {

void Randomize() {
  static bool done = false;
  if (!done) {
    std::srand(std::time(0));
    done = true;
  }
}

template <>
std::vector<double> Generate<double>(std::size_t size) {
  std::vector<double> data;
  data.reserve(size);
  for (auto value : Generate<int>(size)) {
    data.push_back((double)value / RAND_MAX);
  }
  return data;
}

} // namespace fixture
