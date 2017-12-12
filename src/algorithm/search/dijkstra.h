#ifndef ALGORITHM_SEARCH_DIJKSTRA_H_
#define ALGORITHM_SEARCH_DIJKSTRA_H_

#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

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
  std::unordered_map<Node*, std::size_t> shortest;
  std::unordered_map<Node*, Node*> previous;
  return {};
}

} } // namespace algorithm::search

#endif // ALGORITHM_SEARCH_DIJKSTRA_H_
