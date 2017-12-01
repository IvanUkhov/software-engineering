#ifndef ASSESS_H_
#define ASSESS_H_

#include <algorithm>
#include <vector>

#include "fixture.h"
#include "gtest/gtest.h"

namespace assess {

const int kCount = 100;

template <typename T>
void Sort(void perform(std::vector<T>&)) {
  const auto data = fixture::Generate<T>(kCount);
  std::vector<T> expected(data);
  std::sort(expected.begin(), expected.end());

  std::vector<T> actual(data);
  perform(actual);
  ASSERT_EQ(actual, expected);
}

} // namespace assess

#endif // ASSESS_H_
