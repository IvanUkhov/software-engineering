#ifndef STRUCTURE_TREE_TRIE_H_
#define STRUCTURE_TREE_TRIE_H_

#include <string>

namespace structure { namespace tree {

template <typename T, T empty = T()>
class Trie {
 public:
  typedef std::string Key;

  void Insert(const Key& key, T value);
  T Search(const Key& key);
};

template <typename T, T empty>
void Trie<T, empty>::Insert(const Key& key, T value) {
}

template <typename T, T empty>
T Trie<T, empty>::Search(const Key& key) {
  return empty;
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_TRIE_H_
