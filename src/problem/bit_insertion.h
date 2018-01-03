#ifndef PROBLEM_BIT_INSERTION_H_
#define PROBLEM_BIT_INSERTION_H_

#include <cstddef>
#include <cstdint>

namespace problem {

// You are given two 32-bit numbers, N and M, and two bit positions, i and j.
// Write a method to insert M into N such that M starts at bit j and ends at bit
// i. You can assume that the bits j through i have enough space to fit all of
// M. That is, if M = 10011, you can assume that there are at least 5 bits
// between j and i. You would not, for example, have j = 3 and i = 2, because M
// could not fully fit between bit 3 and bit 2.
std::uint32_t BitInsertion(std::uint32_t destination, std::uint32_t source,
                           std::size_t i, std::size_t j);

} // namespace problem

#endif // PROBLEM_BIT_INSERTION_H_
