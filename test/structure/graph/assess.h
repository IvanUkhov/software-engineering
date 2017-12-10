#ifndef STRUCTURE_GRAPH_ASSESS_H_
#define STRUCTURE_GRAPH_ASSESS_H_

#include "gtest/gtest.h"

namespace structure { namespace graph {

template <typename T>
void Assess() {
  T graph;
  auto node0 = graph.AddNode(0);
  auto node1 = graph.AddNode(0);
  auto node2 = graph.AddNode(0);
  auto node3 = graph.AddNode(0);
  auto node4 = graph.AddNode(0);
  auto node5 = graph.AddNode(0);
  graph.AddEdge(node0, node1, 0);
  graph.AddEdge(node0, node2, 0);
  graph.AddEdge(node0, node5, 0);
  graph.AddEdge(node1, node2, 0);
  graph.AddEdge(node1, node3, 0);
  graph.AddEdge(node2, node3, 0);
  graph.AddEdge(node2, node5, 0);
  graph.AddEdge(node3, node4, 0);
  graph.AddEdge(node4, node5, 0);
}

} } // namespace structure::graph

#endif // STRUCTURE_GRAPH_ASSESS_H_
