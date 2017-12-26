#include <iostream>

#include "fixture.h"
#include "gtest/gtest.h"
#include "structure/tree/fenwick.h"

using Tree = structure::tree::Fenwick<std::size_t>;

const std::size_t kRounds = 10;
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

std::size_t Sum(const std::vector<std::size_t>& data,
                std::size_t i, std::size_t j) {
  std::size_t sum = 0;
  for (auto k = i; k < j; ++k) sum += data[k];
  return sum;
}

TEST(TreeTest, FenwickAdd) {
  auto data = fixture::Modulo(fixture::Generate<std::size_t>(kCount), kCount);
  Tree tree(data);
  data[kCount / 2] += 42;
  tree.Add(kCount / 2, 42);
  ASSERT_EQ(tree.Sum(kCount), Sum(data, 0, kCount));
}

TEST(TreeTest, FenwickSum) {
  for (std::size_t i = 0; i < kRounds; ++i) {
    auto data = fixture::Modulo(fixture::Generate<std::size_t>(kCount), kCount);
    auto index = Index(kCount);
    ASSERT_EQ(Tree(data).Sum(index.first, index.second),
              Sum(data, index.first, index.second));
  }
}
