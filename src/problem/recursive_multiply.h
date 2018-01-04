#ifndef PROBLEM_RECURSIVE_MULTIPLY_H_
#define PROBLEM_RECURSIVE_MULTIPLY_H_

#include <cstddef>

namespace problem {

// Write a recursive function to multiply two positive integers without using
// the * operator (or / operator). You can use addition, subtraction, and bit
// shifting, but you should minimize the number of those operations.
std::size_t RecursiveMultiply(std::size_t one, std::size_t other);

} // namespace problem

#endif // PROBLEM_RECURSIVE_MULTIPLY_H_
