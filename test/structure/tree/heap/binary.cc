#include <algorithm>
#include <ctime>

#include "gtest/gtest.h"
#include "structure/tree/heap/binary.h"

using namespace interview::structure::tree::heap;

const int kCount = 100;

std::vector<int> Drain(Binary<int>& heap);
std::vector<int> Generate(int count);

TEST(BinaryTest, New) {
  std::srand(std::time(0));
  const std::vector<int> data = Generate(kCount);
  std::vector<int> expected((std::vector<int>(data)));
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Binary<int> heap((std::vector<int>(data)));
  std::vector<int> actual = Drain(heap);
  ASSERT_EQ(actual, expected);
}

TEST(BinaryTest, Push) {
  std::srand(std::time(0));
  const std::vector<int> data = Generate(kCount);
  std::vector<int> expected((std::vector<int>(data)));
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

std::vector<int> Generate(int size) {
  std::vector<int> data;
  data.reserve(size);
  for (int i = 0; i < size; i++) {
    data.push_back(std::rand());
  }
  return data;
}
