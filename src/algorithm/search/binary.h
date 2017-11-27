#ifndef ALGORITHM_SEARCH_BINARY_H_
#define ALGORITHM_SEARCH_BINARY_H_

namespace algorithm { namespace search {

template <typename T>
int Binary(const std::vector<T>& data, T value) {
  typename std::vector<T>::size_type size = data.size();
  int i = 0, j = (int)size;
  while (i < j) {
    int k = i + (j - i) / 2;
    if (data[k] < value) {
      i = k + 1;
    } else if (data[k] > value) {
      j = k;
    } else {
      return k;
    }
  }
  return -1;
}

} } // namespace algorithm::search

#endif // ALGORITHM_SEARCH_BINARY_H_
