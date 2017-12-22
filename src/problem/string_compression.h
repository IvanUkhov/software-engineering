#ifndef PROBLEM_STRING_COMPRESSION_H_
#define PROBLEM_STRING_COMPRESSION_H_

#include <ostream>
#include <string>

namespace problem {

// Implement a method to perform basic string compression using the counts of
// repeated characters. For example, the string aabcccccaaa would become
// a2b1c5a3. If the compressed string would not become smaller than the original
// string, your method should return the original string. You can assume the
// string has only uppercase and lowercase letters.
std::string StringCompression(const std::string& string);

} // namespace problem

#endif // PROBLEM_STRING_COMPRESSION_H_
