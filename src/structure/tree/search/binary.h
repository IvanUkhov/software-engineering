#ifndef INTERVIEW_STRUCTURE_TREE_SEARCH_BINARY_H_
#define INTERVIEW_STRUCTURE_TREE_SEARCH_BINARY_H_

#include <memory>

struct Node;

class Binary {
 public:
  void Insert(int value);
  Node* root() const;

 private:
  std::unique_ptr<Node> root_;
};

struct Node {
  Node(int value) : value(value) {}

  int value;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
};

#endif // INTERVIEW_STRUCTURE_TREE_SEARCH_BINARY_H_
