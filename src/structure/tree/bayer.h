#ifndef STRUCTURE_TREE_BAYER_H_
#define STRUCTURE_TREE_BAYER_H_

#include <array>
#include <cstddef>
#include <memory>

namespace structure { namespace tree {

template <typename K, typename V, std::size_t N>
class Bayer {
 public:
  class Node {
    friend class Bayer;

   public:

   private:
    Node() : leaf_(true), size_(0) {}

    bool leaf_;
    std::size_t size_;
    std::array<K, 2 * N - 1> keys_;
    std::array<V, 2 * N - 1> values_;
    std::array<std::unique_ptr<Node>, 2 * N> children_;
  };

  Bayer() {}

  void Insert(K key, V value);

 private:
  std::unique_ptr<Node> root_;
};

template <typename K, typename V, std::size_t N>
void Bayer<K, V, N>::Insert(K key, V value) {
  auto& current = &root_;
  current = std::unique_ptr<Node>(new Node());
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_BAYER_H_
