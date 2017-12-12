#ifndef STRUCTURE_GRAPH_ADJACENCY_LIST_H_
#define STRUCTURE_GRAPH_ADJACENCY_LIST_H_

#include <algorithm>
#include <iterator>
#include <list>
#include <memory>
#include <unordered_set>
#include <vector>

namespace structure { namespace graph {

template <typename N, typename E>
class AdjacencyList {
 public:
  class Node;
  class Edge;
  class Iterator;
  class BreadthIterator;
  class DepthIterator;

  Node& AddNode(N value = N()) {
    nodes_.push_back(std::unique_ptr<Node>(new Node(std::move(value))));
    return *nodes_.back().get();
  }

  Edge& AddEdge(Node& from, Node& into, E value = E()) {
    return from.AddEdge(into, std::move(value));
  }

  void RemoveNode(Node& node) {
    nodes_.erase(std::find_if(nodes_.begin(), nodes_.end(),
                              [&node] (const auto& other) {
                                return node == *other.get();
                              }));
  }

  void RemoveEdge(Node& from, Node& into) {
    from.RemoveEdge(into);
  }

  bool HasEdge(const Node& from, const Node& into) const {
    return from.FindEdge(into) != nullptr;
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

  template <typename I = DepthIterator>
  auto begin() {
    return I(*this);
  }

  template <typename I = DepthIterator>
  auto end() {
    return I();
  }

 private:
  Node(N value) : value_(std::move(value)) {}

  Edge& AddEdge(Node& into, E value) {
    auto edge = FindEdge(into);
    if (edge) edge->value_ = std::move(value);
    else {
      children_.push_back(std::unique_ptr<Edge>(new Edge(*this, into,
                                                         std::move(value))));
      edge = children_.back().get();
      into.parents_.push_back(edge);
    }
    return *edge;
  }

  void RemoveEdge(Node& into) {
    auto iterator = std::find_if(children_.begin(), children_.end(),
                                 [&into](const auto& edge) {
                                   return into == edge->into_;
                                 });
    auto edge = iterator->get();
    auto& parents = edge->into_.parents_;
    parents.erase(std::find(parents.begin(), parents.end(), edge));
    children_.erase(iterator);
  }

  Edge* FindEdge(const Node& into) const {
    auto iterator = std::find_if(children_.begin(), children_.end(),
                                 [&into](const auto& edge) {
                                   return into == edge->into_;
                                 });
    if (iterator == children_.end()) return nullptr;
    else return iterator->get();
  }

  bool operator==(const Node& other) const {
    return this == &other;
  }

  N value_;
  std::vector<Edge*> parents_;
  std::vector<std::unique_ptr<Edge>> children_;
};

template <typename N, typename E>
class AdjacencyList<N, E>::Edge {
  friend class Node;
  friend class BreadthIterator;
  friend class DepthIterator;

 public:
  E& Value() {
    return value_;
  }

 private:
  Edge(Node& from, Node& into, E value)
      : from_(from), into_(into), value_(std::move(value)) {}

  bool operator==(const Edge& other) const {
    return this == &other;
  }

  Node& from_;
  Node& into_;
  E value_;
};

template <typename N, typename E>
class AdjacencyList<N, E>::Iterator
    : public std::iterator<std::input_iterator_tag, Node> {
 public:
  Iterator() = default;

  Iterator(Node& node) {
    stack_.push_front(&node);
  }

  Node& operator*() {
    return *stack_.front();
  }

  bool operator!=(const Iterator& other) {
    return !stack_.empty() || !other.stack_.empty();
  }

 protected:
  void PushBack(Node* node) {
    if (!Visited(node)) stack_.push_back(node);
  }

  void PushFront(Node* node) {
    if (!Visited(node)) stack_.push_front(node);
  }

  Node* PopFront() {
    auto node = stack_.front();
    visited_.insert(node);
    do stack_.pop_front();
    while (!stack_.empty() && Visited(stack_.front()));
    return node;
  }

 private:
  bool Visited(Node* node) const {
    return visited_.count(node) > 0;
  }

  std::list<Node*> stack_;
  std::unordered_set<Node*> visited_;
};

template <typename N, typename E>
class AdjacencyList<N, E>::BreadthIterator : public Iterator {
 public:
  BreadthIterator() = default;
  BreadthIterator(Node& node) : Iterator(node) {}

  BreadthIterator& operator++() {
    auto node = this->PopFront();
    for (auto& edge : node->children_) this->PushBack(&edge->into_);
    return *this;
  }
};

template <typename N, typename E>
class AdjacencyList<N, E>::DepthIterator : public Iterator {
 public:
  DepthIterator() = default;
  DepthIterator(Node& node) : Iterator(node) {}

  DepthIterator& operator++() {
    auto node = this->PopFront();
    auto iterator = node->children_.rbegin();
    while (iterator != node->children_.rend()) {
      this->PushFront(&(*iterator)->into_);
      ++iterator;
    }
    return *this;
  }
};

} } // namespace structure::graph

#endif // STRUCTURE_GRAPH_ADJACENCY_LIST_H_
