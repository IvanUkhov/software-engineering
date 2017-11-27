#include <algorithm>
#include <utility>

#include "fixture.h"
#include "gtest/gtest.h"
#include "algorithm/sort/heap.h"

using namespace algorithm::sort;

const int kCount = 100;

TEST(SortTest, BinaryHeap) {
  const std::vector<int> data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end());

  std::vector<int> actual = BinaryHeap<int>(std::move(data));
  ASSERT_EQ(actual, expected);
}
