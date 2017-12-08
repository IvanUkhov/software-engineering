#include "gtest/gtest.h"
#include "problem/rotate_matrix.h"

const std::size_t kSize = 10;

TEST(ProblemTest, RotateMatrix) {
  int plain_data[kSize][kSize];
  int* data[kSize];
  for (std::size_t i = 0; i < kSize; ++i) data[i] = plain_data[i];
  for (std::size_t i = 0; i < kSize; ++i) {
    for (std::size_t j = 0; j < kSize; ++j) {
      data[i][j] = (i + 1) * (j + 1);
    }
  }
  problem::RotateMatrix(data, kSize);
  for (std::size_t i = 0; i < kSize; ++i) {
    for (std::size_t j = 0; j < kSize; ++j) {
      ASSERT_EQ(data[j][kSize - i - 1], (i + 1) * (j + 1));
    }
  }
}
