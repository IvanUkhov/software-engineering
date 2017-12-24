#include "gtest/gtest.h"
#include "problem/fibonacci.h"

namespace internal {

void Test(std::size_t (*compute)(std::size_t)) {
  std::vector<std::size_t> expected = {0, 1, 1, 2, 3,
                                       5, 8, 13, 21, 34,
                                       55, 89, 144, 233, 377,
                                       610, 987, 1597, 2584, 4181};
  auto count = expected.size();
  std::vector<std::size_t> actual(count);
  for (std::size_t i = 0; i < count; ++i) actual[i] = compute(i);
  ASSERT_EQ(actual, expected);
}

} // namespace internal

TEST(ProblemTest, FibonacciLinear) {
  internal::Test(problem::FibonacciLinear);
}
