#include <algorithm>

#include "gtest/gtest.h"
#include "problem/nested_permutation.h"

TEST(ProblemTest, NestedPermutation) {
  const std::vector<std::size_t> expected = {0, 6, 9, 11, 12, 20, 21};
  auto actual = problem::NestedPermutation("abbc", "cbabadcbbabbcbabaabccbabc");
  std::sort(actual.begin(), actual.end());
  ASSERT_EQ(actual, expected);
}
