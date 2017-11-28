#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "algorithm/sort/heap.h"

using namespace algorithm::sort;

const int kCount = 100;

TEST(SortTest, BinaryHeap) {
  auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end());

  auto before = &data[0];
  auto actual = BinaryHeap<int>(std::move(data));
  auto after = &actual[0];
  ASSERT_EQ(actual, expected);
  ASSERT_EQ(before, after);
}
