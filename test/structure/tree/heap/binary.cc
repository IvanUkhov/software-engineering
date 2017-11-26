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
  std::sort(expected.begin(), expected.end());

  Binary heap((std::vector<int>(data)));
  std::vector<int> actual = drain(heap);
  ASSERT_EQ(actual, expected);
}

std::vector<int> drain(Binary& heap) {
  std::vector<int> data;
  while (heap.Size() > 0) {
    data.push_back(heap.Pop());
  }
  return data;
}

std::vector<int> generate(size_t count) {
  std::vector<int> data;
  data.reserve(count);
  for (size_t i = 0; i < count; i++) {
    data.push_back(std::rand());
  }
  return data;
}
