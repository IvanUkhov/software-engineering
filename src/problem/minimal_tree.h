#ifndef PROBLEM_MINIMAL_TREE_H_
#define PROBLEM_MINIMAL_TREE_H_

#include <vector>

#include "structure/tree/search.h"

namespace problem {

typedef structure::tree::BinarySearch<int> Tree;

// Given a sorted (increasing order) array with unique integer elements, write
// an algorithm to create a binary search tree with minimal height.
Tree MinimalTree(const std::vector<int>& data);

} // namespace problem

#endif // PROBLEM_MINIMAL_TREE_H_
