#ifndef STRUCTURE_MAP_HASH_H_
#define STRUCTURE_MAP_HASH_H_

#include <cstddef>
#include <functional>
#include <memory>
#include <vector>

namespace structure { namespace map {

const std::size_t kStartBreadth = 1 << 7;
const double kResizeThreshold = 0.8;

template <typename K, typename V, typename H = std::hash<K>>
class Hash {
 public:
  Hash() : size_(0), nodes_(kStartBreadth) {}

  V* Get(K key) const;
  void Set(K key, V value);

  double Load() const {
    return static_cast<double>(Size()) / Breadth();
  }

  std::size_t Breadth() const {
    return nodes_.size();
  }

  std::size_t Size() const {
    return size_;
  }

 private:
  struct Node {
    Node(K key, V value, std::size_t hash)
        : key(std::move(key)), value(std::move(value)), hash(hash) {}

    K key;
    V value;
    std::size_t hash;
    std::unique_ptr<Node> next;
  };

  void Set(std::unique_ptr<Node> candidate);

  bool ShouldResize() const {
    return Load() > kResizeThreshold;
  }

  void Resize();

  H hash_;
  std::size_t size_;
  std::vector<std::unique_ptr<Node>> nodes_;
};

template <typename K, typename V, typename H>
V* Hash<K, V, H>::Get(K key) const {
  const auto* current_ptr = &nodes_[hash_(key) % Breadth()];
  while (true) {
    const auto& current = *current_ptr;
    if (!current) break;
    if (current->key == key) return &current->value;
    current_ptr = &current->next;
  }
  return nullptr;
}

template <typename K, typename V, typename H>
void Hash<K, V, H>::Set(K key, V value) {
  if (ShouldResize()) Resize();
  auto hash = hash_(key);
  Set(std::unique_ptr<Node>(new Node(std::move(key), std::move(value), hash)));
}

template <typename K, typename V, typename H>
void Hash<K, V, H>::Set(std::unique_ptr<Node> candidate) {
  using std::swap;
  auto* current_ptr = &nodes_[candidate->hash % Breadth()];
  while (true) {
    auto& current = *current_ptr;
    if (!current) {
      swap(current, candidate);
      ++size_;
      return;
    }
    if (current->key == candidate->key) {
      swap(current, candidate);
      return;
    }
    current_ptr = &current->next;
  }
}

template <typename K, typename V, typename H>
void Hash<K, V, H>::Resize() {
  auto breadth = Breadth();
  std::vector<std::unique_ptr<Node>> nodes(2 * breadth);
  std::swap(nodes, nodes_);
  size_ = 0;
  for (auto i = 0; i < breadth; ++i) {
    while (nodes[i]) {
      auto candidate = std::unique_ptr<Node>(nodes[i].release());
      nodes[i].reset(candidate->next.release());
      Set(std::move(candidate));
    }
  }
}

} } // namespace structure::map

#endif // STRUCTURE_MAP_HASH_H_
