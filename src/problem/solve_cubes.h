#ifndef PROBLEM_SOLVE_CUBES_H_
#define PROBLEM_SOLVE_CUBES_H_

#include <cstddef>
#include <ostream>
#include <vector>

namespace problem {

// Print all positive integers to the equation a^3 + b^3 = c^3 + d^3 where a, b,
// c, and d are integers between 1 and 1000.
std::size_t SolveCubes(std::ostream& output, std::size_t start = 1,
                       std::size_t end = 1000);

} // namespace problem

#endif // PROBLEM_SOLVE_CUBES_H_
