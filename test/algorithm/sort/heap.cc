#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "algorithm/sort/heap.h"

using namespace algorithm::sort;

const int kCount = 100;

TEST(SortTest, BinaryHeap) {
  std::vector<int> data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end());

  const int* before = &data[0];
  std::vector<int> actual = BinaryHeap<int>(std::move(data));
  const int* after = &actual[0];
  ASSERT_EQ(actual, expected);
  ASSERT_EQ(before, after);
}
