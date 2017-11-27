#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "structure/tree/heap/binary.h"

using namespace structure::tree::heap;

const int kCount = 100;

std::vector<int> Drain(Binary<int>& heap);

TEST(HeapTest, BinaryNew) {
  const std::vector<int> data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Binary<int> heap(std::move(data));
  std::vector<int> actual = Drain(heap);
  ASSERT_EQ(actual, expected);
}

TEST(HeapTest, BinaryPush) {
  const std::vector<int> data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Binary<int> heap;
  for (int i = 0; i < kCount; i++) {
    heap.Push(data[i]);
  }
  std::vector<int> actual = Drain(heap);
  ASSERT_EQ(actual, expected);
}

std::vector<int> Drain(Binary<int>& heap) {
  int size = heap.Size();
  std::vector<int> data;
  data.reserve(size);
  for (int i = 0; i < size; i++) {
    data.push_back(heap.Pop());
  }
  return data;
}
