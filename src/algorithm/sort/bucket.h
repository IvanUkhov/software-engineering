#ifndef ALGORITHM_SORT_BUCKET_H_
#define ALGORITHM_SORT_BUCKET_H_

#include <algorithm>
#include <cstddef>
#include <functional>
#include <vector>

#include "algorithm/sort/insertion.h"

namespace algorithm { namespace sort {

template <typename T, void Sort(std::vector<T>&) = Insertion<T>>
void Bucket(std::vector<T>& data, std::size_t granularity,
            std::function<std::size_t(const T&)> map) {
  std::vector<std::vector<T>> buckets(granularity);
  for (auto& value : data) buckets[map(value) % granularity].push_back(value);
  auto iterator = data.begin();
  for (auto& bucket : buckets) {
    Sort(bucket);
    std::copy(bucket.begin(), bucket.end(), iterator);
    iterator += bucket.size();
  }
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_BUCKET_H_
