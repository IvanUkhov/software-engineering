#ifndef PROBLEM_ONE_AWAY_H_
#define PROBLEM_ONE_AWAY_H_

#include <string>

namespace problem {

// There are tree types of edits that can be performed on strings: insert a
// character, remove a character, or replace a character. Given two strings,
// write a function to check if they are one edit (or zero edits) away.
bool OneAway(const std::string& one, const std::string& other);

} // namespace problem

#endif // PROBLEM_ONE_AWAY_H_
