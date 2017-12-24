#include "problem/fibonacci.h"

std::size_t problem::FibonacciLinear(std::size_t number) {
  if (number == 0) return 0;
  std::size_t penultimate = 0, ultimate = 1;
  for (std::size_t i = 2; i <= number; ++i) {
    ultimate = ultimate + penultimate;
    penultimate = ultimate - penultimate;
  }
  return ultimate;
}
