#include "algorithm/sort/assess.h"
#include "algorithm/sort/merge.h"

template <typename T>
void Merge(std::vector<T>& data) {
  std::vector<T> work;
  algorithm::sort::Merge(data, work);
}

TEST(SortTest, Merge) {
  algorithm::sort::Assess<int>(Merge);
}
