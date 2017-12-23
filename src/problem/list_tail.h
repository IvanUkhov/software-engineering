#ifndef PROBLEM_LIST_TAIL_H_
#define PROBLEM_LIST_TAIL_H_

#include <cstddef>

#include "structure/list/forward.h"

namespace problem {

// Implement an algorithm to find the kth to last element of a singly linked
// list.
template <typename T>
structure::list::Forward<T>* ListTail(structure::list::Forward<T>& head,
                                      std::size_t position) {
  auto fast = &head;
  while (position > 0) {
    fast = fast->Next();
    if (!fast) return nullptr;
    --position;
  }
  auto slow = &head;
  while (fast->Next()) {
    fast = fast->Next();
    slow = slow->Next();
  }
  return slow;
}

} // namespace problem

#endif // PROBLEM_LIST_TAIL_H_
