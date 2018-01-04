#include "problem/magic_index.h"

int problem::MagicIndex(const std::vector<int>& data) {
  int i = 0, j = data.size();
  while (i < j) {
    auto k = (i + j) / 2;
    if (data[k] < k) j = k;
    else if (data[k] > k) i = k + 1;
    else return k;
  }
  return -1;
}
