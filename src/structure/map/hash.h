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
    return static_cast<double>(Size()) / static_cast<double>(Breadth());
  }

  std::size_t Breadth() const {
    return nodes_.size();
  }

  std::size_t Size() const {
    return size_;
  }

 protected:
  bool ShouldResize() const {
    return Load() > kResizeThreshold;
  }

  std::size_t Index(K key) const {
    return hash_(std::move(key)) % Breadth();
  }

 private:
  struct Node {
   public:
    Node(K key, V value)
      : key(std::move(key)), value(std::move(value)) {}

    K key;
    V value;
    std::unique_ptr<Node> next;
  };

  void Resize();

  H hash_;
  std::size_t size_;
  std::vector<std::unique_ptr<Node>> nodes_;
};

template <typename K, typename V, typename H>
V* Hash<K, V, H>::Get(K key) const {
  const auto* current_ptr = &nodes_[Index(key)];
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
  using std::swap;
  if (ShouldResize()) Resize();
  auto* current_ptr = &nodes_[Index(key)];
  while (true) {
    auto& current = *current_ptr;
    if (!current) {
      current.reset(new Node(std::move(key), std::move(value)));
      ++size_;
      return;
    }
    if (current->key == key) {
      swap(current->value, value);
      return;
    }
    current_ptr = &current->next;
  }
}

template <typename K, typename V, typename H>
void Hash<K, V, H>::Resize() {
}

} } // namespace structure::map

#endif // STRUCTURE_MAP_HASH_H_
