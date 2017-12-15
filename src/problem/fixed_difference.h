#ifndef PROBLEM_FIXED_DIFFERENCE_H_
#define PROBLEM_FIXED_DIFFERENCE_H_

#include <utility>
#include <vector>

namespace problem {

// Given an array of distinct integer values, count the number of pairs of
// integers that have difference k.
std::vector<std::pair<int, int>> FixedDifference(const std::vector<int>& values, int k);

} // namespace problem

#endif // PROBLEM_FIXED_DIFFERENCE_H_
