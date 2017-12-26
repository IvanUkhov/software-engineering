#ifndef ALGORITHM_SEARCH_DIJKSTRA_H_
#define ALGORITHM_SEARCH_DIJKSTRA_H_

#include <list>
#include <type_traits>
#include <unordered_map>
#include <utility>

#include "structure/tree/heap.h"

namespace algorithm { namespace search {

template <typename Graph>
class Dijkstra {
 public:
  using Node = typename Graph::Node;
  using Edge = typename Graph::Edge;
  using Path = std::list<const Edge*>;

  Dijkstra(const Graph& graph, const Node& from);

  Path Search(const Node& into) const {
    Path path;
    auto current = &into;
    while (sources_.count(current) > 0) {
      path.push_front(sources_.at(current));
      current = &path.front()->From();
    }
    return path;
  }

 private:
  using Score = typename std::remove_reference<
    decltype(std::declval<Edge>().Value())>::type;
  using Runner = std::pair<Score, const Node*>;

  std::unordered_map<const Node*, Score> scores_;
  std::unordered_map<const Node*, const Edge*> sources_;
};

template <typename Graph>
Dijkstra<Graph>::Dijkstra(const Graph& graph, const Node& from) {
  static_assert(std::is_unsigned<Score>::value,
                "Dijkstra requires unsigned integers");
  structure::tree::MinHeap<Runner> open;
  scores_[&from] = 0;
  open.Push({0, &from});
  while (!open.IsEmpty()) {
    auto current = open.Pop();
    if (current.first > scores_[current.second]) continue;
    for (auto& edge : current.second->Edges()) {
      auto destination = &edge->Into();
      auto score = current.first + edge->Value();
      if (scores_.count(destination) == 0 || score < scores_[destination]) {
        scores_[destination] = score;
        sources_[destination] = &*edge;
        open.Push({score, destination});
      }
    }
  }
}

} } // namespace algorithm::search

#endif // ALGORITHM_SEARCH_DIJKSTRA_H_
