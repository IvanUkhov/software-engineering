#include <cassert>

#include "problem/bit_insertion.h"

std::uint32_t problem::BitInsertion(std::uint32_t destination,
                                    std::uint32_t source,
                                    std::size_t i,
                                    std::size_t j) {
  assert(i < 32 && j < 32);
  std::uint32_t mask = ~(((1 << j) - 1) - ((1 << i) - 1));
  return (destination & mask) | (source << i);
}
