#include <cmath>

#include "algorithm/search/a_star.h"
#include "gtest/gtest.h"
#include "structure/graph/adjacency_list.h"

typedef structure::graph::AdjacencyList<unsigned, double> Graph;
typedef algorithm::search::AStar<Graph, Graph::Node, Graph::Edge> Itinerary;

const double kHorizontal = 1.0;
const double kVertical = 1.0;
const double kDiagonal = std::sqrt(
    kHorizontal * kHorizontal + kVertical * kVertical);

double Euclidean(double x1, double y1, double x2, double y2) {
  return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Heuristic(const Graph::Node& node) {
  auto row = (node.Value() - 1) / 4 + 1;
  auto column = node.Value() - 4 * (row - 1);
  return Euclidean(row, column, 4, 4);
}

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
  auto& edge12 = graph.AddEdge(node1, node2, kHorizontal);
  auto& edge15 = graph.AddEdge(node1, node5, kVertical);
  auto& edge16 = graph.AddEdge(node1, node6, kDiagonal);
  auto& edge23 = graph.AddEdge(node2, node3, kHorizontal);
  auto& edge34 = graph.AddEdge(node3, node4, kHorizontal);
  auto& edge48 = graph.AddEdge(node4, node8, kVertical);
  auto& edge59 = graph.AddEdge(node5, node9, kVertical);
  auto& edge67 = graph.AddEdge(node6, node7, kHorizontal);
  auto& edge610 = graph.AddEdge(node6, node10, kVertical);
  auto& edge611 = graph.AddEdge(node6, node11, kDiagonal);
  auto& edge812 = graph.AddEdge(node8, node12, kVertical);
  auto& edge913 = graph.AddEdge(node9, node13, kVertical);
  auto& edge1314 = graph.AddEdge(node13, node14, kHorizontal);
  auto& edge1415 = graph.AddEdge(node14, node15, kHorizontal);
  auto& edge1516 = graph.AddEdge(node15, node16, kHorizontal);

  Itinerary::Path expected = {
    &edge15, &edge59, &edge913, &edge1314, &edge1415, &edge1516};
  auto actual = Itinerary::Find(graph, node1, node16, Heuristic);
  ASSERT_EQ(actual, expected);
}
