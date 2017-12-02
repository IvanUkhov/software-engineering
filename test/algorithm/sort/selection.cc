#include "algorithm/sort/selection.h"
#include "assess.h"

TEST(SortTest, Selection) {
  assess::Sort<int>(algorithm::sort::Selection);
}
