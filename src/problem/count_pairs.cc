#include <unordered_set>

#include "problem/count_pairs.h"

std::vector<std::pair<int, int>> problem::CountPairs(
    const std::vector<int>& values, int k) {
  std::unordered_set<int> set;
  std::vector<std::pair<int, int>> result;
  for (auto value : values) {
    if (set.count(k + value) > 0) result.push_back({value, k + value});
    if (set.count(value - k) > 0) result.push_back({value - k, value});
    set.insert(value);
  }
  return result;
}
