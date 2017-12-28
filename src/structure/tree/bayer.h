#ifndef STRUCTURE_TREE_BAYER_H_
#define STRUCTURE_TREE_BAYER_H_

#include <array>
#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>

namespace structure { namespace tree {

template <typename T, std::size_t N>
class Bayer {
 public:
  class Node {
    friend class Bayer;

   public:

   private:
    Node(bool leaf = true) : leaf_(leaf), size_(0) {}

    Node(std::unique_ptr<Node> node) : leaf_(false), size_(0) {
      children_[0] = std::move(node);
    }

    void Insert(T key);

    void Split(std::size_t i);

    bool IsFull() const {
      return size_ == 2 * N - 1;
    }

    bool IsLeaf() const {
      return leaf_;
    }

    bool leaf_;
    std::size_t size_;
    std::array<T, 2 * N - 1> keys_;
    std::array<std::unique_ptr<Node>, 2 * N> children_;
  };

  Bayer() : root_(std::unique_ptr<Node>(new Node())) {
  }

  void Insert(T key);

 private:
  std::unique_ptr<Node> root_;
};

template <typename T, std::size_t N>
void Bayer<T, N>::Insert(T key) {
  using std::swap;
  if (root_->IsFull()) {
    root_ = std::unique_ptr<Node>(new Node(std::move(root_)));
    root_.Split(0);
  }
  root_.Insert(std::move(key));
}

template <typename T, std::size_t N>
void Bayer<T, N>::Node::Insert(T key) {
  using std::swap;
  if (IsLeaf()) {
    auto i = size_;
    while (i > 0 && keys_[i - 1] > key) {
      swap(keys_[i], keys_[i - 1]);
      --i;
    }
    swap(keys_[i], key);
    ++size_;
  } else {
    auto i = size_;
    while (i > 0 && keys_[i - 1] > key) --i;
    if (children_[i + 1]->IsFull()) {
      Split(i + 1);
      if (keys_[i + 1] < key) ++i;
    }
    children_[i + 1]->Insert(std::move(key));
  }
}

template <typename T, std::size_t N>
void Bayer<T, N>::Node::Split(std::size_t i) {
  using std::swap;
  assert(!IsFull());
  auto& child = children_[i];
  assert(child->IsFull());
  auto node = std::unique_ptr<Node>(new Node(child->IsLeaf()));
  for (std::size_t j = 0; j < N - 1; ++j) {
    swap(node->keys_[j], child->keys_[N + j]);
  }
  for (std::size_t j = 0; j < N; ++j) {
    swap(node->children_[j], child->children_[N + j]);
  }
  node->size_ = N - 1;
  child->size_ = N - 1;
  for (std::size_t j = size_ + 1; j > i + 1; --j) {
    swap(children_[j], children_[j - 1]);
  }
  swap(children_[i + 1], std::move(node));
  for (std::size_t j = size_; j > i; --j) {
    swap(keys_[j], keys_[j - 1]);
  }
  swap(keys_[i], child->keys_[N - 1]);
  ++size_;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_BAYER_H_
