#ifndef INTERVIEW_STRUCTURE_TREE_HEAP_BINARY_H_
#define INTERVIEW_STRUCTURE_TREE_HEAP_BINARY_H_

#include <vector>

class Binary {
 public:
  Binary() {}
  Binary(std::vector<int> data);
  void Arrange();
  int Pop();
  void Push(int value);
  size_t Size() const;

 private:
  std::vector<int> data_;
};

#endif // INTERVIEW_STRUCTURE_TREE_HEAP_BINARY_H_
