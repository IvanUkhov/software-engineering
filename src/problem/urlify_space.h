#ifndef PROBLEM_URLIFY_SPACE_H_
#define PROBLEM_URLIFY_SPACE_H_

#include <cstddef>
#include <string>

namespace problem {

// Write a method to replace all spaces in a string with ‘%20’. You may assume
// that the string has sufficient space at the end to hold the additional
// characters, and that you are given the “true” length of the string.
void UrlifySpace(std::string& string, std::size_t length);

} // namespace problem

#endif // PROBLEM_URLIFY_SPACE_H_
