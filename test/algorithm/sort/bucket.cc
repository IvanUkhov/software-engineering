#include "algorithm/sort/assess.h"
#include "algorithm/sort/bucket.h"

const std::size_t kGranularity = 100;

void Bucket(std::vector<double>& data) {
  algorithm::sort::Bucket<double>(data, kGranularity, [](const double& value) {
                                    return kGranularity * value;
                                  });
}

TEST(SortTest, Bucket) {
  algorithm::sort::Assess<double>(Bucket);
}
