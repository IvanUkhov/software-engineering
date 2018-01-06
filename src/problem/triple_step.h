#ifndef PROBLEM_TRIPLE_STEP_H_
#define PROBLEM_TRIPLE_STEP_H_

#include <cstddef>
#include <vector>

namespace problem {

// A child is running up a staircase with n steps and can hop either 1 step, 2
// steps, or 3 steps at a time. Implement a method to count how many possible
// ways the child can run up the stairs.
std::size_t TripleStep(std::size_t distance,
                       const std::vector<std::size_t>& steps = {1, 2, 3});

} // namespace problem

#endif // PROBLEM_TRIPLE_STEP_H_
