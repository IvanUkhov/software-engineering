#include "algorithm/sort/count.h"
#include "assess.h"

const std::size_t kRange = 20;

template <typename T>
void Count(std::vector<T>& data) {
  algorithm::sort::Count(data, kRange);
}

TEST(SortTest, Count) {
  assess::Sort<std::size_t>(Count, kRange);
}
