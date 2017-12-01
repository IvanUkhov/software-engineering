#include "algorithm/sort/merge.h"
#include "assess.h"

TEST(SortTest, Merge) {
  assess::Sort<int>(algorithm::sort::Merge<int>);
}
