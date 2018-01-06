#include "problem/triple_step.h"

std::size_t problem::TripleStep(std::size_t distance,
                                const std::vector<std::size_t>& steps) {
  std::vector<std::size_t> counts(distance + 1);
  counts[0] = 1;
  for (std::size_t i = 1; i <= distance; ++i) {
    for (auto step : steps) {
      if (i < step) continue;
      counts[i] += counts[i - step];
    }
  }
  return counts[distance];
}
