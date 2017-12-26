#include "algorithm/search/bellman_ford.h"
#include "gtest/gtest.h"
#include "structure/graph/adjacency_list.h"

using Graph = structure::graph::AdjacencyList<const char*, int>;
using Itinerary = algorithm::search::BellmanFord<Graph>;

TEST(SearchTest, BellmanFordSuccess) {
  Graph graph;
  auto& a = graph.AddNode("a");
  auto& b = graph.AddNode("b");
  auto& c = graph.AddNode("c");
  auto& d = graph.AddNode("d");
  auto& e = graph.AddNode("e");
  auto& ab = graph.AddEdge(a, b, -1);
  auto& ac = graph.AddEdge(a, c, 4);
  auto& bc = graph.AddEdge(b, c, 3);
  auto& bd = graph.AddEdge(b, d, 2);
  auto& be = graph.AddEdge(b, e, 2);
  auto& db = graph.AddEdge(d, b, 1);
  auto& dc = graph.AddEdge(d, c, 5);
  auto& ed = graph.AddEdge(e, d, -3);

  Itinerary::Path expected = {&ab, &be, &ed};
  auto itinerary = Itinerary(graph, a);
  auto actual = itinerary.Search(d);
  ASSERT_EQ(actual, expected);
}

TEST(SearchTest, BellmanFordFailure) {
  Graph graph;
  auto& a = graph.AddNode("a");
  auto& b = graph.AddNode("b");
  auto& c = graph.AddNode("c");
  auto& d = graph.AddNode("d");
  auto& ab = graph.AddEdge(a, b, 1);
  auto& bc = graph.AddEdge(b, c, 1);
  auto& cd = graph.AddEdge(c, d, 1);
  auto& db = graph.AddEdge(d, b, -3);

  try {
    Itinerary(graph, a);
    ASSERT_TRUE(false);
  } catch (Itinerary::NegativeCycleException) {
  }
}
