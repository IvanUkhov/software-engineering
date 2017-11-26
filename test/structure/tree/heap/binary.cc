#include <algorithm>
#include <cstdlib>
#include <ctime>

#include "gtest/gtest.h"
#include "structure/tree/heap/binary.h"

const size_t kCount = 100;

std::vector<int> drain(Binary& heap);
std::vector<int> generate(size_t count);

TEST(BinaryTest, New) {
  std::srand(std::time(0));
  const std::vector<int> data = generate(kCount);
  std::vector<int> expected((std::vector<int>(data)));
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Binary heap((std::vector<int>(data)));
  std::vector<int> actual = drain(heap);
  ASSERT_EQ(actual, expected);
}

TEST(BinaryTest, Push) {
  std::srand(std::time(0));
  const std::vector<int> data = generate(kCount);
  std::vector<int> expected((std::vector<int>(data)));
  std::sort(expected.begin(), expected.end(), std::greater<int>());

  Binary heap;
  for (size_t i = 0; i < kCount; i++) heap.Push(data[i]);
  std::vector<int> actual = drain(heap);
  ASSERT_EQ(actual, expected);
}

std::vector<int> drain(Binary& heap) {
  size_t size = heap.Size();
  std::vector<int> data;
  data.reserve(size);
  for (size_t i = 0; i < size; i++) data.push_back(heap.Pop());
  return data;
}

std::vector<int> generate(size_t size) {
  std::vector<int> data;
  data.reserve(size);
  for (size_t i = 0; i < size; i++) data.push_back(std::rand());
  return data;
}
