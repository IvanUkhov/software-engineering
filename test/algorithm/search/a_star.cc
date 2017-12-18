#include "algorithm/search/a_star.h"
#include "gtest/gtest.h"
#include "structure/graph/adjacency_list.h"

typedef structure::graph::AdjacencyList<unsigned, unsigned> Graph;

TEST(SearchTest, AStar) {
  Graph graph;
  auto& node1 = graph.AddNode(1);
  auto& node2 = graph.AddNode(2);
  auto& edge12 = graph.AddEdge(node1, node2, 0);
  auto itinerary = algorithm::search::AStar<Graph, Graph::Node, Graph::Edge>(
      graph, node1, node2, [](const auto& node) {
        return 0.0;
      });
}
