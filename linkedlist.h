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
  using KeyType = typename LinkedList::KeyType;
  using ValueType = typename LinkedList::ValueType;
  using PointerType = ValueType*;
  using ReferenceType = ValueType&;
  using NodeType = Node<KeyType, ValueType>;
  using NodePointerType = Node<KeyType, ValueType>*;
  using NodeReferenceType = Node<KeyType, ValueType>&;

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
  using KeyType = typename LinkedList::KeyType;
  using ValueType = typename LinkedList::ValueType;
  using PointerType = ValueType*;
  using ReferenceType = ValueType&;
  using NodeType = Node<KeyType, ValueType>;
  using NodePointerType = Node<KeyType, ValueType>*;
  using NodeReferenceType = Node<KeyType, ValueType>&;

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
  using PointerValueType = V*;
  using ReferenceValueType = V&;
  using ConstValueType = const V;
  using ConstPointerValueType = const V*;
  using ConstReferenceValueType = const V&;
  using KeyType = K;
  using PointerKeyType = K*;
  using ReferenceKeyType = K&;
  using ConstKeyType = const K;
  using ConstPointerKeyType = const K*;
  using ConstReferenceKeyType = const K&;
  using Iterator = LinkedListIterator<LinkedList<K, V>>;
  using ConstIterator = LinkedListIterator<const LinkedList<K, V>>;
  using ReverseIterator = LinkedListReverseIterator<LinkedList<K, V>>;
  using ConstReverseIterator =
      LinkedListReverseIterator<const LinkedList<K, V>>;

 private:
  Node<K, V>* head;
  Node<K, V>* tail;
  int length;

 public:
  LinkedList() noexcept;
  LinkedList(int size) noexcept;
  LinkedList(int size, const V& data) noexcept;
  LinkedList(const initializer_list<V>&) noexcept;
  LinkedList(const vector<V>&) noexcept;
  LinkedList(const LinkedList<K, V>&) noexcept;
  LinkedList(LinkedList<K, V>&&) noexcept;
  ~LinkedList() noexcept;

  void PushFront(const V& data) noexcept;
  void PushBack(const V& data);
  void PushAt(const V& data, int index);
  void PushMiddle(const V& data);

  void PushFront(V&& data) noexcept;
  void PushBack(V&& data);
  void PushAt(V&& data, int index);
  void PushMiddle(V&& data);

  void InsertManyAtStart(const initializer_list<V>& data);
  void InsertManyAtEnd(const initializer_list<V>& data);

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

  Node<K, V>* At(int index) const noexcept;

  [[nodiscard]] bool Empty() const noexcept;
  [[nodiscard]] bool Contains(const V& data) const noexcept;

  void PopFront();
  void PopBack();
  void PopAt(int index);

  [[nodiscard]] int Count(const V& data) const;

  bool UpdateIndex(const V& data, int index);

  bool UpdateFirst(const V& data);
  bool UpdateLast(const V& data);

  void Clear();

  void Resize(int size);
  void Resize(int size, const V& dataToUse);

  bool Swap(LinkedList<K, V>& otherList);

  Node<K, V>* Head();
  Node<K, V>* Tail();

 public:
  const Node<K, V>* operator[](int index) const noexcept {
    if (!this->head && !this->tail) {
      return nullptr;
    }

    if (index < 0 || index > this->length - 1) {
      return nullptr;
    }

    Node<K, V>* nodeAtIndex = this->At(index);
    return nodeAtIndex;
  }

  Node<K, V>* operator[](int index) noexcept {
    if (!this->head && !this->tail) {
      return nullptr;
    }

    if (index < 0 || index > this->length - 1) {
      return nullptr;
    }

    Node<K, V>* nodeAtIndex = this->At(index);

    return nodeAtIndex;
  }

  LinkedList<K, V>& operator=(const LinkedList<K, V>& otherList) noexcept {
    if (&otherList == this) {
      return *this;
    }

    Node<K, V>* otherListHeadNode = otherList.head;

    while (otherListHeadNode) {
      this->PushBack(otherListHeadNode->data);
      otherListHeadNode = otherListHeadNode->next;
    }

    return *this;
  }

  LinkedList<K, V>& operator=(LinkedList<K, V>&& otherList) noexcept {
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

  bool operator==(const LinkedList<K, V>& rhs) const {
    if (this == &rhs) {
      return true;
    }

    if (this->Size() != rhs.Size()) {
      return false;
    }

    Node<K, V>* otherListHeadNode = rhs.head;
    Node<K, V>* headNode = this->head;

    while (headNode && otherListHeadNode) {
      if (headNode->data != otherListHeadNode->data) {
        return false;
      }

      otherListHeadNode = otherListHeadNode->next;
      headNode = headNode->next;
    }

    return true;
  }

  bool operator!=(const LinkedList<K, V>& rhs) const {
    return !((*this) == rhs);
  }

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

  bool operator<(LinkedList<K, V>& otherList) const {
    return this->Size() < otherList.Size();
  }

  bool operator>(LinkedList<K, V>& otherList) const {
    return this->Size() > otherList.Size();
  }

  template <typename W, typename X>
  friend ostream& operator<<(ostream& os, const LinkedList<W, X>& list);

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

template <typename K, typename V>
LinkedList<K, V>::LinkedList() noexcept
    : head{nullptr}, tail{nullptr}, length{0} {}

template <typename K, typename V>
LinkedList<K, V>::LinkedList(int size) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  this->Resize(size);
}

