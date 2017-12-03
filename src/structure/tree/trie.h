#ifndef STRUCTURE_TREE_TRIE_H_
#define STRUCTURE_TREE_TRIE_H_

#include <memory>
#include <string>
#include <unordered_map>
#include <utility>

namespace structure { namespace tree {

template <typename T, T empty = T()>
class Trie {
 public:
  typedef std::string Key;
  typedef std::string::value_type Symbol;

  struct Node {
   public:
     Node(T value = empty) : value(std::move(value)) {}

     T value;
     std::unordered_map<Symbol, std::unique_ptr<Node>> children;
  };

  void Insert(const Key& key, T value);
  T Search(const Key& key);

 private:
  Node root;
};

template <typename T, T empty>
void Trie<T, empty>::Insert(const Key& key, T value) {
  using std::swap;
  auto current = &root;
  for (auto symbol : key) {
    auto& child = current->children[symbol];
    if (!child) child = std::unique_ptr<Node>(new Node());
    current = child.get();
  }
  swap(current->value, value);
}

template <typename T, T empty>
T Trie<T, empty>::Search(const Key& key) {
  auto current = &root;
  for (auto symbol : key) {
    auto child = current->children.find(symbol);
    if (child == current->children.end()) return empty;
    current = child->second.get();
  }
  return current->value;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_TRIE_H_
