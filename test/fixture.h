#ifndef FIXTURE_H_
#define FIXTURE_H_

#include <vector>

namespace fixture {

template <typename T>
std::vector<T> Generate(typename std::vector<T>::size_type size) {
  std::vector<T> data;
  data.reserve(size);
  for (int i = 0; i < size; i++) {
    data.push_back((T)std::rand());
  }
  return data;
}

} // namespace fixture

#endif // FIXTURE_H_
