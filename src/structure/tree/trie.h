#ifndef STRUCTURE_TREE_TRIE_H_
#define STRUCTURE_TREE_TRIE_H_

#include <memory>
#include <string>
#include <utility>

namespace structure { namespace tree {

template <typename T, T empty = T()>
class Trie {
 public:
  typedef std::string Key;
  typedef std::string::value_type Symbol;

  struct Node {
   public:
     Node(Symbol symbol = Symbol())
       : symbol(symbol), value(empty) {}

     T value;
     Symbol symbol;
     std::unique_ptr<Node> child;
     std::unique_ptr<Node> sibling;
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
    if (!current->child) {
      auto node = std::unique_ptr<Node>(new Node(symbol));
      swap(current->child, node);
      current = current->child.get();
      continue;
    }
    current = current->child.get();
    while (current->symbol != symbol) {
      if (!current->sibling) {
        auto node = std::unique_ptr<Node>(new Node(symbol));
        swap(current->sibling, node);
        current = current->sibling.get();
        break;
      }
      current = current->sibling.get();
    }
  }
  swap(current->value, value);
}

template <typename T, T empty>
T Trie<T, empty>::Search(const Key& key) {
  auto current = &root;
  for (auto symbol : key) {
    if (!current->child) return empty;
    current = current->child.get();
    while (current->symbol != symbol) {
      if (!current->sibling) return empty;
      current = current->sibling.get();
    }
  }
  return current->value;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_TRIE_H_
