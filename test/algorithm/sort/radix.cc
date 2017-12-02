#include "algorithm/sort/radix.h"
#include "assess.h"

const unsigned kLimit = 20;

template <typename T>
void Radix(std::vector<T>& data) {
  algorithm::sort::Radix(data, kLimit);
}

TEST(SortTest, Radix) {
  assess::Sort<unsigned int>(Radix, kLimit);
}
