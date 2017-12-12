#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "structure/tree/heap.h"

const std::size_t kCount = 100;

typedef structure::tree::MaxHeap<int> Tree;

std::vector<int> Drain(Tree& tree) {
  std::size_t size = tree.Size();
  std::vector<int> data;
  data.reserve(size);
  for (std::size_t i = 0; i < size; i++) {
    data.push_back(tree.Pop());
  }
  return data;
}

TEST(TreeTest, MaxHeapNew) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Tree tree(std::move(data));
  auto actual = Drain(tree);
  ASSERT_EQ(actual, expected);
}

TEST(TreeTest, MaxHeapPush) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Tree tree;
  for (std::size_t i = 0; i < kCount; i++) {
    tree.Push(data[i]);
  }
  auto actual = Drain(tree);
  ASSERT_EQ(actual, expected);
}
