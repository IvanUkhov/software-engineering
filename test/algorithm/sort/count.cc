#include "algorithm/sort/count.h"
#include "assess.h"

const unsigned kLimit = 20;

template <typename T>
void Count(std::vector<T>& data) {
  algorithm::sort::Count(data, kLimit);
}

TEST(SortTest, Count) {
  assess::Sort<unsigned>(Count, kLimit);
}
