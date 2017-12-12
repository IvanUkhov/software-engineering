#include "algorithm/sort/assess.h"
#include "algorithm/sort/heap.h"

template <typename T>
void Heap(std::vector<T>& given) {
  std::vector<T> data;
  std::swap(data, given);
  auto before = &data[0];
  data = algorithm::sort::Heap(std::move(data));
  auto after = &data[0];
  ASSERT_EQ(before, after);
  std::swap(data, given);
}

TEST(SortTest, Heap) {
  algorithm::sort::Assess<int>(Heap);
}
