#include "algorithm/sort/assess.h"
#include "algorithm/sort/quick.h"

TEST(SortTest, Quick) {
  algorithm::sort::Assess<int>(algorithm::sort::Quick);
}
