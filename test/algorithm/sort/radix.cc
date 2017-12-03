#include "algorithm/sort/radix.h"
#include "assess.h"

const std::size_t kLimit = 20;

template <typename T>
void Radix(std::vector<T>& data) {
  algorithm::sort::Radix(data, kLimit);
}

TEST(SortTest, Radix) {
  assess::Sort<std::size_t>(Radix, kLimit);
}
