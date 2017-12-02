#include "algorithm/sort/count.h"
#include "assess.h"

const unsigned kLimit = 20;

void Count(std::vector<unsigned>& data) {
  algorithm::sort::Count(data, kLimit);
}

TEST(SortTest, Count) {
  assess::Sort<unsigned>(Count, kLimit);
}
