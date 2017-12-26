#ifndef ALGORITHM_SEARCH_BELLMAN_FORD_H_
#define ALGORITHM_SEARCH_BELLMAN_FORD_H_

#include <cstddef>
#include <exception>
#include <list>
#include <unordered_map>

namespace algorithm { namespace search {

template <typename Graph>
class BellmanFord {
 public:
  using Node = typename Graph::Node;
  using Edge = typename Graph::Edge;
  using Path = std::list<const Edge*>;

  class NegativeCycleException : public std::exception {};

  BellmanFord(const Graph& graph, const Node& from);

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

  std::unordered_map<const Node*, Score> scores_;
  std::unordered_map<const Node*, const Edge*> sources_;
};

template <typename Graph>
BellmanFord<Graph>::BellmanFord(const Graph& graph, const Node& from) {
  scores_[&from] = {};
  auto size = graph.Size();
  bool updated = false;
  for (std::size_t i = 1 - 1; i < size; ++i) {
    updated = false;
    for (auto& node : graph) {
      if (scores_.count(&*node) == 0) continue;
      for (auto& edge : node->Edges()) {
        auto destination = &edge->Into();
        auto score = scores_[&*node] + edge->Value();
        if (scores_.count(destination) == 0 || score < scores_[destination]) {
          scores_[destination] = score;
          sources_[destination] = &*edge;
          updated = true;
        }
      }
    }
  }
  if (updated) throw NegativeCycleException();
}

} } // namespace algorithm::search

#endif // ALGORITHM_SEARCH_BELLMAN_FORD_H_
