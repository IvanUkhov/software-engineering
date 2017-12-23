#include <algorithm>

#include "problem/nested_permutations.h"

std::vector<std::size_t> problem::NestedPermutations(std::string small,
                                                     std::string big) {
  auto small_size = small.size(), big_size = big.size();
  std::sort(small.begin(), small.end());
  std::vector<std::size_t> result;
  for (std::size_t i = 0; i + small_size <= big_size; ++i) {
    auto candidate = big.substr(i, small_size);
    std::sort(candidate.begin(), candidate.end());
    if (small == candidate) result.push_back(i);
  }
  return result;
}
