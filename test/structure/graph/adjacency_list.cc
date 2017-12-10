#include "structure/graph/adjacency_list.h"
#include "structure/graph/assess.h"

namespace structure { namespace graph {

typedef AdjacencyList<int, int> Graph;

TEST(GraphTest, AdjacencyList) {
  Assess<Graph>();
}

} } // namespace structure::graph
