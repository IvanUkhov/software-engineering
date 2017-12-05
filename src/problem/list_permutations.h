#ifndef PROBLEM_LIST_PERMUTATIONS_H_
#define PROBLEM_LIST_PERMUTATIONS_H_

#include <cstddef>
#include <ostream>
#include <string>

namespace problem {

// Design an algorithm to print all permutations of a string. For simplicity,
// assume all characters are unique.
std::size_t ListPermutations(std::ostream& output, const std::string& string);

} // namespace problem

#endif // PROBLEM_LIST_PERMUTATIONS_H_
