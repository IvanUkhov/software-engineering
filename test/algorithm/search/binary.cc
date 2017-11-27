#include <algorithm>
#include <ctime>

#include "fixture.h"
#include "gtest/gtest.h"
#include "algorithm/search/binary.h"

using namespace algorithm::search;

const int kCount = 100;

TEST(BinaryTest, Search) {
  std::srand(std::time(0));
  std::vector<int> data = fixture::Generate<int>(kCount);
  std::sort(data.begin(), data.end());

  for (int i = 0; i < kCount; i++) {
    int j = Binary<int>(data, data[i]);
    ASSERT_TRUE(j >= 0 && j < kCount);
    ASSERT_EQ(data[i], data[j]);
  }
}
