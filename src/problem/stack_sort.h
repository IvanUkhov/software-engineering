#ifndef PROBLEM_STACK_SORT_H_
#define PROBLEM_STACK_SORT_H_

#include "structure/stack/list.h"

namespace problem {

// Write a program to sort a stack such that the smallest items are on the top.
// You can use an additional temporary stack, but you may not copy the elements
// into any other data structure (such as an array). The stack supports the
// following operations: push, pop, peek, and isEmpty.
template <typename T, typename U = structure::stack::List<T>>
void StackSort(U& stack) {
}

} // namespace problem

#endif // PROBLEM_STACK_SORT_H_
