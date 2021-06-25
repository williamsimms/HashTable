#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <utility>

using std::move;

template <typename T>
class Node {
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const Node<U>& node);

 public:
  T data;
  Node<T>* previous;
  Node<T>* next;

  explicit Node(T data, Node<T>* previous = nullptr, Node<T>* next = nullptr);
  Node(const Node<T>&);
  Node(Node<T>&&);
  ~Node();
  T Data() const;
  void SetData(T data);
  void SetNext(Node<T>* next);
  void Print();
  void SetPrevious(Node<T>* previous);
  void StepForward(int amountToStepForward);
  void StepBackward(int amountToStepForward);

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

  Node<T>& operator=(const Node<T>& rhs);
  Node<T>& operator=(Node<T>&& rhs);
};

template <typename T>
Node<T>::Node(T data, Node<T>* previous, Node<T>* next)
    : data{move(data)}, previous{move(previous)}, next{move(next)} {}

template <typename T>
Node<T>::~Node() = default;

template <typename T>
Node<T>::Node(const Node<T>&) = default;

template <typename T>
Node<T>::Node(Node<T>&&) = default;

template <typename T>
T Node<T>::Data() const {
  return this->data;
}

template <typename T>
Node<T>& Node<T>::operator=(const Node<T>& rhs) = default;

template <typename T>
Node<T>& Node<T>::operator=(Node<T>&& rhs) = default;

template <typename T>
void Node<T>::SetPrevious(Node<T>* previousNode) {
  this->previous = previousNode;
}

template <typename T>
void Node<T>::SetNext(Node<T>* nextNode) {
  this->next = nextNode;
}

template <typename T>
void Node<T>::SetData(T newData) {
  this->data = newData;
}

template <typename T>
void Node<T>::StepForward(int amountToStepForward) {
  int counter = 0;

  while (counter < amountToStepForward && this->next != nullptr) {
    *this = *next;
    counter++;
  }
}

template <typename T>
void Node<T>::StepBackward(int amountToStepForward) {
  int counter = 0;

  while (counter < amountToStepForward && this->previous != nullptr) {
    *this = *previous;
    counter++;
  }
}

template <typename T>
void Node<T>::Print() {
  std::cout << this->data << std::endl;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
  os << node.GetData();
  return os;
}

#endif