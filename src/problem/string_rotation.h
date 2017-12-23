#ifndef PROBLEM_STRING_ROTATION_H_
#define PROBLEM_STRING_ROTATION_H_

#include <string>

namespace problem {

// Assume you have a method isString which checks if one word is a substring of
// another. Given two strings, s1 and s2, write code to check if s2 is a
// rotation of s1 using only one call to isSubstring.
bool StringRotation(const std::string& s1, const std::string& s2);

} // namespace problem

#endif // PROBLEM_STRING_ROTATION_H_
