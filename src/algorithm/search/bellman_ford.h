#ifndef ALGORITHM_SEARCH_BELLMAN_FORD_H_
#define ALGORITHM_SEARCH_BELLMAN_FORD_H_

#include <list>

#include "structure/tree/heap.h"

namespace algorithm { namespace search {

template <typename Graph>
class BellmanFord {
 public:
  using Node = typename Graph::Node;
  using Edge = typename Graph::Edge;
  using Path = std::list<const Edge*>;

  BellmanFord(const Graph& graph, const Node& from);

  Path Search(const Node& into) const {
    return {};
  }
};

template <typename Graph>
BellmanFord<Graph>::BellmanFord(const Graph& graph, const Node& from) {
}

} } // namespace algorithm::search

#endif // ALGORITHM_SEARCH_BELLMAN_FORD_H_
