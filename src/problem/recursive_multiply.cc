#include "problem/recursive_multiply.h"

std::size_t RecursiveMultiply(std::size_t one, std::size_t other) {
  if (other == 1) return one;
  auto result = RecursiveMultiply(one, other >> 1) << 1;
  return (((other >> 1) << 1) != other) ? result + one : result;
}

std::size_t problem::RecursiveMultiply(std::size_t one, std::size_t other) {
  return (one < other) ? ::RecursiveMultiply(other, one)
                       : ::RecursiveMultiply(one, other);
}
