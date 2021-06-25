#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <cassert>
#include <cmath>
#include <cstddef>
#include <ctime>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

#include "node.h"

using std::cout;
using std::endl;
using std::forward;
using std::initializer_list;
using std::move;
using std::ostream;
using std::string;
using std::vector;

template <typename LinkedList>
class LinkedListIterator {
 public:
  using ValueType = typename LinkedList::ValueType;
  using PointerType = ValueType*;
  using ReferenceType = ValueType&;
  using NodeType = Node<ValueType>;
  using NodePointerType = Node<ValueType>*;
  using NodeReferenceType = Node<ValueType>&;

 private:
  NodePointerType nodeItr;

 public:
  explicit LinkedListIterator(NodePointerType nodeItr) : nodeItr{nodeItr} {}

  LinkedListIterator& operator++() noexcept {
    nodeItr = nodeItr->next;
    return *this;
  }

  LinkedListIterator operator++(int) noexcept {
    LinkedListIterator temp(*this);
    nodeItr = nodeItr->next;
    return temp;
  }

  LinkedListIterator& operator--() noexcept {
    nodeItr = nodeItr->previous;
    return *this;
  }

  LinkedListIterator operator--(int) noexcept {
    LinkedListIterator temp(*this);
    nodeItr = nodeItr->previous;
    return temp;
  }

  NodePointerType operator->() const { return nodeItr; }

  NodeReferenceType operator*() const { return *nodeItr; }

  bool operator==(const LinkedListIterator& other) const {
    return nodeItr == other.nodeItr;
  }

  bool operator!=(const LinkedListIterator& other) const {
    return !(nodeItr == other.nodeItr);
  }

  operator LinkedListIterator<const LinkedList>() const {
    return LinkedListIterator<const LinkedList>(nodeItr);
  }
};

template <typename LinkedList>
class LinkedListReverseIterator {
 public:
  using ValueType = typename LinkedList::ValueType;
  using PointerType = ValueType*;
  using ReferenceType = ValueType&;
  using NodeType = Node<ValueType>;
  using NodePointerType = Node<ValueType>*;
  using NodeReferenceType = Node<ValueType>&;

 private:
  NodePointerType nodeItr;

 public:
  explicit LinkedListReverseIterator(NodePointerType nodeItr)
      : nodeItr{nodeItr} {}

  LinkedListReverseIterator& operator++() {
    nodeItr = nodeItr->previous;
    return *this;
  }

  LinkedListReverseIterator operator++(int) {
    LinkedListReverseIterator temp(*this);
    nodeItr = nodeItr->previous;
    return temp;
  }

  LinkedListReverseIterator& operator--() {
    nodeItr = nodeItr->next;
    return *this;
  }

  LinkedListReverseIterator operator--(int) {
    LinkedListReverseIterator temp(*this);
    nodeItr = nodeItr->next;
    return temp;
  }

  NodePointerType operator->() const { return nodeItr; }

  NodeReferenceType operator*() const { return *nodeItr; }

  bool operator==(const LinkedListReverseIterator& other) const {
    return nodeItr == other.nodeItr;
  }

  bool operator!=(const LinkedListReverseIterator& other) const {
    return !(nodeItr == other.nodeItr);
  }

  operator LinkedListReverseIterator<const LinkedList>() const {
    return LinkedListReverseIterator<const LinkedList>(nodeItr);
  }
};

template <typename K, typename V>
class LinkedList {
 public:
  using ValueType = V;
  using PointerType = V*;
  using ReferenceType = V&;
  using Iterator = LinkedListIterator<LinkedList<V>>;
  using ConstIterator = LinkedListIterator<const LinkedList<V>>;
  using ReverseIterator = LinkedListReverseIterator<LinkedList<V>>;
  using ConstReverseIterator = LinkedListReverseIterator<const LinkedList<V>>;

 private:
  Node<T>* head;
  Node<T>* tail;
  int length;

