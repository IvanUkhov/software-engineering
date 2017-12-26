#include <iostream>
#include <utility>

#include "fixture.h"
#include "gtest/gtest.h"
#include "structure/tree/fenwick.h"

using Tree = structure::tree::Fenwick<int, long long>;

const std::size_t kRounds = 100;
const std::size_t kCount = 1000;

std::pair<std::size_t, std::size_t> Index(std::size_t count) {
  std::size_t i = 0, j = 0;
  while (i == j) {
    auto index = fixture::Generate<std::size_t>(2);
    i = index[0] % (count + 1);
    j = index[1] % (count + 1);
    if (i > j) std::swap(i, j);
  }
  return {i, j};
}

long long Sum(const std::vector<int>& data, std::size_t i, std::size_t j) {
  long long sum = 0;
  for (auto k = i; k < j; ++k) sum += data[k];
  return sum;
}

TEST(TreeTest, FenwickUpdate) {
  for (std::size_t i = 0; i < kRounds; ++i) {
    auto data = fixture::Generate<int>(kCount);
    auto index = Index(kCount);
    auto expected = Sum(data, index.first, index.second);
    auto actual = Tree(std::move(data)).Sum(index.first, index.second);
    ASSERT_EQ(actual, expected);
  }
}
