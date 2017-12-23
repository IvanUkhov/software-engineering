#ifndef PROBLEM_LIST_DUPLICATES_H_
#define PROBLEM_LIST_DUPLICATES_H_

#include <unordered_set>

#include "structure/list/forward.h"

namespace problem {

// Write code to remove duplicates from an unsorted linked list.
template <typename T>
void ListDuplicates(structure::list::Forward<T>& list) {
  std::unordered_set<T> seen;
  seen.insert(list.Value());
  auto current = &list;
  while (current->Next()) {
    auto& value = current->Next()->Value();
    if (seen.count(value) > 0) {
      current->PushBack(current->BreakAfter()->BreakAfter());
    } else {
      seen.insert(value);
      current = current->Next();
    }
  }
}

} // namespace problem

#endif // PROBLEM_LIST_DUPLICATES_H_
