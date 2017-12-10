#ifndef STRUCTURE_GRAPH_ADJACENCY_LIST_H_
#define STRUCTURE_GRAPH_ADJACENCY_LIST_H_

#include <memory>
#include <unordered_map>
#include <vector>

namespace structure { namespace graph {

template <typename N, typename E>
class AdjacencyList {
 public:
  class Node;
  class Edge;

  Node* AddNode(N value) {
    return nullptr;
  }

  Edge* AddEdge(Node* from, Node* into, E value) {
    return nullptr;
  }

  Edge* FindEdge(Node* from, Node* into) const {
    return nullptr;
  }

 private:
  std::vector<std::unique_ptr<Node>> nodes_;
};

template <typename N, typename E>
class AdjacencyList<N, E>::Node {
 public:
  N& Value() {
    return value_;
  }

 private:
  N value_;
  std::vector<std::unique_ptr<Edge>> edges_;
};

template <typename N, typename E>
class AdjacencyList<N, E>::Edge {
 public:
  E& Value() {
    return value_;
  }

 private:
  E value_;
  const Node* from_;
  const Node* into_;
};

} } // namespace structure::graph

#endif // STRUCTURE_GRAPH_ADJACENCY_LIST_H_
