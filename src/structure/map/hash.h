#ifndef STRUCTURE_MAP_HASH_H_
#define STRUCTURE_MAP_HASH_H_

#include <cstddef>
#include <functional>
#include <memory>
#include <vector>

namespace structure { namespace map {

template <typename K, typename V, typename H = std::hash<K>>
class Hash {
 public:
  Hash() : buckets_(1 << 7), size_(0) {}

  void Insert(K key, V value);

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
    return Load() > 0.8;
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
    bool Insert(K key, V value);

   private:
    std::unique_ptr<Node> root_;
  };

  void Resize();

  H hash_;
  std::vector<Bucket> buckets_;
  std::size_t size_;
};

template <typename K, typename V, typename H>
void Hash<K, V, H>::Insert(K key, V value) {
  if (ShouldResize()) Resize();
  if (buckets_[Index(key)].Insert(std::move(key), std::move(value))) ++size_;
}

template <typename K, typename V, typename H>
void Hash<K, V, H>::Resize() {
}

template <typename K, typename V, typename H>
bool Hash<K, V, H>::Bucket::Insert(K key, V value) {
  using std::swap;
  std::unique_ptr<Node>* current = &root_;
  while (true) {
    std::unique_ptr<Node>& node = *current;
    if (!node) {
      node.reset(new Node(std::move(key), std::move(value)));
      return true;
    }
    if (node->key == key) {
      swap(node->value, value);
      return false;
    }
    current = &node->next;
  }
}

} } // namespace structure::map

#endif // STRUCTURE_MAP_HASH_H_
