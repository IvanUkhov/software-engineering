#ifndef ALGORITHM_SORT_BUCKET_H_
#define ALGORITHM_SORT_BUCKET_H_

#include <cstddef>
#include <functional>
#include <vector>

namespace algorithm { namespace sort {

template <typename T>
void Bucket(std::vector<T>& data, std::size_t granularity,
            std::function<std::size_t(const T&)> map) {
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_BUCKET_H_
