#include <iostream>

#include "gtest/gtest.h"
#include "problem/rotate_matrix.h"

namespace internal {

using std::size_t;

template <size_t size>
void Test() {
  int plain_data[size][size];
  int* data[size];
  for (size_t i = 0; i < size; ++i) data[i] = plain_data[i];
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      data[i][j] = (i + 1) * (j + 1);
    }
  }
  problem::RotateMatrix(data, size);
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      ASSERT_EQ(data[j][size - i - 1], (i + 1) * (j + 1));
    }
  }
}

} // namespace internal

TEST(ProblemTest, RotateMatrix) {
  internal::Test<10>();
  internal::Test<11>();
}
