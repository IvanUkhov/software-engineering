#ifndef PROBLEM_STRING_PERMUTATIONS_H_
#define PROBLEM_STRING_PERMUTATIONS_H_

#include <ostream>
#include <string>

namespace problem {

// Write a method to compute all permutations of a string of unique characters.
void StringPermutationsUniqueChars(std::string string, std::ostream& output);

// Write a method to compute all permutations of a string whose characters are
// not necessarily unique. The list of permutations should not have duplicates.
void StringPermutationsNonuniqueChars(std::string string, std::ostream& output);

} // namespace problem

#endif // PROBLEM_STRING_PERMUTATIONS_H_
