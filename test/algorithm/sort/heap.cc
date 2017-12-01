#include "algorithm/sort/heap.h"
#include "assess.h"

template <typename T>
void BinaryHeap(std::vector<T>& given) {
  std::vector<T> data;
  std::swap(data, given);
  auto before = &data[0];
  data = algorithm::sort::BinaryHeap<T>(std::move(data));
  auto after = &data[0];
  ASSERT_EQ(before, after);
  std::swap(data, given);
}

TEST(SortTest, BinaryHeap) {
  assess::Sort<int>(BinaryHeap);
}
