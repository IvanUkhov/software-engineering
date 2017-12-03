#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "algorithm/search/binary.h"

using namespace algorithm::search;

const std::size_t kCount = 100;

TEST(SearchTest, Binary) {
  auto data = fixture::Generate<int>(kCount);
  std::sort(data.begin(), data.end());

  for (std::size_t i = 0; i < kCount; i++) {
    int j = Binary(data, data[i]);
    ASSERT_TRUE(j >= 0 && j < kCount);
    ASSERT_EQ(data[i], data[j]);
  }
}