 public:
  LinkedList() noexcept;
  LinkedList(int size) noexcept;
  LinkedList(int size, const T& data) noexcept;
  LinkedList(const initializer_list<T>&) noexcept;
  LinkedList(const vector<T>&) noexcept;
  LinkedList(const LinkedList<T>&) noexcept;
  LinkedList(LinkedList<T>&&) noexcept;
  ~LinkedList() noexcept;

  void PushFront(const T& data) noexcept;
  void PushBack(const T& data);
  void PushAt(const T& data, int index);
  void PushMiddle(const T& data);

  void PushFront(T&& data) noexcept;
  void PushBack(T&& data);
  void PushAt(T&& data, int index);
  void PushMiddle(T&& data);

  template <typename... Args>
  void EmplaceFront(Args&&... args);

  template <typename... Args>
  void EmplaceMiddle(Args&&... args);

  template <typename... Args>
  void EmplaceBack(Args&&... args);

  template <typename... Args>
  void EmplaceAt(int index, Args&&... args);

  void Print() const noexcept;
  [[nodiscard]] int Length() const noexcept;
  [[nodiscard]] int Size() const noexcept;

  Node<T>* At(int index) const noexcept;

  [[nodiscard]] bool Empty() const noexcept;
  [[nodiscard]] bool Contains(const T& data) const noexcept;

  void PopFront();
  void PopBack();
  void PopAt(int index);

  [[nodiscard]] int Count(const T& data) const;

  bool UpdateIndex(const T& data, int index);

  bool UpdateFirst(const T& data);
  bool UpdateLast(const T& data);

  void Clear();

  int Unique();

  void Resize(int size);
  void Resize(int size, const T& dataToUse);

  bool Swap(LinkedList<T>& otherList);

  Node<T>* Front();
  Node<T>* Back();

 public:
  const Node<T>* operator[](int index) const noexcept {
    if (!this->head && !this->tail) {
      return nullptr;
    }

    if (index < 0 || index > this->length - 1) {
      return nullptr;
    }

    Node<T>* nodeAtIndex = this->GetAt(index);
    return nodeAtIndex;
  }

  Node<T>* operator[](int index) noexcept {
    if (!this->head && !this->tail) {
      return nullptr;
    }

    if (index < 0 || index > this->length - 1) {
      return nullptr;
    }

    Node<T>* nodeAtIndex = this->GetAt(index);

    return nodeAtIndex;
  }

  LinkedList<T>& operator=(const LinkedList<T>& otherList) noexcept {
    if (&otherList == this) {
      return *this;
    }

    Node<T>* otherListHeadNode = otherList.head;

    while (otherListHeadNode) {
      this->InsertLast(otherListHeadNode->data);
      otherListHeadNode = otherListHeadNode->next;
    }

    return *this;
  }

  LinkedList<T>& operator=(LinkedList<T>&& otherList) noexcept {
    if (&otherList == this) {
      return *this;
    }

    this->Clear();
    this->head = otherList.head;
    this->tail = otherList.tail;
    this->length = otherList.length;
    otherList = nullptr;
    return *this;
  }

  bool operator==(const LinkedList<T>& rhs) const {
    if (this == &rhs) {
      return true;
    }

    if (this->Size() != rhs.Size()) {
      return false;
    }

    Node<T>* otherListHeadNode = rhs.head;
    Node<T>* headNode = this->head;

    while (headNode && otherListHeadNode) {
      if (headNode->data != otherListHeadNode->data) {
        return false;
      }

      otherListHeadNode = otherListHeadNode->next;
      headNode = headNode->next;
    }

    return true;
  }

  bool operator!=(const LinkedList<T>& rhs) const { return !((*this) == rhs); }

  void operator++() {
    int currentLength = this->length;
    this->Resize(currentLength + 1);
  }

  void operator++(int) {
    int currentLength = this->length;
    this->Resize(currentLength + 1);
  }

  void operator--() {
    if (this->length == 0) {
      return;
    }

    int currentLength = this->length;
    this->Resize(currentLength - 1);
  }

  void operator--(int) {
    if (this->length == 0) {
      return;
    }

    int currentLength = this->length;
    this->Resize(currentLength - 1);
  }

  void operator+=(size_t size) {
    int currentLength = this->length;
    this->Resize(currentLength + size);
  }

