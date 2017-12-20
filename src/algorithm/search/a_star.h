#ifndef ALGORITHM_SEARCH_A_STAR_H_
#define ALGORITHM_SEARCH_A_STAR_H_

#include <functional>
#include <list>
#include <type_traits>
#include <unordered_map>
#include <utility>

#include "structure/tree/heap.h"

namespace algorithm { namespace search {

template <typename Graph,
          typename Node = typename Graph::Node,
          typename Edge = typename Graph::Edge>
class AStar {
 public:
  using Path = std::list<const Edge*>;

  static Path Find(const Graph& graph, const Node& from, const Node& into,
                   std::function<double(const Node&)> appraise);

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

  AStar() {
    static_assert(std::is_unsigned<typename std::remove_reference<decltype(
                      std::declval<Edge>().Value())>::type>::value,
                  "AStart requires unsigned integers");
  }
};

template <typename Graph, typename Node, typename Edge>
typename AStar<Graph, Node, Edge>::Path AStar<Graph, Node, Edge>::Find(
    const Graph& graph, const Node& from, const Node& into,
    std::function<double(const Node&)> appraise) {
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
        current_runner.past + edge->Value(), appraise(node), &node, &*edge};
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
