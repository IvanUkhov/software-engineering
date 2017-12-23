#ifndef PROBLEM_LIST_TAIL_H_
#define PROBLEM_LIST_TAIL_H_

#include <cstddef>

#include "structure/list/forward.h"

namespace problem {

// Implement an algorithm to find the kth to last element of a singly linked
// list.
template <typename T>
structure::list::Forward<T>* ListTail(structure::list::Forward<T>& head,
                                      std::size_t k) {
  return nullptr;
}

} // namespace problem

#endif // PROBLEM_LIST_TAIL_H_
