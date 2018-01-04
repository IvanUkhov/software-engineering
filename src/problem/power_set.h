#ifndef PROBLEM_POWER_SET_H_
#define PROBLEM_POWER_SET_H_

#include <cstddef>
#include <unordered_set>
#include <vector>

namespace problem {

template <typename T>
std::vector<std::unordered_set<T>> PowerSet(const std::vector<T>& set) {
  auto size = set.size();
  auto total = 1 << size;
  std::vector<std::unordered_set<T>> power_set;
  power_set.reserve(total);
  std::unordered_set<T> current;
  for (std::size_t i = 0; i < total; ++i) {
    power_set.push_back(current);
    for (std::size_t j = 0; j < size; ++j) {
      auto iterator = current.find(set[j]);
      if (iterator != current.end()) {
        current.erase(iterator);
      } else {
        current.insert(set[j]);
        break;
      }
    }
  }
  return power_set;
}

} // namespace problem

#endif // PROBLEM_POWER_SET_H_
