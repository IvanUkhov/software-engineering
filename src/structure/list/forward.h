#ifndef STRUCTURE_LIST_FORWARD_H_
#define STRUCTURE_LIST_FORWARD_H_

#include <memory>
#include <utility>

namespace structure { namespace list {

template <typename T>
class Forward {
 public:
  class Iterator {
   public:
    Iterator() : node_(nullptr) {}
    Iterator(Forward& node) : node_(&node) {}

    Iterator& operator++() {
      node_ = node_->next_.get();
      return *this;
    }

    Forward& operator*() {
      return *node_;
    }

    bool operator!=(const Iterator& other) {
      return node_ != other.node_;
    }

   private:
    Forward* node_;
  };

  Forward(T value) : value_(std::move(value)) {}

  Forward& Append(T value) {
    return Append(std::unique_ptr<Forward>(new Forward(std::move(value))));
  }

  Forward& Append(std::unique_ptr<Forward> node) {
    std::swap(next_, node);
    next_->PushBack(std::move(node));
    return *next_;
  }

  Forward& PushBack(T value) {
    return PushBack(std::unique_ptr<Forward>(new Forward(std::move(value))));
  }

  Forward& PushBack(std::unique_ptr<Forward> node) {
    auto current = this;
    while (current->next_) current = current->next_.get();
    current->next_ = std::move(node);
    return *current->next_;
  }

  void Prune() {
    while (next_) {
      auto next = std::move(next_->next_);
      std::swap(next_, next);
    }
  }

  T& Value() {
    return this->value_;
  }

 private:
  std::unique_ptr<Forward> next_;
  T value_;
};

template <typename T>
typename Forward<T>::Iterator begin(Forward<T>& node) {
  return typename Forward<T>::Iterator(node);
}

template <typename T>
typename Forward<T>::Iterator end(Forward<T>& node) {
  return typename Forward<T>::Iterator();
}

} } // namespace structure::list

#endif // STRUCTURE_LIST_FORWARD_H_
