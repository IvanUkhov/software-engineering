#ifndef ALGORITHM_SORT_HEAP_H_
#define ALGORITHM_SORT_HEAP_H_

#include <utility>
#include <vector>

#include "structure/tree/heap.h"

namespace algorithm { namespace sort {

template <typename T>
std::vector<T> Heap(std::vector<T> data) {
  structure::tree::MaxHeap<T> heap(std::move(data));
  heap.Sort();
  return heap;
}

} } // namespace algorithm::sort

#endif // ALGORITHM_SORT_HEAP_H_
