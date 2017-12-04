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
  }

  T Dequeue() {
    return T();
  }

 private:
  struct Node {
   public:
    Node() : previous(nullptr) {}

    Node* previous;
    std::unique_ptr<Node> next;
  };

  std::unique_ptr<Node> head_;
  Node* tail_;
};

} } // namespace structure::queue

#endif // STRUCTURE_QUEUE_IMPARTIAL_H_
