#ifndef PROBLEM_NESTED_PERMUTATION_H_
#define PROBLEM_NESTED_PERMUTATION_H_

#include <cstddef>
#include <string>
#include <vector>

namespace problem {

// Given a smaller string s and a bigger string b, design an algorithm to find
// all permutations of the shorter string within the longer one. Print the
// location of each permutation.
std::vector<std::size_t> NestedPermutation(std::string s, std::string b);

} // namespace problem

#endif // PROBLEM_NESTED_PERMUTATION_H_
