#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <utility>

template <typename K, typename V>
class Node {
  template <typename W, typename X>
  friend std::ostream& operator<<(std::ostream& os, const Node<W, X>& node);

 public:
  V data;
  Node<K, V>* previous;
  Node<K, V>* next;

  explicit Node(V data,
                Node<K, V>* previous = nullptr,
                Node<K, V>* next = nullptr);
  Node(const Node<K, V>&);
  Node(Node<K, V>&&);
  ~Node();
  V Data() const;
  void SetData(V data);
  void SetNext(Node<K, V>* next);
  void Print();
  void SetPrevious(Node<K, V>* previous);

  bool operator==(const Node& rhs) const {
    if (this->data == rhs.data) {
      return true;
    }

    return false;
  }

  bool operator>(const Node& rhs) const {
    if (this->data > rhs.data) {
      return true;
    }

    return false;
  }

  bool operator<(const Node& rhs) const {
    if (this->data < rhs.data) {
      return true;
    }

    return false;
  }

  Node<K, V>& operator=(const Node<K, V>& rhs);
  Node<K, V>& operator=(Node<K, V>&& rhs);
};

template <typename K, typename V>
Node<K, V>::Node(V data, Node<K, V>* previous, Node<K, V>* next)
    : data{std::move(data)},
      previous{std::move(previous)},
      next{std::move(next)} {}

template <typename K, typename V>
Node<K, V>::~Node() = default;

template <typename K, typename V>
Node<K, V>::Node(const Node<K, V>&) = default;

template <typename K, typename V>
Node<K, V>::Node(Node<K, V>&&) = default;

template <typename K, typename V>
V Node<K, V>::Data() const {
  return this->data;
}

template <typename K, typename V>
Node<K, V>& Node<K, V>::operator=(const Node<K, V>& rhs) = default;

template <typename K, typename V>
Node<K, V>& Node<K, V>::operator=(Node<K, V>&& rhs) = default;

template <typename K, typename V>
void Node<K, V>::SetPrevious(Node<K, V>* previousNode) {
  this->previous = previousNode;
}

template <typename K, typename V>
void Node<K, V>::SetNext(Node<K, V>* nextNode) {
  this->next = nextNode;
}

template <typename K, typename V>
void Node<K, V>::SetData(V newData) {
  this->data = newData;
}

template <typename K, typename V>
void Node<K, V>::Print() {
  std::cout << this->data << std::endl;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const Node<K, V>& node) {
  os << node.GetData();
  return os;
}

#endif