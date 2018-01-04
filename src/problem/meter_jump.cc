#include "problem/meter_jump.h"

std::size_t problem::MeterJump(std::size_t distance,
                               const std::vector<std::size_t>& jumps) {
  if (distance == 0) return 0;
  std::vector<std::size_t> counts(distance + 1);
  counts[0] = 1;
  for (std::size_t i = 1; i <= distance; ++i) {
    for (auto jump : jumps) {
      if (i < jump) continue;
      counts[i] += counts[i - jump];
    }
  }
  return counts[distance];
}
