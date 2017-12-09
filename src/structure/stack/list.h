#ifndef STRUCTURE_STACK_LIST_H_
#define STRUCTURE_STACK_LIST_H_

#include <cstddef>
#include <memory>
#include <utility>

#include "structure/list/forward.h"

namespace structure { namespace stack {

template <typename T>
class List {
 public:
  void Push(T value) {
    auto node = std::unique_ptr<Node>(new Node(std::move(value)));
    node->InsertAfter(std::move(head_));
    head_ = std::move(node);
  }

  T Pop() {
    auto node = std::move(head_);
    head_ = node->RemoveAfter();
    return node->Value();
  }

  bool IsEmpty() const {
    return !head_;
  }

 private:
  typedef structure::list::Forward<T> Node;

  std::unique_ptr<Node> head_;
};

} } // namespace structure::stack

#endif // STRUCTURE_STACK_LIST_H_
