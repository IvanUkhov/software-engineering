#include "problem/factorial_zeros.h"

std::size_t Count(std::size_t dividend, std::size_t dividor) {
  std::size_t count = 0;
  while (dividend % dividor == 0) {
    ++count;
    dividend = dividend / dividor;
  }
  return count;
}

std::size_t problem::FactorialZeros(std::size_t n) {
  std::size_t two = 0, five = 0;
  for (std::size_t i = 1; i <= n; ++i) {
    two += Count(i, 2);
    five += Count(i, 5);
  }
  return (two < five) ? two : five;
}
