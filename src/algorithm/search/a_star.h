#ifndef ALGORITHM_SEARCH_A_STAR_H_
#define ALGORITHM_SEARCH_A_STAR_H_

#include <cmath>
#include <functional>
#include <list>
#include <type_traits>
#include <unordered_map>
#include <utility>

#include "structure/tree/heap.h"

namespace algorithm { namespace search {

template <typename Graph>
class AStar {
 public:
  using Node = typename Graph::Node;
  using Edge = typename Graph::Edge;
  using Path = std::list<const Edge*>;

  static Path Search(const Graph& graph, const Node& from, const Node& into,
                     std::function<double(const Node&)> estimate);

 private:
  struct Runner {
    double Score() const {
      return past + future;
    }

    double past;
    double future;
    const Node* node;
    const Edge* edge;
  };

  struct Comparator {
    bool operator()(const Runner& one, const Runner& another) const {
      return one.Score() < another.Score();
    }
  };
};

template <typename Graph>
typename AStar<Graph>::Path AStar<Graph>::Search(
    const Graph& graph, const Node& from, const Node& into,
    std::function<double(const Node&)> estimate) {
  structure::tree::BinaryHeap<Runner, Comparator> open_queue;
  std::unordered_map<const Node*, double> open_map;
  std::unordered_map<const Node*, Runner> closed;
  open_queue.Push({0.0, 0.0, &from, nullptr});
  open_map[&from] = 0.0;
  const Edge* found = nullptr;
  while (!found && !open_queue.IsEmpty()) {
    auto current_runner = open_queue.Pop();
    open_map.erase(current_runner.node);
    for (auto& edge : current_runner.node->Edges()) {
      auto& node = edge->Into();
      if (node == into) {
        found = &*edge;
        break;
      }
      Runner new_runner = {
        current_runner.past + std::abs(static_cast<double>(edge->Value())),
        std::abs(estimate(node)), &node, &*edge};
      if (open_map.count(&node) > 0 &&
          open_map[&node] < new_runner.Score()) continue;
      if (closed.count(&node) > 0 &&
          closed[&node].Score() < new_runner.Score()) continue;
      open_map[&node] = new_runner.Score();
      open_queue.Push(std::move(new_runner));
    }
    closed[current_runner.node] = std::move(current_runner);
  }
  std::list<const Edge*> path;
  while (found) {
    path.push_front(found);
    found = closed[&found->From()].edge;
  }
  return path;
}

} } // namespace algorithm::search

#endif // ALGORITHM_SEARCH_A_STAR_H_
