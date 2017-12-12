#ifndef STRUCTURE_GRAPH_ASSESS_H_
#define STRUCTURE_GRAPH_ASSESS_H_

#include <type_traits>
#include <utility>

#include "gtest/gtest.h"

namespace structure { namespace graph { namespace assess {

template <typename T>
void Manipulate() {
  T graph;
  auto node0 = graph.AddNode(0);
  auto node1 = graph.AddNode(1);
  auto node2 = graph.AddNode(2);
  auto node3 = graph.AddNode(3);
  auto node4 = graph.AddNode(4);
  auto node5 = graph.AddNode(5);
  graph.AddEdge(node0, node1);
  graph.AddEdge(node0, node2);
  graph.AddEdge(node0, node5);
  graph.AddEdge(node1, node2);
  graph.AddEdge(node1, node3);
  graph.AddEdge(node2, node3);
  graph.AddEdge(node2, node5);
  graph.AddEdge(node3, node4);
  graph.AddEdge(node4, node5);

  ASSERT_TRUE(graph.Connected(node0, node5));
  graph.RemoveEdge(node0, node5);
  ASSERT_FALSE(graph.Connected(node0, node5));
  graph.RemoveNode(node0);
  ASSERT_EQ(graph.FindNode(0), nullptr);
}

template <typename T>
void TraverseBreadth() {
  typedef typename std::remove_reference<decltype(
      std::declval<typename T::Node>().Value())>::type N;

  T graph;
  auto node0 = graph.AddNode(0);
  auto node1 = graph.AddNode(1);
  auto node2 = graph.AddNode(2);
  auto node3 = graph.AddNode(3);
  auto node4 = graph.AddNode(4);
  auto node5 = graph.AddNode(5);
  graph.AddEdge(node0, node1);
  graph.AddEdge(node0, node4);
  graph.AddEdge(node0, node5);
  graph.AddEdge(node1, node3);
  graph.AddEdge(node1, node4);
  graph.AddEdge(node2, node1);
  graph.AddEdge(node3, node2);
  graph.AddEdge(node3, node4);

  std::vector<N> data;
  auto root = graph.FindNode(0);
  auto iterator = root->template begin<typename T::BreadthIterator>();
  auto end = root->template end<typename T::BreadthIterator>();
  for (; iterator != end; ++iterator) data.push_back((*iterator).Value());
  // ASSERT_EQ(data, std::vector<N>({0, 1, 4, 5, 3, 2}));
}

template <typename T>
void TraverseDepth() {
  typedef typename std::remove_reference<decltype(
      std::declval<typename T::Node>().Value())>::type N;

  T graph;
  auto node0 = graph.AddNode(0);
  auto node1 = graph.AddNode(1);
  auto node2 = graph.AddNode(2);
  auto node3 = graph.AddNode(3);
  auto node4 = graph.AddNode(4);
  auto node5 = graph.AddNode(5);
  graph.AddEdge(node0, node1);
  graph.AddEdge(node0, node4);
  graph.AddEdge(node0, node5);
  graph.AddEdge(node1, node3);
  graph.AddEdge(node1, node4);
  graph.AddEdge(node2, node1);
  graph.AddEdge(node3, node2);
  graph.AddEdge(node3, node4);

  std::vector<N> data;
  for (auto& node : *graph.FindNode(0)) data.push_back(node.Value());
  ASSERT_EQ(data, std::vector<N>({0, 1, 3, 2, 4, 5}));
}

} } } // namespace structure::graph::assess

#endif // STRUCTURE_GRAPH_ASSESS_H_
