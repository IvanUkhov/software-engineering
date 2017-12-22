#ifndef PROBLEM_UNIQUE_CHARS_H_
#define PROBLEM_UNIQUE_CHARS_H_

#include <string>

namespace problem {

// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?
bool UniqueChars(const std::string& string,
                 char begin = 'a', char end = 'z' + 1);

} // namespace problem

#endif // PROBLEM_UNIQUE_CHARS_H_
