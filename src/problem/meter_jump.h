#ifndef PROBLEM_METER_JUMP_H_
#define PROBLEM_METER_JUMP_H_

#include <cstddef>

namespace problem {

// Design an algorithm that finds the number of ways in which you can traverse N
// meters by doing jumps of 1, 2, 3, 4, or 5 meter lengths. Assume that N can be
// a very large number.
std::size_t MeterJump(std::size_t distance);

} // namespace problem

#endif // PROBLEM_METER_JUMP_H_
