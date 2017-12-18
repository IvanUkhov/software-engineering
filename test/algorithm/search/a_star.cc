#include "algorithm/search/a_star.h"
#include "gtest/gtest.h"
#include "structure/graph/adjacency_list.h"

typedef structure::graph::AdjacencyList<unsigned, unsigned> Graph;
typedef algorithm::search::AStar<Graph, Graph::Node, Graph::Edge> Itinerary;

TEST(SearchTest, AStar) {
  Graph graph;
  auto& node1 = graph.AddNode(1);
  auto& node2 = graph.AddNode(2);
  auto& node3 = graph.AddNode(3);
  auto& node4 = graph.AddNode(4);
  auto& node5 = graph.AddNode(5);
  auto& node6 = graph.AddNode(6);
  auto& node7 = graph.AddNode(7);
  auto& node8 = graph.AddNode(8);
  auto& node9 = graph.AddNode(9);
  auto& node10 = graph.AddNode(10);
  auto& node11 = graph.AddNode(11);
  auto& node12 = graph.AddNode(12);
  auto& node13 = graph.AddNode(13);
  auto& node14 = graph.AddNode(14);
  auto& node15 = graph.AddNode(15);
  auto& node16 = graph.AddNode(16);
  auto& edge12 = graph.AddEdge(node1, node2, 1);
  auto& edge15 = graph.AddEdge(node1, node5, 1);
  auto& edge16 = graph.AddEdge(node1, node6, 1);
  auto& edge23 = graph.AddEdge(node2, node3, 1);
  auto& edge34 = graph.AddEdge(node3, node4, 1);
  auto& edge48 = graph.AddEdge(node4, node8, 1);
  auto& edge59 = graph.AddEdge(node5, node9, 1);
  auto& edge67 = graph.AddEdge(node6, node7, 1);
  auto& edge610 = graph.AddEdge(node6, node10, 1);
  auto& edge611 = graph.AddEdge(node6, node11, 1);
  auto& edge812 = graph.AddEdge(node8, node12, 1);
  auto& edge913 = graph.AddEdge(node9, node13, 1);
  auto& edge1314 = graph.AddEdge(node13, node14, 1);
  auto& edge1415 = graph.AddEdge(node14, node15, 1);
  auto& edge1516 = graph.AddEdge(node15, node16, 1);

  Itinerary::Path expected = {
    &edge15, &edge59, &edge913, &edge1314, &edge1415, &edge1516};
  auto actual = Itinerary::Find(
      graph, node1, node16, [](const auto& node) {
        return 0.0;
      });
}
