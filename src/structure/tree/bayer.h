#ifndef STRUCTURE_TREE_BAYER_H_
#define STRUCTURE_TREE_BAYER_H_

#include <array>
#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>

namespace structure { namespace tree {

template <typename T, std::size_t D>
class Bayer {
 public:
  class Node;
  class BranchNode;
  class LeafNode;

  using Location = std::pair<const Node*, std::size_t>;

  Bayer() : root_(std::unique_ptr<Node>(new LeafNode())) {
    static_assert(D > 0, "Bayer requires a positive minimum degree");
  }

  Location Insert(T key);

  Location Search(T key) const {
    return root_->Search(std::move(key));
  }

 private:
  std::unique_ptr<Node> root_;
};

template <typename T, std::size_t D>
class Bayer<T, D>::Node {
  friend class Bayer;

 public:
  virtual ~Node() {}

 protected:
  virtual Node* New() const = 0;
  virtual Location Insert(T key) = 0;
  virtual Location Search(T key) const = 0;
  void Split(std::size_t i);

  bool IsFull() const {
    return size_ == 2 * D;
  }

  std::size_t size_ = 0;
  std::array<T, 2 * D> keys_;
  std::array<std::unique_ptr<Node>, 2 * D + 1> children_;
};

template <typename T, std::size_t D>
class Bayer<T, D>::BranchNode : public Node {
 protected:
  Node* New() const override {
    return new BranchNode();
  }

  Location Insert(T key) override;
  Location Search(T key) const override;
};

template <typename T, std::size_t D>
class Bayer<T, D>::LeafNode : public Node {
 protected:
  Node* New() const override {
    return new LeafNode();
  }

  Location Insert(T key) override;
  Location Search(T key) const override;
};

template <typename T, std::size_t D>
typename Bayer<T, D>::Location Bayer<T, D>::Insert(T key) {
  using std::swap;
  if (root_->IsFull()) {
    auto node = std::unique_ptr<Node>(new BranchNode());
    swap(root_, node);
    swap(root_->children_[0], node);
    root_->Split(0);
  }
  return root_->Insert(std::move(key));
}

template <typename T, std::size_t D>
void Bayer<T, D>::Node::Split(std::size_t i) {
  using std::swap;
  assert(!IsFull());
  auto& child = children_[i];
  assert(child->IsFull());
  auto node = std::unique_ptr<Node>(child->New());
  child->size_ = D;
  node->size_ = D - 1;
  for (std::size_t j = 0; j < D - 1; ++j) {
    swap(node->keys_[j], child->keys_[D + 1 + j]);
  }
  for (std::size_t j = 0; j < D; ++j) {
    swap(node->children_[j], child->children_[D + 1 + j]);
  }
  for (std::size_t j = size_; j > i; --j) {
    swap(keys_[j], keys_[j - 1]);
  }
  swap(keys_[i], child->keys_[D]);
  for (std::size_t j = size_ + 1; j > i + 1; --j) {
    swap(children_[j], children_[j - 1]);
  }
  swap(children_[i + 1], node);
  ++size_;
}

template <typename T, std::size_t D>
typename Bayer<T, D>::Location Bayer<T, D>::BranchNode::Insert(T key) {
  using std::swap;
  auto i = this->size_;
  while (i > 0 && this->keys_[i - 1] > key) --i;
  if (this->children_[i]->IsFull()) {
    this->Split(i);
    if (this->keys_[i] < key) ++i;
  }
  return this->children_[i]->Insert(std::move(key));
}

template <typename T, std::size_t D>
typename Bayer<T, D>::Location Bayer<T, D>::LeafNode::Insert(T key) {
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

template <typename T, std::size_t D>
typename Bayer<T, D>::Location Bayer<T, D>::BranchNode::Search(T key) const {
  std::size_t i = 0;
  while (i < this->size_ && this->keys_[i] < key) ++i;
  if (i < this->size_ && this->keys_[i] == key) return {this, i};
  return this->children_[i]->Search(std::move(key));
}

template <typename T, std::size_t D>
typename Bayer<T, D>::Location Bayer<T, D>::LeafNode::Search(T key) const {
  std::size_t i = 0;
  while (i < this->size_ && this->keys_[i] < key) ++i;
  if (i < this->size_ && this->keys_[i] == key) return {this, i};
  return {nullptr, 0};
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_BAYER_H_
