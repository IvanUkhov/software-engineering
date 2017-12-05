#include <fstream>

#include "gtest/gtest.h"
#include "problem/list_permutations.h"

std::size_t Count(std::size_t n) {
  if (n == 0) return 0;
  std::size_t count = 1;
  while (n > 1) count *= n--;
  return count;
}

TEST(ProblemTest, ListPermutations) {
  std::ofstream output("/dev/null");
  const std::string input = "abc";
  ASSERT_EQ(problem::ListPermutations(output, input), Count(input.size()));
}
