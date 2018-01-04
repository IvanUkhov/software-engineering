#ifndef PROBLEM_MAGIC_INDEX_H_
#define PROBLEM_MAGIC_INDEX_H_

#include <vector>

namespace problem {

// A magic index in an array A[1...n-1] is defined to be an index such that A[i]
// = i. Given a sorted array of distinct integers, write a method to find a
// magic index, if one exists, in array A.
int MagicIndex(const std::vector<int>& data);

} // namespace problem

#endif // PROBLEM_MAGIC_INDEX_H_