template <typename K, typename V>
LinkedList<K, V>::LinkedList(int size, const V& data) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  this->Resize(size, data);
}

template <typename K, typename V>
LinkedList<K, V>::LinkedList(const initializer_list<V>& list) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  this->InsertManyAtEnd(list);
}

template <typename K, typename V>
LinkedList<K, V>::LinkedList(const vector<V>& vector) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  this->Assign(vector);
}

template <typename K, typename V>
LinkedList<K, V>::LinkedList(const LinkedList<K, V>& otherList) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  if (&otherList == this) {
    return;
  }

  Node<K, V>* otherListHeadNode = otherList.head;

  while (otherListHeadNode) {
    this->PushBack(otherListHeadNode->data);
    otherListHeadNode = otherListHeadNode->next;
  }
}

template <typename K, typename V>
LinkedList<K, V>::LinkedList(LinkedList<K, V>&& otherList) noexcept
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

template <typename K, typename V>
LinkedList<K, V>::~LinkedList() noexcept {
  if (this->head != nullptr) {
    Node<K, V>* node = this->head;
    Node<K, V>* next = nullptr;

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

template <typename K, typename V>
ostream& operator<<(ostream& os, const LinkedList<K, V>& list) {
  list.Print();
  return os;
}

template <typename K, typename V>
void LinkedList<K, V>::PushFront(const V& data) noexcept {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(data);
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* currentHead = this->head;
  Node<K, V>* newNode = new Node<K, V>(data, nullptr, currentHead);
  currentHead->previous = newNode;
  this->head = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushBack(const V& data) {
  if (!this->head && !this->tail) {
    this->PushFront(data);
    return;
  }

  Node<K, V>* currentTail = this->tail;
  Node<K, V>* newNode = new Node<K, V>(data, currentTail, nullptr);
  currentTail->next = newNode;
  this->tail = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushBack(V&& data) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(move(data));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* newNode = new Node<K, V>(move(data), this->tail, nullptr);
  this->tail->next = newNode;
  this->tail = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushAt(const V& data, int index) {
  if ((!this->head && !this->tail) || index <= 0) {
    this->PushFront(data);
    return;
  }

  if (index > this->length - 1) {
    this->PushBack(data);
    return;
  }

  Node<K, V>* nodeAtPreviousIndex = this->At(index - 1);

  Node<K, V>* nodeToBeReplacedAtIndex = nodeAtPreviousIndex->next;

  Node<K, V>* newNode =
      new Node<K, V>(data, nodeAtPreviousIndex, nodeToBeReplacedAtIndex);

  nodeAtPreviousIndex->next = newNode;
  nodeToBeReplacedAtIndex->previous = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushMiddle(const V& data) {
  if (!this->head && !this->tail) {
    this->PushFront(data);
    return;
  }

  int midpointIndex = this->FindMidpointIndex();

  this->PushAt(data, midpointIndex);
}

template <typename K, typename V>
void LinkedList<K, V>::PushFront(V&& data) noexcept {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(move(data));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* currentHead = this->head;
  Node<K, V>* newNode = new Node<K, V>(move(data), nullptr, currentHead);
  currentHead->previous = newNode;
  this->head = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushAt(V&& data, int index) {
  if ((!this->head && !this->tail) || index <= 0) {
    this->PushFront(move(data));
    return;
  }

  if (index > this->length - 1) {
    this->PushBack(move(data));
    return;
  }

  Node<K, V>* nodeAtPreviousIndex = this->At(index - 1);

  Node<K, V>* nodeToBeReplacedAtIndex = nodeAtPreviousIndex->next;

  Node<K, V>* newNode =
      new Node<K, V>(move(data), nodeAtPreviousIndex, nodeToBeReplacedAtIndex);

  nodeAtPreviousIndex->next = newNode;
  nodeToBeReplacedAtIndex->previous = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::InsertManyAtStart(const initializer_list<V>& data) {
  for (const V& element : data) {
    this->PushFront(element);
  }
}

template <typename K, typename V>
void LinkedList<K, V>::InsertManyAtEnd(const initializer_list<V>& data) {
  for (const V& element : data) {
    this->PushBack(element);
  }
}

template <typename K, typename V>
int LinkedList<K, V>::Length() const noexcept {
  return this->length;
}

template <typename K, typename V>
int LinkedList<K, V>::Size() const noexcept {
  return this->length;
}

template <typename K, typename V>
Node<K, V>* LinkedList<K, V>::At(int index) const noexcept {
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

  Node<K, V>* node = this->head;
  int counter = 0;

  while (node->next != nullptr && counter < index) {
    node = node->next;
    counter++;
  }

  return node;
}

template <typename K, typename V>
bool LinkedList<K, V>::Empty() const noexcept {
  if (!this->head && !this->tail) {
    return true;
  }

  return false;
}

template <typename K, typename V>
bool LinkedList<K, V>::Contains(const V& data) const noexcept {
  if (!this->head && !this->tail) {
    return false;
  }

  Node<K, V>* node = this->head;
  while (node) {
    if (node->data == data) {
      return true;
    }

    node = node->next;
  }

  return false;
}

template <typename K, typename V>
void LinkedList<K, V>::PopFront() {
  if (!this->head || !this->tail) {
    return;
  }

  if (this->head->next == nullptr) {
    Node<K, V>* node = this->head;
    delete node;
    this->tail = nullptr;
    this->head = nullptr;
    this->length--;
    return;
  }

  Node<K, V>* currentHead = this->head;
  this->head = currentHead->next;
  currentHead->next = nullptr;
  currentHead->previous = nullptr;
  delete currentHead;
  this->length--;
}

template <typename K, typename V>
void LinkedList<K, V>::PopBack() {
  if (!this->head || !this->tail) {
    return;
  }

  if (this->tail->previous == nullptr) {
    Node<K, V>* node = this->tail;
    delete node;
    this->tail = nullptr;
    this->head = nullptr;
    this->length--;
    return;
  }

  Node<K, V>* currentTail = this->tail;
  Node<K, V>* nodeBeforeTail = this->tail->previous;
  nodeBeforeTail->next = nullptr;
  this->tail = nodeBeforeTail;
  currentTail->previous = nullptr;
  delete currentTail;
  this->length--;
}

template <typename K, typename V>
void LinkedList<K, V>::PopAt(int index) {
  if (!this->head && !this->tail) {
    return;
  }

  if (index < 0 || index > this->length - 1) {
    return;
  }

  if (index == 0) {
    this->PopFront();
    return;
  }

  if (index == this->length - 1) {
    this->PopBack();
    return;
  }

  Node<K, V>* nodeAtPreviousIndex = this->At(index - 1);
  Node<K, V>* nodeToBeRemoved = nodeAtPreviousIndex->next;
  Node<K, V>* nodeAfterNodeToBeRemoved = nodeToBeRemoved->next;
  nodeAtPreviousIndex->next = nodeToBeRemoved->next;
  nodeAfterNodeToBeRemoved->previous = nodeAtPreviousIndex;
  nodeToBeRemoved->next = nullptr;
  nodeToBeRemoved->previous = nullptr;
  delete nodeToBeRemoved;
  this->length--;
}

template <typename K, typename V>
int LinkedList<K, V>::Count(const V& data) const {
  if (!this->head && !this->tail) {
    return 0;
  }

  Node<K, V>* node = this->head;
  int counter = 0;

  while (node) {
    if (node->data == data) {
      counter++;
    }
    node = node->next;
  }

  return counter;
}

template <typename K, typename V>
bool LinkedList<K, V>::UpdateIndex(const V& data, int index) {
  if (!this->head && !this->tail) {
    return false;
  }

  if (index < 0 || index > (this->length - 1)) {
    return false;
  }

  Node<K, V>* nodeAtIndex = this->At(index);
  nodeAtIndex->data = data;
  return true;
}

template <typename K, typename V>
bool LinkedList<K, V>::UpdateFirst(const V& data) {
  if (!this->head && !this->tail) {
    return false;
  }

  Node<K, V>* headNode = this->head;
  headNode->data = data;
  return true;
}

template <typename K, typename V>
bool LinkedList<K, V>::UpdateLast(const V& data) {
  if (!this->head && !this->tail) {
    return false;
  }

  Node<K, V>* tailNode = this->tail;
  tailNode->data = data;
  return true;
}

template <typename K, typename V>
void LinkedList<K, V>::Clear() {
  if (!this->head && !this->tail) {
    return;
  }

  Node<K, V>* node = this->head;
  Node<K, V>* nextNode = nullptr;

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

template <typename K, typename V>
void LinkedList<K, V>::Print() const noexcept {
  if (!this->head && !this->tail) {
    return;
  }

  Node<K, V>* node = this->head;
  while (node) {
    std::cout << node->data;
    std::cout << " -> ";
    node = node->next;
  }
  std::cout << "nullptr" << endl;
}

template <typename K, typename V>
void LinkedList<K, V>::Resize(int size) {
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
      this->PushBack(V{});
      counter++;
    }

    return;
  }

  if (size < this->length) {
    int counter = this->length;

    while (counter > size) {
      this->PopBack();
      counter = this->length;
    }
  }
}

template <typename K, typename V>
void LinkedList<K, V>::Resize(int size, const V& dataToUse) {
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
      this->PushBack(dataToUse);
      counter++;
    }

    return;
  }

  if (size < this->length) {
    int counter = this->length;

    while (counter > size) {
      this->PopBack();
      counter = this->length;
    }
  }
}

template <typename K, typename V>
bool LinkedList<K, V>::Swap(LinkedList<K, V>& otherList) {
  if ((!this->head && !this->tail) && (!otherList.head && !otherList.tail)) {
    return false;
  }

  if (this == &otherList) {
    return false;
  }

  Node<K, V>* node = nullptr;
  Node<K, V>* otherListNode = nullptr;

  if (this->length > otherList.Size()) {
    int otherListInitialSize = otherList.Size();
    otherList.Resize(this->length);

    node = this->head;
    otherListNode = otherList.head;

    while (node != nullptr && otherListNode != nullptr) {
      V temp = node->data;
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
      V temp = node->data;
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
      V temp = node->data;
      node->data = otherListNode->data;
      otherListNode->data = temp;
      node = node->next;
      otherListNode = otherListNode->next;
    }

    return true;
  }

  return false;
}

template <typename K, typename V>
Node<K, V>* LinkedList<K, V>::Head() {
  if (!this->head && !this->tail) {
    return nullptr;
  }

  return this->head;
}

template <typename K, typename V>
Node<K, V>* LinkedList<K, V>::Tail() {
  if (!this->head && !this->tail) {
    return nullptr;
  }

  return this->tail;
}

template <typename K, typename V>
template <typename... Args>
void LinkedList<K, V>::EmplaceBack(Args&&... args) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(V(forward<Args>(args)...));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* newNode = new Node<K, V>(V(forward<Args>(args)...), this->tail);
  this->tail->next = newNode;
  this->tail = newNode;
  this->length++;
}

template <typename K, typename V>
template <typename... Args>
void LinkedList<K, V>::EmplaceFront(Args&&... args) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(V(forward<Args>(args)...));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* newNode =
      new Node<K, V>(V(forward<Args>(args)...), nullptr, this->head);
  this->head->previous = newNode;
  this->head = newNode;
  this->length++;
}

template <typename K, typename V>
template <typename... Args>
void LinkedList<K, V>::EmplaceMiddle(Args&&... args) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode =
        new Node<K, V>(V(forward<Args>(args)...), nullptr, nullptr);
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* middleNode = this->FindMidpoint();
  Node<K, V>* nodePreviousToMiddle = middleNode->previous;

  Node<K, V>* newNode = new Node<K, V>(V(forward<Args>(args)...),
                                       nodePreviousToMiddle, middleNode);
  nodePreviousToMiddle->next = newNode;
  middleNode->previous = newNode;
  this->length++;
}

template <typename K, typename V>
template <typename... Args>
void LinkedList<K, V>::EmplaceAt(int index, Args&&... args) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode =
        new Node<K, V>(V(forward<Args>(args)...), nullptr, nullptr);
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

  Node<K, V>* nodeAtPreviousIndex = this->At(index - 1);
  Node<K, V>* nodeToBeReplacedAtIndex = nodeAtPreviousIndex->next;
  Node<K, V>* newNode = new Node<K, V>(
      V(forward<Args>(args)...), nodeAtPreviousIndex, nodeToBeReplacedAtIndex);

  nodeAtPreviousIndex->next = newNode;
  nodeToBeReplacedAtIndex->previous = newNode;
  this->length++;
}

#endif