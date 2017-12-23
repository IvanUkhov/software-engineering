#ifndef STRUCTURE_LIST_ASSESS_H_
#define STRUCTURE_LIST_ASSESS_H_

#include <vector>

#include "structure/list/forward.h"

namespace structure { namespace list {

template <typename T>
std::vector<T> Collect(Forward<T>& head) {
  std::vector<T> data;
  for (Forward<T>& node : head) data.push_back(node.Value());
  return data;
}

} } // namespace structure::list

#endif // STRUCTURE_LIST_ASSESS_H_
