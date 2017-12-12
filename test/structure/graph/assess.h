#ifndef STRUCTURE_GRAPH_ASSESS_H_
#define STRUCTURE_GRAPH_ASSESS_H_

#include <type_traits>
#include <utility>

#include "gtest/gtest.h"

namespace structure { namespace graph { namespace assess {

template <typename T>
void Manipulate() {
  T graph;
  auto node0 = graph.AddNode();
  auto node1 = graph.AddNode();
  auto node2 = graph.AddNode();
  auto node3 = graph.AddNode();
  auto node4 = graph.AddNode();
  auto node5 = graph.AddNode();
  graph.AddEdge(node0, node1);
  graph.AddEdge(node0, node2);
  graph.AddEdge(node0, node5);
  graph.AddEdge(node1, node2);
  graph.AddEdge(node1, node3);
  graph.AddEdge(node2, node3);
  graph.AddEdge(node2, node5);
  graph.AddEdge(node3, node4);
  graph.AddEdge(node4, node5);

  ASSERT_TRUE(graph.HasEdge(node0, node5));
  graph.RemoveEdge(node0, node5);
  ASSERT_FALSE(graph.HasEdge(node0, node5));
  graph.RemoveNode(node0);
}

template <typename T>
void TraverseBreadth() {
  T graph;
  auto node0 = graph.AddNode();
  auto node1 = graph.AddNode();
  auto node2 = graph.AddNode();
  auto node3 = graph.AddNode();
  auto node4 = graph.AddNode();
  auto node5 = graph.AddNode();
  graph.AddEdge(node0, node1);
  graph.AddEdge(node0, node4);
  graph.AddEdge(node0, node5);
  graph.AddEdge(node1, node3);
  graph.AddEdge(node1, node4);
  graph.AddEdge(node2, node1);
  graph.AddEdge(node3, node2);
  graph.AddEdge(node3, node4);

  std::vector<typename T::Node*> expected = {
      node0, node1, node4, node5, node3, node2};
  std::vector<typename T::Node*> actual;
  auto iterator = node0->template begin<typename T::BreadthIterator>();
  auto end = node0->template end<typename T::BreadthIterator>();
  for (; iterator != end; ++iterator) actual.push_back(&*iterator);
  // ASSERT_EQ(actual, expected);
}

template <typename T>
void TraverseDepth() {
  T graph;
  auto node0 = graph.AddNode();
  auto node1 = graph.AddNode();
  auto node2 = graph.AddNode();
  auto node3 = graph.AddNode();
  auto node4 = graph.AddNode();
  auto node5 = graph.AddNode();
  graph.AddEdge(node0, node1);
  graph.AddEdge(node0, node4);
  graph.AddEdge(node0, node5);
  graph.AddEdge(node1, node3);
  graph.AddEdge(node1, node4);
  graph.AddEdge(node2, node1);
  graph.AddEdge(node3, node2);
  graph.AddEdge(node3, node4);

  std::vector<typename T::Node*> expected = {
      node0, node1, node3, node2, node4, node5};
  std::vector<typename T::Node*> actual;
  for (auto& node : *node0) actual.push_back(&node);
  ASSERT_EQ(actual, expected);
}

} } } // namespace structure::graph::assess

#endif // STRUCTURE_GRAPH_ASSESS_H_
