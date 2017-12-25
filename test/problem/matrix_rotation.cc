#include "gtest/gtest.h"
#include "problem/matrix_rotation.h"

template <std::size_t size>
void Assess() {
  std::vector<int> data(size * size);
  for (std::size_t i = 0; i < size; ++i) {
    for (std::size_t j = 0; j < size; ++j) {
      data[i * size + j] = (i + 1) * (j + 1);
    }
  }
  problem::MatrixRotation(data, size);
  for (std::size_t i = 0; i < size; ++i) {
    for (std::size_t j = 0; j < size; ++j) {
      ASSERT_EQ(data[j * size + size - i - 1], (i + 1) * (j + 1));
    }
  }
}

TEST(ProblemTest, MatrixRotation) {
  Assess<10>();
  Assess<11>();
}
