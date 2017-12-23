#include "gtest/gtest.h"
#include "problem/matrix_rotation.h"

namespace internal {

using std::size_t;

template <size_t size>
void Test() {
  std::vector<int> data(size * size);
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      data[i * size + j] = (i + 1) * (j + 1);
    }
  }
  problem::MatrixRotation(data, size);
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      ASSERT_EQ(data[j * size + size - i - 1], (i + 1) * (j + 1));
    }
  }
}

} // namespace internal

TEST(ProblemTest, MatrixRotation) {
  internal::Test<10>();
  internal::Test<11>();
}
