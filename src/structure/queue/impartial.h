#ifndef STRUCTURE_QUEUE_IMPARTIAL_H_
#define STRUCTURE_QUEUE_IMPARTIAL_H_

#include <cstddef>
#include <memory>
#include <utility>

namespace structure { namespace queue {

template <typename T>
class Impartial {
 public:
  Impartial() : tail_(nullptr) {}

  void Enqueue(T value) {
    auto node = new Node(std::move(value), tail_);
    if (tail_) tail_->next.reset(node);
    else head_.reset(node);
    tail_ = node;
  }

  T Dequeue() {
    T value = std::move(tail_->value);
    tail_ = tail_->previous;
    if (tail_) tail_->next.reset(nullptr);
    else head_.reset(nullptr);
    return value;
  }

  T& Peek() {
    return tail_->value;
  }

  bool IsEmpty() const {
    return !head_;
  }

 private:
  struct Node {
   public:
    Node(T value, Node* previous)
        : value(std::move(value)), previous(previous) {}

    T value;
    Node* previous;
    std::unique_ptr<Node> next;
  };

  std::unique_ptr<Node> head_;
  Node* tail_;
};

} } // namespace structure::queue

#endif // STRUCTURE_QUEUE_IMPARTIAL_H_
