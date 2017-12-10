#include "algorithm/sort/assess.h"
#include "algorithm/sort/radix.h"

const std::size_t kRange = 20;

template <typename T>
void Radix(std::vector<T>& data) {
  algorithm::sort::Radix(data, kRange);
}

TEST(SortTest, Radix) {
  algorithm::sort::Assess<std::size_t>(Radix, kRange);
}
