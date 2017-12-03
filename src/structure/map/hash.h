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
  Hash() : buckets_(kStartBreadth), size_(0) {}

  V* Get(K key) const {
    return buckets_[Index(key)].Get(std::move(key));
  }

  void Set(K key, V value) {
    if (ShouldResize()) Resize();
    if (buckets_[Index(key)].Set(std::move(key), std::move(value))) ++size_;
  }

  double Load() const {
    return static_cast<double>(Size()) / static_cast<double>(Breadth());
  }

  std::size_t Breadth() const {
    return buckets_.size();
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
    Node(K key, V value) : key(std::move(key)), value(std::move(value)) {}

    K key;
    V value;
    std::unique_ptr<Node> next;
  };

  class Bucket {
   public:
    V* Get(K key) const;
    bool Set(K key, V value);

   private:
    std::unique_ptr<Node> root_;
  };

  void Resize();

  H hash_;
  std::vector<Bucket> buckets_;
  std::size_t size_;
};

template <typename K, typename V, typename H>
void Hash<K, V, H>::Resize() {
}

template <typename K, typename V, typename H>
V* Hash<K, V, H>::Bucket::Get(K key) const {
  const auto* current_ptr = &root_;
  while (true) {
    const auto& current = *current_ptr;
    if (!current) break;
    if (current->key == key) return &current->value;
    current_ptr = &current->next;
  }
  return nullptr;
}

template <typename K, typename V, typename H>
bool Hash<K, V, H>::Bucket::Set(K key, V value) {
  using std::swap;
  auto* current_ptr = &root_;
  while (true) {
    auto& current = *current_ptr;
    if (!current) {
      current.reset(new Node(std::move(key), std::move(value)));
      return true;
    }
    if (current->key == key) {
      swap(current->value, value);
      return false;
    }
    current_ptr = &current->next;
  }
}

} } // namespace structure::map

#endif // STRUCTURE_MAP_HASH_H_
