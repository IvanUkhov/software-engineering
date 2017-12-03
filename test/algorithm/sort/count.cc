#include "algorithm/sort/count.h"
#include "assess.h"

const std::size_t kLimit = 20;

template <typename T>
void Count(std::vector<T>& data) {
  algorithm::sort::Count(data, kLimit);
}

TEST(SortTest, Count) {
  assess::Sort<std::size_t>(Count, kLimit);
}
