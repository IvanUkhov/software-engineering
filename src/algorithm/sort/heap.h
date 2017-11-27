#ifndef ALGORITHM_SORT_HEAP_H_
#define ALGORITHM_SORT_HEAP_H_

#include <utility>

#include "structure/tree/heap/binary.h"

namespace algorithm { namespace sort {

template <typename T>
std::vector<T> BinaryHeap(std::vector<T> data) {
  structure::tree::heap::Binary<T> heap(std::move(data));
  heap.Sort();
  return heap;
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_HEAP_H_
