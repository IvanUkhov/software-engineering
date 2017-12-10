#include "algorithm/sort/assess.h"
#include "algorithm/sort/count.h"

const std::size_t kRange = 20;

template <typename T>
void Count(std::vector<T>& data) {
  algorithm::sort::Count(data, kRange);
}

TEST(SortTest, Count) {
  algorithm::sort::Assess<std::size_t>(Count, kRange);
}
