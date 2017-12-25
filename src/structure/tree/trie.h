#ifndef STRUCTURE_TREE_TRIE_H_
#define STRUCTURE_TREE_TRIE_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

namespace structure { namespace tree {

template <typename T>
class Trie {
 public:
  using Key = std::string;

  void Insert(const Key& key, T value);
  T* Search(const Key& key);

 private:
  using Glyph = std::string::value_type;

  struct Node {
    Node() = default;
    Node(T value) : value(std::move(value)) {}

    T value;
    std::unordered_map<Glyph, std::unique_ptr<Node>> children;
  };

  Node root;
};

template <typename T>
void Trie<T>::Insert(const Key& key, T value) {
  using std::swap;
  auto current = &root;
  for (auto glyph : key) {
    auto& child = current->children[glyph];
    if (!child) child = std::unique_ptr<Node>(new Node());
    current = child.get();
  }
  swap(current->value, value);
}

template <typename T>
T* Trie<T>::Search(const Key& key) {
  auto current = &root;
  for (auto glyph : key) {
    auto child = current->children.find(glyph);
    if (child == current->children.end()) return nullptr;
    current = child->second.get();
  }
  return &current->value;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_TRIE_H_
