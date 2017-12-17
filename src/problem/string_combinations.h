#ifndef PROBLEM_STRING_COMBINATIONS_H_
#define PROBLEM_STRING_COMBINATIONS_H_

#include <ostream>
#include <string>

namespace problem {

// Implement a function that prints all possible combinations of the characters
// in a string. These combinations range in length from one to the length of the
// string. Two combinations that differ only in ordering of their characters are
// the same combination. In other words, “12” and “31” are different
// combinations from the input string “123”, but “21” is the same as “12”.
void StringCombinations(std::string string, std::ostream& output);

} // namespace problem

#endif // PROBLEM_STRING_COMBINATIONS_H_
