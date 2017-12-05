#ifndef ASSESS_H_
#define ASSESS_H_

#include <algorithm>
#include <cstddef>
#include <vector>

#include "fixture.h"
#include "gtest/gtest.h"

namespace assess {

const std::size_t kCount = 100;

template <typename T>
void Sort(void perform(std::vector<T>&), T range = 1000) {
  const auto data = fixture::Modulo(fixture::Generate<T>(kCount), range);
  std::vector<T> expected(data);
  std::sort(expected.begin(), expected.end());
  std::vector<T> actual(data);
  perform(actual);
  ASSERT_EQ(actual, expected);
}

} // namespace assess

#endif // ASSESS_H_
