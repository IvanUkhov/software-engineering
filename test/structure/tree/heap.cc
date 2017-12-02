#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "structure/tree/heap.h"

const int kCount = 100;

typedef structure::tree::BinaryHeap<int> Heap;

std::vector<int> Drain(Heap& heap) {
  int size = heap.Size();
  std::vector<int> data;
  data.reserve(size);
  for (int i = 0; i < size; i++) {
    data.push_back(heap.Pop());
  }
  return data;
}

TEST(TreeTest, BinaryHeapNew) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Heap heap(std::move(data));
  auto actual = Drain(heap);
  ASSERT_EQ(actual, expected);
}

TEST(TreeTest, BinaryHeapPush) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Heap heap;
  for (int i = 0; i < kCount; i++) {
    heap.Push(data[i]);
  }
  auto actual = Drain(heap);
  ASSERT_EQ(actual, expected);
}
