#ifndef STRUCTURE_STACK_LIST_H_
#define STRUCTURE_STACK_LIST_H_

#include <cstddef>
#include <utility>

namespace structure { namespace stack {

template <typename T>
class List {
 public:
  void Push(T value) {
  }

  T Pop() {
    return 0;
  }

  bool IsEmpty() const {
    return false;
  }
};

} } // namespace structure::stack

#endif // STRUCTURE_STACK_LIST_H_
