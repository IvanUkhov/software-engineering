#include "structure/graph/adjacency_list.h"
#include "structure/graph/assess.h"

namespace structure { namespace graph {

typedef AdjacencyList<int, int> Graph;

TEST(GraphTest, AdjacencyListManipulate) {
  assess::Manipulate<Graph>();
}

TEST(GraphTest, AdjacencyListTraverseDepth) {
  assess::TraverseDepth<Graph>();
}

} } // namespace structure::graph
