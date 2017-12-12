#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "structure/tree/heap.h"

using structure::tree::MaxHeap;
using structure::tree::MinHeap;

const std::size_t kCount = 100;

template <typename T>
std::vector<int> Drain(T tree) {
  std::vector<int> data;
  while (!tree.IsEmpty()) data.push_back(tree.Pop());
  return data;
}

TEST(TreeTest, MaxHeapNew) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  MaxHeap<int> tree(std::move(data));
  auto actual = Drain(tree);
  ASSERT_EQ(actual, expected);
}

TEST(TreeTest, MaxHeapPush) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  MaxHeap<int> tree;
  for (std::size_t i = 0; i < kCount; ++i) tree.Push(data[i]);
  auto actual = Drain(tree);
  ASSERT_EQ(actual, expected);
}

TEST(TreeTest, MinHeapPush) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end());

  MinHeap<int> tree(std::move(data));
  auto actual = Drain(tree);
  ASSERT_EQ(actual, expected);
}
