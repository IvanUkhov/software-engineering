#ifndef ALGORITHM_SORT_ASSESS_H_
#define ALGORITHM_SORT_ASSESS_H_

#include <algorithm>
#include <cstddef>
#include <vector>

#include "fixture.h"
#include "gtest/gtest.h"

namespace algorithm { namespace sort {

const std::size_t kCount = 100;

template <typename T>
void Assess(void perform(std::vector<T>&), T range = 1000) {
  const auto data = fixture::Modulo(fixture::Generate<T>(kCount), range);
  std::vector<T> expected(data);
  std::sort(expected.begin(), expected.end());
  std::vector<T> actual(data);
  perform(actual);
  ASSERT_EQ(actual, expected);
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_ASSESS_H_