  void operator-=(size_t size) {
    int currentLength = this->length;
    this->Resize(currentLength - size);
  }

  bool operator<(LinkedList<T>& otherList) const {
    return this->Size() < otherList.Size();
  }

  bool operator>(LinkedList<T>& otherList) const {
    return this->Size() > otherList.Size();
  }

  template <typename U>
  friend ostream& operator<<(ostream& os, const LinkedList<U>& list);

  Iterator begin() {
    Iterator it(this->head);
    return it;
  }

  Iterator end() {
    Iterator it(this->tail->next);
    return it;
  }

  ConstIterator cbegin() const {
    ConstIterator it(this->head);
    return it;
  }

  ConstIterator cend() const {
    ConstIterator it(this->tail->next);
    return it;
  }

  ReverseIterator rbegin() {
    ReverseIterator it(this->tail);
    return it;
  }

  ReverseIterator rend() {
    ReverseIterator it(this->head->previous);
    return it;
  }

  ConstReverseIterator crbegin() const {
    ConstReverseIterator it(this->tail);
    return it;
  }

  ConstReverseIterator crend() const {
    ConstReverseIterator it(this->head->previous);
    return it;
  }
};

template <typename T>
LinkedList<T>::LinkedList() noexcept
    : head{nullptr}, tail{nullptr}, length{0} {}

template <typename T>
LinkedList<T>::LinkedList(int size) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  this->Resize(size);
}

template <typename T>
LinkedList<T>::LinkedList(int size, const T& data) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  this->Resize(size, data);
}

template <typename T>
LinkedList<T>::LinkedList(const initializer_list<T>& list) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  this->InsertManyAtEnd(list);
}

template <typename T>
LinkedList<T>::LinkedList(const vector<T>& vector) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  this->Assign(vector);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& otherList) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  if (&otherList == this) {
    return;
  }

  Node<T>* otherListHeadNode = otherList.head;

  while (otherListHeadNode) {
    this->InsertLast(otherListHeadNode->data);
    otherListHeadNode = otherListHeadNode->next;
  }
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList&& otherList) noexcept
    : head{move(otherList.head)},
      tail{move(otherList.tail)},
      length{move(otherList.length)} {
  if (&otherList == this) {
    return;
  }

  otherList.head = nullptr;
  otherList.tail = nullptr;
  otherList.length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() noexcept {
  if (this->head != nullptr) {
    Node<T>* node = this->head;
    Node<T>* next = nullptr;

    while (node) {
      next = node->next;
      node->next = nullptr;
      node->previous = nullptr;
      delete node;
      node = next;
    }
  }

  this->head = nullptr;
  this->tail = nullptr;
  this->length = 0;
}

template <typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& list) {
  list.Print();
  return os;
}

