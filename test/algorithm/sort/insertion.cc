#include "algorithm/sort/assess.h"
#include "algorithm/sort/insertion.h"

TEST(SortTest, Insertion) {
  algorithm::sort::Assess<int>(algorithm::sort::Insertion);
}
