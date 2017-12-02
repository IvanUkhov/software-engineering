#include "algorithm/sort/merge.h"
#include "assess.h"

template <typename T>
void Merge(std::vector<T>& data) {
  std::vector<T> work;
  algorithm::sort::Merge(data, work);
}

TEST(SortTest, Merge) {
  assess::Sort<int>(Merge);
}