template <typename T>
void LinkedList<T>::PushFront(const T& data) noexcept {
  if (!this->head && !this->tail) {
    Node<T>* newNode = new Node<T>(data);
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<T>* currentHead = this->head;
  Node<T>* newNode = new Node<T>(data, nullptr, currentHead);
  currentHead->previous = newNode;
  this->head = newNode;
  this->length++;
}

template <typename T>
void LinkedList<T>::PushBack(const T& data) {
  if (!this->head && !this->tail) {
    this->InsertFirst(data);
    return;
  }

  Node<T>* currentTail = this->tail;
  Node<T>* newNode = new Node<T>(data, currentTail, nullptr);
  currentTail->next = newNode;
  this->tail = newNode;
  this->length++;
}

template <typename T>
void LinkedList<T>::PushBack(T&& data) {
  if (!this->head && !this->tail) {
    Node<T>* newNode = new Node<T>(move(data));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<T>* newNode = new Node<T>(move(data), this->tail, nullptr);
  this->tail->next = newNode;
  this->tail = newNode;
  this->length++;
}

template <typename T>
void LinkedList<T>::PushAt(const T& data, int index) {
  if ((!this->head && !this->tail) || index <= 0) {
    this->InsertFirst(data);
    return;
  }

  if (index > this->length - 1) {
    this->InsertLast(data);
    return;
  }

  Node<T>* nodeAtPreviousIndex = this->GetAt(index - 1);

  Node<T>* nodeToBeReplacedAtIndex = nodeAtPreviousIndex->next;

  Node<T>* newNode =
      new Node<T>(data, nodeAtPreviousIndex, nodeToBeReplacedAtIndex);

  nodeAtPreviousIndex->next = newNode;
  nodeToBeReplacedAtIndex->previous = newNode;
  this->length++;
}

template <typename T>
void LinkedList<T>::PushMiddle(const T& data) {
  if (!this->head && !this->tail) {
    this->InsertFirst(data);
    return;
  }

  int midpointIndex = this->FindMidpointIndex();

  this->InsertAt(data, midpointIndex);
}

template <typename T>
void LinkedList<T>::PushFront(T&& data) noexcept {
  if (!this->head && !this->tail) {
    Node<T>* newNode = new Node<T>(move(data));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<T>* currentHead = this->head;
  Node<T>* newNode = new Node<T>(move(data), nullptr, currentHead);
  currentHead->previous = newNode;
  this->head = newNode;
  this->length++;
}

template <typename T>
void LinkedList<T>::PushAt(T&& data, int index) {
  if ((!this->head && !this->tail) || index <= 0) {
    this->InsertFirst(move(data));
    return;
  }

  if (index > this->length - 1) {
    this->InsertLast(move(data));
    return;
  }

  Node<T>* nodeAtPreviousIndex = this->GetAt(index - 1);

  Node<T>* nodeToBeReplacedAtIndex = nodeAtPreviousIndex->next;

  Node<T>* newNode =
      new Node<T>(move(data), nodeAtPreviousIndex, nodeToBeReplacedAtIndex);

  nodeAtPreviousIndex->next = newNode;
  nodeToBeReplacedAtIndex->previous = newNode;
  this->length++;
}

template <typename T>
int LinkedList<T>::Length() const noexcept {
  return this->length;
}

template <typename T>
int LinkedList<T>::Size() const noexcept {
  return this->length;
}

template <typename T>
Node<T>* LinkedList<T>::At(int index) const noexcept {
  if (!this->head || !this->tail) {
    return nullptr;
  }

  if (index < 0) {
    return nullptr;
  }

  if (index == 0) {
    return this->head;
  }

  if (index > this->length - 1) {
    return nullptr;
  }

  if (index == this->length - 1) {
    return this->tail;
  }

  Node<T>* node = this->head;
  int counter = 0;

  while (node->next != nullptr && counter < index) {
    node = node->next;
    counter++;
  }

  return node;
}

template <typename T>
bool LinkedList<T>::Empty() const noexcept {
  if (!this->head && !this->tail) {
    return true;
  }

  return false;
}

template <typename T>
bool LinkedList<T>::Contains(const T& data) const noexcept {
  if (!this->head && !this->tail) {
    return false;
  }

  Node<T>* node = this->head;
  while (node) {
    if (node->data == data) {
      return true;
    }

    node = node->next;
  }

  return false;
}

template <typename T>
void LinkedList<T>::PopFront() {
  if (!this->head || !this->tail) {
    return;
  }

  if (this->head->next == nullptr) {
    Node<T>* node = this->head;
    delete node;
    this->tail = nullptr;
    this->head = nullptr;
    this->length--;
    return;
  }

  Node<T>* currentHead = this->head;
  this->head = currentHead->next;
  currentHead->next = nullptr;
  currentHead->previous = nullptr;
  delete currentHead;
  this->length--;
}

template <typename T>
void LinkedList<T>::PopBack() {
  if (!this->head || !this->tail) {
    return;
  }

  if (this->tail->previous == nullptr) {
    Node<T>* node = this->tail;
    delete node;
    this->tail = nullptr;
    this->head = nullptr;
    this->length--;
    return;
  }

  Node<T>* currentTail = this->tail;
  Node<T>* nodeBeforeTail = this->tail->previous;
  nodeBeforeTail->next = nullptr;
  this->tail = nodeBeforeTail;
  currentTail->previous = nullptr;
  delete currentTail;
  this->length--;
}

template <typename T>
void LinkedList<T>::PopAt(int index) {
  if (!this->head && !this->tail) {
    return;
  }

  if (index < 0 || index > this->length - 1) {
    return;
  }

  if (index == 0) {
    this->RemoveFirst();
    return;
  }

  if (index == this->length - 1) {
    this->RemoveLast();
    return;
  }

  Node<T>* nodeAtPreviousIndex = this->GetAt(index - 1);
  Node<T>* nodeToBeRemoved = nodeAtPreviousIndex->next;
  Node<T>* nodeAfterNodeToBeRemoved = nodeToBeRemoved->next;
  nodeAtPreviousIndex->next = nodeToBeRemoved->next;
  nodeAfterNodeToBeRemoved->previous = nodeAtPreviousIndex;
  nodeToBeRemoved->next = nullptr;
  nodeToBeRemoved->previous = nullptr;
  delete nodeToBeRemoved;
  this->length--;
}

template <typename T>
int LinkedList<T>::Count(const T& data) const {
  if (!this->head && !this->tail) {
    return 0;
  }

  Node<T>* node = this->head;
  int counter = 0;

  while (node) {
    if (node->data == data) {
      counter++;
    }
    node = node->next;
  }

  return counter;
}

template <typename T>
bool LinkedList<T>::UpdateIndex(const T& data, int index) {
  if (!this->head && !this->tail) {
    return false;
  }

  if (index < 0 || index > (this->length - 1)) {
    return false;
  }

  Node<T>* nodeAtIndex = this->GetAt(index);
  nodeAtIndex->data = data;
  return true;
}

template <typename T>
bool LinkedList<T>::UpdateFirst(const T& data) {
  if (!this->head && !this->tail) {
    return false;
  }

  Node<T>* headNode = this->head;
  headNode->data = data;
  return true;
}

template <typename T>
bool LinkedList<T>::UpdateLast(const T& data) {
  if (!this->head && !this->tail) {
    return false;
  }

  Node<T>* tailNode = this->tail;
  tailNode->data = data;
  return true;
}

template <typename T>
void LinkedList<T>::Clear() {
  if (!this->head && !this->tail) {
    return;
  }

  Node<T>* node = this->head;
  Node<T>* nextNode = nullptr;

  if (node->next == nullptr) {
    delete this->head;
    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;
    return;
  }

  while (node->next != nullptr) {
    nextNode = node->next;
    node->next = nullptr;
    node->previous = nullptr;
    delete node;
    node = nextNode;
  }

  this->head = nullptr;
  this->tail = nullptr;
  this->length = 0;
}

template <typename T>
void LinkedList<T>::Print() const noexcept {
  if (!this->head && !this->tail) {
    return;
  }

  Node<T>* node = this->head;
  while (node) {
    cout << node->data;
    cout << " -> ";
    node = node->next;
  }
  cout << "nullptr" << endl;
}

template <typename T>
void LinkedList<T>::Resize(int size) {
  if (size < 0) {
    return;
  }

  if (size == 0) {
    this->Clear();
    return;
  }

  if (size > this->length) {
    int counter = this->length;

    while (counter < size) {
      this->InsertLast(T{});
      counter++;
    }

    return;
  }

  if (size < this->length) {
    int counter = this->length;

    while (counter > size) {
      this->RemoveLast();
      counter = this->length;
    }
  }
}

template <typename T>
void LinkedList<T>::Resize(int size, const T& dataToUse) {
  if (size < 0) {
    return;
  }

  if (size == 0) {
    this->Clear();
    return;
  }

  if (size > this->length) {
    int counter = this->length;

    while (counter < size) {
      this->InsertLast(dataToUse);
      counter++;
    }

    return;
  }

  if (size < this->length) {
    int counter = this->length;

    while (counter > size) {
      this->RemoveLast();
      counter = this->length;
    }
  }
}

template <typename T>
bool LinkedList<T>::Swap(LinkedList<T>& otherList) {
  if ((!this->head && !this->tail) && (!otherList.head && !otherList.tail)) {
    return false;
  }

  if (this == &otherList) {
    return false;
  }

  Node<T>* node = nullptr;
  Node<T>* otherListNode = nullptr;

  if (this->length > otherList.Size()) {
    int otherListInitialSize = otherList.Size();
    otherList.Resize(this->length);

    node = this->head;
    otherListNode = otherList.head;

    while (node != nullptr && otherListNode != nullptr) {
      T temp = node->data;
      node->data = otherListNode->data;
      otherListNode->data = temp;
      node = node->next;
      otherListNode = otherListNode->next;
    }

    this->Resize(otherListInitialSize);

    return true;
  }

  if (otherList.Size() > this->length) {
    int initialSize = this->length;
    int otherListSize = otherList.Size();

    this->Resize(otherListSize);

    node = this->head;
    otherListNode = otherList.head;

    while (node != nullptr && otherListNode != nullptr) {
      T temp = node->data;
      node->data = otherListNode->data;
      otherListNode->data = temp;
      node = node->next;
      otherListNode = otherListNode->next;
    }

    otherList.Resize(initialSize);

    return true;
  }

  if (otherList.Size() == this->length) {
    node = this->head;
    otherListNode = otherList.head;

    while (node && otherListNode) {
      T temp = node->data;
      node->data = otherListNode->data;
      otherListNode->data = temp;
      node = node->next;
      otherListNode = otherListNode->next;
    }

    return true;
  }

  return false;
}

template <typename T>
Node<T>* LinkedList<T>::Front() {
  if (!this->head && !this->tail) {
    return nullptr;
  }

  return this->head;
}

template <typename T>
Node<T>* LinkedList<T>::Back() {
  if (!this->head && !this->tail) {
    return nullptr;
  }

  return this->tail;
}

template <typename T>
template <typename... Args>
void LinkedList<T>::EmplaceBack(Args&&... args) {
  if (!this->head && !this->tail) {
    Node<T>* newNode = new Node<T>(T(forward<Args>(args)...));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<T>* newNode = new Node<T>(T(forward<Args>(args)...), this->tail);
  this->tail->next = newNode;
  this->tail = newNode;
  this->length++;
}

template <typename T>
template <typename... Args>
void LinkedList<T>::EmplaceFront(Args&&... args) {
  if (!this->head && !this->tail) {
    Node<T>* newNode = new Node<T>(T(forward<Args>(args)...));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<T>* newNode =
      new Node<T>(T(forward<Args>(args)...), nullptr, this->head);
  this->head->previous = newNode;
  this->head = newNode;
  this->length++;
}

template <typename T>
template <typename... Args>
void LinkedList<T>::EmplaceMiddle(Args&&... args) {
  if (!this->head && !this->tail) {
    Node<T>* newNode = new Node<T>(T(forward<Args>(args)...), nullptr, nullptr);
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<T>* middleNode = this->FindMidpoint();
  Node<T>* nodePreviousToMiddle = middleNode->previous;

  Node<T>* newNode =
      new Node<T>(T(forward<Args>(args)...), nodePreviousToMiddle, middleNode);
  nodePreviousToMiddle->next = newNode;
  middleNode->previous = newNode;
  this->length++;
}

template <typename T>
template <typename... Args>
void LinkedList<T>::EmplaceAt(int index, Args&&... args) {
  if (!this->head && !this->tail) {
    Node<T>* newNode = new Node<T>(T(forward<Args>(args)...), nullptr, nullptr);
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  if (index < 0) {
    return;
  }

  if (index > this->length - 1) {
    return;
  }

  Node<T>* nodeAtPreviousIndex = this->GetAt(index - 1);
  Node<T>* nodeToBeReplacedAtIndex = nodeAtPreviousIndex->next;
  Node<T>* newNode = new Node<T>(T(forward<Args>(args)...), nodeAtPreviousIndex,
                                 nodeToBeReplacedAtIndex);

  nodeAtPreviousIndex->next = newNode;
  nodeToBeReplacedAtIndex->previous = newNode;
  this->length++;
}

#endif