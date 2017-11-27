#ifndef STRUCTURE_TREE_SEARCH_BINARY_H_
#define STRUCTURE_TREE_SEARCH_BINARY_H_

#include <memory>

namespace structure { namespace tree { namespace search {

class Binary {
 public:
  struct Node {
    Node(int value) : value(value) {}

    int value;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
  };

  void Insert(int value);
  std::shared_ptr<Node> root() const;

 private:
  std::shared_ptr<Node> root_;
};

} } } // namespace structure::tree::search

#endif // STRUCTURE_TREE_SEARCH_BINARY_H_
