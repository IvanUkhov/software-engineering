#ifndef PROBLEM_FIBONACCI_H_
#define PROBLEM_FIBONACCI_H_

#include <cstddef>

namespace problem {

// Compute the Fibonacci numbers in linear time.
std::size_t FibonacciLinear(std::size_t number);

// Compute the Fibonacci numbers in logarithmic time.
std::size_t FibonacciLogarithmic(std::size_t number);

} // namespace problem

#endif // PROBLEM_FIBONACCI_H_
