#include "problem/factorial_zeros.h"

static std::size_t Count(std::size_t dividend, std::size_t dividor) {
  std::size_t count = 0;
  while (dividend % dividor == 0) {
    ++count;
    dividend = dividend / dividor;
  }
  return count;
}

std::size_t problem::FactorialZeros(std::size_t n) {
  std::size_t count = 0;
  for (std::size_t i = 5; i <= n; ++i) count += Count(i, 5);
  return count;
}
