#ifndef INTERVIEW_STRUCTURE_TREE_SEARCH_BINARY_H_
#define INTERVIEW_STRUCTURE_TREE_SEARCH_BINARY_H_

struct Node;

class Binary {
 public:
  ~Binary();

  void Insert(int value);
  bool Query();
  Node* root() const;

 private:
  Node* root_ = nullptr;
};

struct Node {
  Node(int value);
  ~Node();

  int value;
  Node* left = nullptr;
  Node* right = nullptr;
};

#endif // INTERVIEW_STRUCTURE_TREE_SEARCH_BINARY_H_
