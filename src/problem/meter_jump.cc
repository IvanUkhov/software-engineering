#include <algorithm>
#include <vector>

#include "problem/meter_jump.h"

const std::vector<std::size_t> kSteps = {1, 2, 3, 4, 5};

std::size_t problem::MeterJump(std::size_t distance) {
  std::vector<std::size_t> counts(distance + 1);
  if (distance > 0) counts[0] = 1;
  for (std::size_t i = 1; i <= distance; ++i) {
    for (auto step : kSteps) {
      if (i < step) continue;
      counts[i] += counts[i - step];
    }
  }
  return counts[distance];
}
