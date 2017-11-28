#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "algorithm/sort/bubble.h"

using namespace algorithm::sort;

const int kCount = 100;

TEST(SortTest, Bubble) {
  const auto data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end());

  std::vector<int> actual(std::move(data));
  Bubble<int>(actual);
  ASSERT_EQ(actual, expected);
}
