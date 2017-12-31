#include <cassert>
#include <deque>
#include <unordered_map>
#include <unordered_set>

#include "problem/build_order.h"
#include "structure/graph/adjacency_list.h"

using Graph = structure::graph::AdjacencyList<std::size_t, bool>;

Graph Convert(const std::vector<std::size_t>& nodes,
              const std::vector<std::pair<std::size_t, std::size_t>>& edges) {
  Graph graph;
  auto size = nodes.size();
  std::unordered_map<std::size_t, std::size_t> mapping;
  for (std::size_t i = 0; i < size; ++i) {
    graph.AddNode(nodes[i]);
    mapping[nodes[i]] = i;
  }
  for (auto& edge : edges) graph.AddEdge(graph[mapping[edge.first]],
                                         graph[mapping[edge.second]]);
  return graph;
}

std::vector<std::size_t> problem::BuildOrder(
    const std::vector<std::size_t>& projects,
    const std::vector<std::pair<std::size_t, std::size_t>>& dependencies) {
  auto graph = Convert(projects, dependencies);
  std::deque<const Graph::Node*> ready;
  std::unordered_map<const Graph::Node*, std::size_t> pending;
  for (auto& node : graph) {
    auto parents = node->Parents().size();
    if (parents == 0) ready.push_back(&*node);
    else pending[&*node] = parents;
  }
  std::vector<std::size_t> schedule;
  schedule.reserve(graph.Size());
  while (!ready.empty()) {
    auto node = ready.front();
    ready.pop_front();
    schedule.push_back(node->Value());
    for (auto& edge : node->Children()) {
      auto child = &edge->Into();
      assert(pending[child] > 0);
      if (--pending[child] == 0) {
        pending.erase(child);
        ready.push_back(child);
      }
    }
  }
  if (pending.size() > 0) return {};
  else return schedule;
}
