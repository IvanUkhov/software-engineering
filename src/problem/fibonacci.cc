#include "problem/fibonacci.h"

namespace internal {

using Quadratic = std::size_t[2][2];

const Quadratic kFibonacci = {{1, 1}, {1, 0}};
const Quadratic kIdentity = {{1, 0}, {0, 1}};

void Multiply(const Quadratic left, const Quadratic right, Quadratic result) {
  auto result00 = left[0][0] * right[0][0] + left[0][1] * right[1][0];
  auto result01 = left[0][0] * right[0][1] + left[0][1] * right[1][1];
  auto result10 = left[1][0] * right[0][0] + left[1][1] * right[1][0];
  auto result11 = left[1][0] * right[0][1] + left[1][1] * right[1][1];
  result[0][0] = result00;
  result[0][1] = result01;
  result[1][0] = result10;
  result[1][1] = result11;
}

void Power(const Quadratic factor, std::size_t number, Quadratic result) {
  if (number == 0) Multiply(kIdentity, kIdentity, result);
  else if (number == 1) Multiply(factor, kIdentity, result);
  else {
    Power(factor, number / 2, result);
    Multiply(result, result, result);
    if (number % 2 == 1) Multiply(factor, result, result);
  }
}

}

std::size_t problem::FibonacciLinear(std::size_t number) {
  if (number == 0) return 0;
  std::size_t penultimate = 0, ultimate = 1;
  for (std::size_t i = 2; i <= number; ++i) {
    ultimate = ultimate + penultimate;
    penultimate = ultimate - penultimate;
  }
  return ultimate;
}

std::size_t problem::FibonacciLogarithmic(std::size_t number) {
  if (number == 0) return 0;
  internal::Quadratic result = {};
  internal::Power(internal::kFibonacci, number - 1, result);
  return result[0][0];
}
