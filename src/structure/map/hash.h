#ifndef STRUCTURE_MAP_HASH_H_
#define STRUCTURE_MAP_HASH_H_

#include <cstddef>
#include <functional>
#include <memory>
#include <vector>

namespace structure { namespace map {

template <typename K, typename V, typename hash = std::hash<K>>
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

 private:
  class Bucket {
  };

  void Resize();

  std::vector<Bucket> buckets_;
  std::size_t size_;
};

template <typename K, typename V, typename hash>
void Hash<K, V, hash>::Insert(K key, V value) {
  ++size_;
}

template <typename K, typename V, typename hash>
void Hash<K, V, hash>::Resize() {
}

} } // namespace structure::map

#endif // STRUCTURE_MAP_HASH_H_
