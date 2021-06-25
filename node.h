#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <utility>

template <typename K, typename V>
class Node {
  template <typename W, typename X>
  friend std::ostream& operator<<(std::ostream& os, const Node<W, X>& node);

 public:
  K key;
  V value;
  Node<K, V>* previous;
  Node<K, V>* next;

  explicit Node(V value,
                Node<K, V>* previous = nullptr,
                Node<K, V>* next = nullptr);
  Node(const Node<K, V>&);
  Node(Node<K, V>&&);
  ~Node();
  V Data() const;
  void SetData(V value);
  void SetNext(Node<K, V>* next);
  void Print();
  void SetPrevious(Node<K, V>* previous);

  bool operator==(const Node& rhs) const {
    if (this->value == rhs.value) {
      return true;
    }

    return false;
  }

  bool operator>(const Node& rhs) const {
    if (this->value > rhs.value) {
      return true;
    }

    return false;
  }

  bool operator<(const Node& rhs) const {
    if (this->value < rhs.value) {
      return true;
    }

    return false;
  }

  Node<K, V>& operator=(const Node<K, V>& rhs);
  Node<K, V>& operator=(Node<K, V>&& rhs);
};

template <typename K, typename V>
Node<K, V>::Node(V value, Node<K, V>* previous, Node<K, V>* next)
    : value{std::move(value)},
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
  return this->value;
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
  this->value = newData;
}

template <typename K, typename V>
void Node<K, V>::Print() {
  std::cout << this->value << std::endl;
}

template <typename K, typename V>
std::ostream& operator<<(std::ostream& os, const Node<K, V>& node) {
  os << node.GetData();
  return os;
}

#endif