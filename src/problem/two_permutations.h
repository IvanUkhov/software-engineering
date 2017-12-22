#ifndef PROBLEM_TWO_PERMUTATIONS_H_
#define PROBLEM_TWO_PERMUTATIONS_H_

#include <string>

namespace problem {

// Given two strings, write a method to decide if one is a permutation of the
// other.
bool TwoPermutations(std::string one, std::string other,
                     char begin = 'a', char end = 'z' + 1);

} // namespace problem

#endif // PROBLEM_TWO_PERMUTATIONS_H_
