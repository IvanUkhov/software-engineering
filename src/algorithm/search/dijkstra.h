#ifndef ALGORITHM_SEARCH_DIJKSTRA_H_
#define ALGORITHM_SEARCH_DIJKSTRA_H_

#include <utility>
#include <vector>

namespace algorithm { namespace search {

template <typename G,
          typename N = typename G::Node,
          typename E = typename G::Edge>
std::vector<std::pair<N*, E*>> Dijkstra(const G& graph,
                                        const N& from,
                                        const N& into) {
  return {};
}

} } // namespace algorithm::search

#endif // ALGORITHM_SEARCH_DIJKSTRA_H_
