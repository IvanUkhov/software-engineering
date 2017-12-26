#ifndef FIXTURE_H_
#define FIXTURE_H_

#include <cstddef>
#include <cstdlib>
#include <vector>

namespace fixture {

void Randomize();

template <typename T>
std::vector<T> Generate(std::size_t size) {
  Randomize();
  std::vector<T> data;
  data.reserve(size);
  for (std::size_t i = 0; i < size; ++i) data.push_back(std::rand());
  return data;
}

template <>
std::vector<double> Generate<double>(std::size_t size);

template <typename T>
std::vector<T> Modulo(std::vector<T> data, T modulus) {
  for (auto& value : data) value %= modulus;
  return data;
}

} // namespace fixture

#endif // FIXTURE_H_
