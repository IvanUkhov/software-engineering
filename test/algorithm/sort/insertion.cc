#include "algorithm/sort/insertion.h"
#include "assess.h"

TEST(SortTest, Insertion) {
  assess::Sort<int>(algorithm::sort::Insertion<int>);
}
