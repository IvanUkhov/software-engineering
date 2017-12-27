#ifndef PROBLEM_STACK_SORT_H_
#define PROBLEM_STACK_SORT_H_

#include <utility>

#include "structure/stack/list.h"

namespace problem {

// Write a program to sort a stack such that the smallest items are on the top.
// You can use an additional temporary stack, but you may not copy the elements
// into any other data structure (such as an array). The stack supports the
// following operations: push, pop, peek, and isEmpty.
template <typename T, typename U = structure::stack::List<T>>
void StackSort(U& stack) {
  U temporary;
  while (!stack.IsEmpty()) {
    T value = stack.Pop();
    while (!temporary.IsEmpty() && temporary.Peek() > value) {
      stack.Push(temporary.Pop());
    }
    temporary.Push(std::move(value));
  }
  while (!temporary.IsEmpty()) stack.Push(temporary.Pop());
}

} // namespace problem

#endif // PROBLEM_STACK_SORT_H_
