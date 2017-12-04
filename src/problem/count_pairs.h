#ifndef PROBLEM_COUNT_PAIRS_H_
#define PROBLEM_COUNT_PAIRS_H_

#include <utility>
#include <vector>

namespace problem {

// Given an array of distinct integer values, count the number of pairs of
// integers that have difference k.
std::vector<std::pair<int, int>> CountPairs(const std::vector<int>& values, int k);

} // namespace problem

#endif // PROBLEM_COUNT_PAIRS_H_
