#ifndef PROBLEM_HANOI_TOWERS_H_
#define PROBLEM_HANOI_TOWERS_H_

#include <cstddef>

#include "structure/stack/list.h"

namespace problem {

using Stack = structure::stack::List<std::size_t>;

// In the classic problem of the Towers of Hanoi, you have 3 towers and N disks
// of different sizes which can slide onto any tower. The puzzle start with
// disks sorted in ascending order of size from top to bottom (i.e., each disk
// sits on top of an even large one). You have the following constraints:
//
// (1) Only one disk can be moved at a time.
// (2) A disk is lid off the top of one tower onto another tower.
// (3) A disk cannot be placed on top of a smaller disk.
//
// Write a program to move the disks from the first tower to the last using
// Stacks.
void HanoiTowers(Stack& a, Stack& b, Stack& c);

} // namespace problem

#endif // PROBLEM_HANOI_TOWERS_H_
