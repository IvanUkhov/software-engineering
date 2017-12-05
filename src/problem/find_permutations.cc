#include <algorithm>

#include "problem/find_permutations.h"

std::vector<std::size_t> problem::FindPermutations(std::string s,
                                                   std::string b) {
  auto ssize = s.size(), bsize = b.size();
  std::sort(s.begin(), s.end());
  std::vector<std::size_t> result;
  for (std::size_t i = 0; i + ssize <= bsize; ++i) {
    auto candidate = b.substr(i, ssize);
    std::sort(candidate.begin(), candidate.end());
    if (s == candidate) result.push_back(i);
  }
  return result;
}
