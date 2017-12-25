#include <algorithm>
#include <cmath>
#include <cstddef>
#include <vector>

#include "gtest/gtest.h"
#include "problem/median_tracker.h"

const double kEpsilon = 1e-10;
const std::size_t kRoundCount = 10;

template <typename T>
void Assess(std::vector<T> data, double median) {
  for (std::size_t i = 0; i < kRoundCount; ++i) {
    std::random_shuffle(data.begin(), data.end());
    problem::MedianTracker<T> tracker;
    for (auto number : data) tracker.Consume(number);
    ASSERT_LT(std::abs(tracker.Compute() - median), kEpsilon);
  }
}

TEST(ProblemTest, TrackMedian) {
  Assess<int>({1, 3, 3, 6, 7, 8, 9}, 6.0);
  Assess<int>({1, 2, 3, 4, 5, 6, 8, 9}, 4.5);
}
