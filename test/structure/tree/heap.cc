#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "structure/tree/heap.h"

const int kCount = 100;

typedef structure::tree::BinaryHeap<int> Tree;

std::vector<int> Drain(Tree& tree) {
  int size = tree.Size();
  std::vector<int> data;
  data.reserve(size);
  for (int i = 0; i < size; i++) {
    data.push_back(tree.Pop());
  }
  return data;
}

TEST(TreeTest, BinaryHeapNew) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Tree tree(std::move(data));
  auto actual = Drain(tree);
  ASSERT_EQ(actual, expected);
}

TEST(TreeTest, BinaryHeapPush) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Tree tree;
  for (int i = 0; i < kCount; i++) {
    tree.Push(data[i]);
  }
  auto actual = Drain(tree);
  ASSERT_EQ(actual, expected);
}
