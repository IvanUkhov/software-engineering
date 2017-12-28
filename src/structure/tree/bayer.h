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
  class Node;
  class BranchNode;
  class LeafNode;

  using Location = std::pair<const Node*, std::size_t>;

  Bayer() : root_(std::unique_ptr<Node>(new LeafNode())) {
    static_assert(N >= 2, "Bayer requires a degree more than or equal to 2");
  }

  Location Insert(T key);

  Location Search(T key) const {
    return root_->Search(std::move(key));
  }

 private:
  std::unique_ptr<Node> root_;
};

template <typename T, std::size_t N>
class Bayer<T, N>::Node {
  friend class Bayer;

 public:
  virtual ~Node() {}

 protected:
  virtual Node* New() const = 0;
  virtual Location Insert(T key) = 0;

  Location Search(T key) const;

  void Split(std::size_t i);

  bool IsFull() const {
    return size_ == 2 * N - 1;
  }

  std::size_t size_ = 0;
  std::array<T, 2 * N - 1> keys_;
  std::array<std::unique_ptr<Node>, 2 * N> children_;
};

template <typename T, std::size_t N>
class Bayer<T, N>::BranchNode : public Node {
 protected:
  Node* New() const override {
    return new BranchNode();
  }

  Location Insert(T key) override;
};

template <typename T, std::size_t N>
class Bayer<T, N>::LeafNode : public Node {
 protected:
  Node* New() const override {
    return new LeafNode();
  }

  Location Insert(T key) override;
};

template <typename T, std::size_t N>
typename Bayer<T, N>::Location Bayer<T, N>::Insert(T key) {
  using std::swap;
  if (root_->IsFull()) {
    auto node = std::unique_ptr<Node>(new BranchNode());
    swap(root_, node);
    swap(node->children_[0], node);
    root_->Split(0);
  }
  return root_->Insert(std::move(key));
}

template <typename T, std::size_t N>
typename Bayer<T, N>::Location Bayer<T, N>::Node::Search(T key) const {
  return {nullptr, 0};
}

template <typename T, std::size_t N>
void Bayer<T, N>::Node::Split(std::size_t i) {
  using std::swap;
  assert(!IsFull());
  auto& child = children_[i];
  assert(child->IsFull());
  auto node = std::unique_ptr<Node>(child->New());
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
  swap(children_[i + 1], node);
  for (std::size_t j = size_; j > i; --j) {
    swap(keys_[j], keys_[j - 1]);
  }
  swap(keys_[i], child->keys_[N - 1]);
  ++size_;
}

template <typename T, std::size_t N>
typename Bayer<T, N>::Location Bayer<T, N>::BranchNode::Insert(T key) {
  using std::swap;
  auto i = this->size_;
  while (i > 0 && this->keys_[i - 1] > key) --i;
  ++i;
  if (this->children_[i]->IsFull()) {
    this->Split(i);
    if (this->keys_[i] < key) ++i;
  }
  return this->children_[i]->Insert(std::move(key));
}

template <typename T, std::size_t N>
typename Bayer<T, N>::Location Bayer<T, N>::LeafNode::Insert(T key) {
  using std::swap;
  auto i = this->size_;
  while (i > 0 && this->keys_[i - 1] > key) {
    swap(this->keys_[i], this->keys_[i - 1]);
    --i;
  }
  swap(this->keys_[i], key);
  ++this->size_;
  return {this, i};
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_BAYER_H_
