#ifndef STRUCTURE_GRAPH_ADJACENCY_LIST_H_
#define STRUCTURE_GRAPH_ADJACENCY_LIST_H_

#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>

namespace structure { namespace graph {

template <typename N, typename E>
class AdjacencyList {
 public:
  class Node;
  class Edge;
  class DepthIterator;

  Node* AddNode(N value) {
    nodes_.push_back(std::unique_ptr<Node>(new Node(std::move(value))));
    return nodes_.back().get();
  }

  Edge* AddEdge(Node* from, Node* into, E value) {
    return from->AddEdge(into, std::move(value));
  }

  void RemoveNode(Node* node) {
    nodes_.erase(std::find_if(nodes_.begin(), nodes_.end(),
                              [node] (const auto& other) {
                                return other.get() == node;
                              }));
  }

  void RemoveEdge(Edge* edge) {
    edge->from->RemoveEdge(edge->into);
  }

  void RemoveEdge(Node* from, Node* into) {
    from->RemoveEdge(into);
  }

  Node* FindNode(const N& value) const {
    auto iterator = std::find_if(nodes_.begin(), nodes_.end(),
                                 [&value] (const auto& node) {
                                   return node->value_ == value;
                                 });
    if (iterator == nodes_.end()) return nullptr;
    else return (*iterator).get();
  }

  Edge* FindEdge(const Node* from, const Node* into) const {
    return from->FindEdge(into);
  }

  bool Connected(const Node* one, const Node* another) const {
    return one->FindEdge(another) || another->FindEdge(one);
  }

 private:
  std::vector<std::unique_ptr<Node>> nodes_;
};

template <typename N, typename E>
class AdjacencyList<N, E>::Node {
  friend class AdjacencyList;

 public:
  N& Value() {
    return value_;
  }

 private:
  Node(N value) : value_(std::move(value)) {}

  Edge* AddEdge(Node* into, E value) {
    auto edge = FindEdge(into);
    if (edge) {
      edge->value_ = std::move(value);
    } else {
      children_.push_back(
          std::unique_ptr<Edge>(new Edge(std::move(value), this, into)));
      edge = children_.back().get();
      into->parents_.push_back(edge);
    }
    return edge;
  }

  void RemoveEdge(Node* into) {
    auto iterator = std::find_if(children_.begin(), children_.end(),
                                 [into](const auto& edge) {
                                   return edge->into_ == into;
                                 });
    auto edge = iterator->get();
    auto& parents = edge->into_->parents_;
    parents.erase(std::find(parents.begin(), parents.end(), edge));
    children_.erase(iterator);
  }

  Edge* FindEdge(const Node* into) const {
    auto iterator = std::find_if(children_.begin(), children_.end(),
                                 [into](const auto& edge) {
                                   return edge->into_ == into;
                                 });
    if (iterator == children_.end()) return nullptr;
    else return iterator->get();
  }

  N value_;
  std::vector<Edge*> parents_;
  std::vector<std::unique_ptr<Edge>> children_;
};

template <typename N, typename E>
class AdjacencyList<N, E>::Edge {
  friend class Node;

 public:
  E& Value() {
    return value_;
  }

 private:
  Edge(E value, Node* from, Node* into)
      : value_(std::move(value)), from_(from), into_(into) {}

  E value_;
  Node* const from_;
  Node* const into_;
};

template <typename N, typename E>
class AdjacencyList<N, E>::DepthIterator
    : public std::iterator<std::input_iterator_tag, Node> {
 public:
  DepthIterator() : graph_(nullptr) {}
  DepthIterator(const AdjacencyList& graph) : graph_(&graph) {}

  DepthIterator& operator++() {
    return *this;
  }

  Node& operator*() {
    return *(Node*)(1);
  }

  bool operator!=(const DepthIterator& other) {
    return false;
  }

 private:
  const AdjacencyList* graph_;
};

template <typename N, typename E,
          typename I = typename AdjacencyList<N, E>::DepthIterator>
auto begin(const AdjacencyList<N, E>& graph) {
  return I(graph);
}

template <typename N, typename E,
          typename I = typename AdjacencyList<N, E>::DepthIterator>
auto end(const AdjacencyList<N, E>& graph) {
  return I();
}

} } // namespace structure::graph

#endif // STRUCTURE_GRAPH_ADJACENCY_LIST_H_
