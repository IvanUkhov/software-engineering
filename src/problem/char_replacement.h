#ifndef PROBLEM_CHAR_REPLACEMENT_H_
#define PROBLEM_CHAR_REPLACEMENT_H_

#include <cstddef>
#include <string>

namespace problem {

// Write a method to replace all spaces in a string with ‘%20’. You may assume
// that the string has sufficient space at the end to hold the additional
// characters, and that you are given the “true” length of the string.
void CharReplacement(std::string& string, std::size_t length);

} // namespace problem

#endif // PROBLEM_CHAR_REPLACEMENT_H_
