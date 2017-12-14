#ifndef ALGORITHM_SEARCH_DIJKSTRA_H_
#define ALGORITHM_SEARCH_DIJKSTRA_H_

#include <cstddef>
#include <list>
#include <type_traits>
#include <unordered_map>
#include <utility>

#include "structure/tree/heap.h"

namespace algorithm { namespace search {

template <typename Graph,
          typename Node = typename Graph::Node,
          typename Edge = typename Graph::Edge>
class Dijkstra {
 public:
  typedef std::list<const Edge*> Path;

  Dijkstra(const Graph& graph, const Node& from);

  Path Find(const Node& into) const {
    Path path;
    auto current = &into;
    while (sources_.count(current) > 0) {
      path.push_front(sources_.at(current));
      current = &path.front()->From();
    }
    return path;
  }

 private:
  std::unordered_map<const Node*, std::size_t> scores_;
  std::unordered_map<const Node*, const Edge*> sources_;
};

template <typename Graph, typename Node, typename Edge>
Dijkstra<Graph, Node, Edge>::Dijkstra(const Graph& graph, const Node& from) {
  static_assert(std::is_unsigned<typename std::remove_reference<decltype(
                    std::declval<Edge>().Value())>::type>::value,
                "Dijkstra requires unsigned integers");
  typedef std::pair<std::size_t, const Node*> Runner;
  struct Comparator {
    bool operator()(const Runner& one, const Runner& another) const {
      return one.first < another.first;
    }
  };
  structure::tree::BinaryHeap<Runner, Comparator> remaining;
  scores_[&from] = 0;
  remaining.Push({0, &from});
  while (!remaining.IsEmpty()) {
    auto current = remaining.Pop();
    if (current.first > scores_[current.second]) continue;
    for (auto& edge : current.second->Edges()) {
      auto destination = &edge->Into();
      auto score = current.first + edge->Value();
      if (scores_.count(destination) == 0 ||
          score < scores_[destination]) {
        scores_[destination] = score;
        sources_[destination] = &*edge;
        remaining.Push({score, destination});
      }
    }
  }
}

} } // namespace algorithm::search

#endif // ALGORITHM_SEARCH_DIJKSTRA_H_
