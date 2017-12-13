#include "algorithm/search/dijkstra.h"
#include "gtest/gtest.h"
#include "structure/graph/adjacency_list.h"

typedef structure::graph::AdjacencyList<unsigned, unsigned> Graph;
typedef algorithm::search::Dijkstra<Graph, Graph::Node, Graph::Edge> Itinerary;

TEST(SearchTest, Dijkstra) {
  Graph graph;
  auto& node1 = graph.AddNode(1);
  auto& node2 = graph.AddNode(2);
  auto& node3 = graph.AddNode(3);
  auto& node4 = graph.AddNode(4);
  auto& node5 = graph.AddNode(5);
  auto& node6 = graph.AddNode(6);
  auto& edge12 = graph.AddEdge(node1, node2, 7);
  auto& edge13 = graph.AddEdge(node1, node3, 9);
  auto& edge16 = graph.AddEdge(node1, node6, 14);
  auto& edge21 = graph.AddEdge(node2, node1, 7);
  auto& edge23 = graph.AddEdge(node2, node3, 10);
  auto& edge24 = graph.AddEdge(node2, node4, 15);
  auto& edge31 = graph.AddEdge(node3, node1, 9);
  auto& edge32 = graph.AddEdge(node3, node2, 10);
  auto& edge34 = graph.AddEdge(node3, node4, 11);
  auto& edge36 = graph.AddEdge(node3, node6, 2);
  auto& edge42 = graph.AddEdge(node4, node2, 15);
  auto& edge43 = graph.AddEdge(node4, node3, 11);
  auto& edge45 = graph.AddEdge(node4, node5, 6);
  auto& edge54 = graph.AddEdge(node5, node4, 6);
  auto& edge56 = graph.AddEdge(node5, node6, 9);
  auto& edge61 = graph.AddEdge(node6, node1, 14);
  auto& edge63 = graph.AddEdge(node6, node3, 2);
  auto& edge65 = graph.AddEdge(node6, node5, 9);

  Itinerary::Path expected = {&edge13, &edge36, &edge65};
  auto itinerary = Itinerary(graph, node1);
  auto actual = itinerary.Find(node5);
  ASSERT_EQ(actual, expected);
}
