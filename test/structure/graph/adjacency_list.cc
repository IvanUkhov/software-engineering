#include "structure/graph/adjacency_list.h"
#include "structure/graph/assess.h"

namespace structure { namespace graph {

using Graph = AdjacencyList<int, int>;

TEST(GraphTest, AdjacencyListManipulate) {
  assess::Manipulate<Graph>();
}

TEST(GraphTest, AdjacencyListTraverseBreadth) {
  assess::TraverseBreadth<Graph>();
}

TEST(GraphTest, AdjacencyListTraverseDepth) {
  assess::TraverseDepth<Graph>();
}

} } // namespace structure::graph
