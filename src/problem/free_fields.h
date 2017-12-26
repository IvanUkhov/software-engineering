#ifndef PROBLEM_FREE_FIELDS_H_
#define PROBLEM_FREE_FIELDS_H_

#include <cstddef>
#include <vector>

namespace problem {

// You are given a matrix of MxN boolean values representing a board of free
// (True) or occupied (False) fields. Find the size of the largest square of
// free fields.
std::size_t FreeFields(const std::vector<bool>& board, std::size_t rows,
                       std::size_t columns);

} // namespace problem

#endif // PROBLEM_FREE_FIELDS_H_
