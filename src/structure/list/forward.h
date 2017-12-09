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

  Forward& Append(std::unique_ptr<Forward> next) {
    std::swap(next_, next);
    std::swap(next_->next_, next);
    return *next_;
  }

  Forward& Append(T value) {
    return Append(std::unique_ptr<Forward>(new Forward(std::move(value))));
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
