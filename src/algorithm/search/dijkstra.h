#ifndef ALGORITHM_SEARCH_DIJKSTRA_H_
#define ALGORITHM_SEARCH_DIJKSTRA_H_

#include <cstddef>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include "structure/tree/heap.h"

namespace algorithm { namespace search {

template <typename Graph,
          typename Node = typename Graph::Node,
          typename Edge = typename Graph::Edge>
std::vector<std::pair<Node*, Edge*>> Dijkstra(const Graph& graph,
                                              const Node& from,
                                              const Node& into) {
  static_assert(std::is_unsigned<typename std::remove_reference<decltype(
                    std::declval<Edge>().Value())>::type>::value,
                "Weights should be non-negative");
  typedef std::pair<std::size_t, const Node*> Runner;
  struct Comparator {
    bool operator()(const Runner& one, const Runner& another) const {
      return one.first < another.first;
    }
  };
  std::unordered_map<const Node*, std::size_t> shortest;
  std::unordered_map<const Node*, const Node*> previous;
  structure::tree::BinaryHeap<Runner, Comparator> remaining;
  remaining.Push({0, &from});
  return {};
}

} } // namespace algorithm::search

#endif // ALGORITHM_SEARCH_DIJKSTRA_H_
