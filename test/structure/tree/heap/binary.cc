#include <algorithm>
#include <ctime>

#include "gtest/gtest.h"
#include "structure/tree/heap/binary.h"

const std::size_t kCount = 100;

std::vector<int> Drain(Binary& heap);
std::vector<int> Generate(std::size_t count);

TEST(BinaryTest, New) {
  std::srand(std::time(0));
  const std::vector<int> data = Generate(kCount);
  std::vector<int> expected((std::vector<int>(data)));
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Binary heap((std::vector<int>(data)));
  std::vector<int> actual = Drain(heap);
  ASSERT_EQ(actual, expected);
}

TEST(BinaryTest, Push) {
  std::srand(std::time(0));
  const std::vector<int> data = Generate(kCount);
  std::vector<int> expected((std::vector<int>(data)));
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Binary heap;
  for (std::size_t i = 0; i < kCount; i++) {
    heap.Push(data[i]);
  }
  std::vector<int> actual = Drain(heap);
  ASSERT_EQ(actual, expected);
}

std::vector<int> Drain(Binary& heap) {
  std::size_t size = heap.Size();
  std::vector<int> data;
  data.reserve(size);
  for (std::size_t i = 0; i < size; i++) {
    data.push_back(heap.Pop());
  }
  return data;
}

std::vector<int> Generate(std::size_t size) {
  std::vector<int> data;
  data.reserve(size);
  for (std::size_t i = 0; i < size; i++) {
    data.push_back(std::rand());
  }
  return data;
}
