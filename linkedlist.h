#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <cassert>
#include <cmath>
#include <cstddef>
#include <ctime>
#include <iostream>
#include <iterator>
#include <utility>

#include "node.h"

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
  LinkedList(const LinkedList<K, V>&) noexcept;
  LinkedList(LinkedList<K, V>&&) noexcept;
  ~LinkedList() noexcept;

  void PushFront(const K&, const V& value) noexcept;
  void PushBack(const K&, const V& value);
  void PushAt(const K&, const V& value, int index);
  void PushMiddle(const K&, const V& value);

  void PushFront(const K&, V&& value) noexcept;
  void PushBack(const K&, V&& value);
  void PushAt(const K&, V&& value, int index);
  void PushMiddle(const K&, V&& value);

  template <typename... Args>
  void EmplaceFront(const K&, Args&&... args);

  template <typename... Args>
  void EmplaceMiddle(const K&, Args&&... args);

  template <typename... Args>
  void EmplaceBack(const K&, Args&&... args);

  template <typename... Args>
  void EmplaceAt(int index, const K&, Args&&... args);

  void Print() const noexcept;
  [[nodiscard]] int Length() const noexcept;
  [[nodiscard]] int Size() const noexcept;

  Node<K, V>* At(int index) const noexcept;

  [[nodiscard]] bool Empty() const noexcept;
  [[nodiscard]] bool Contains(const K& key) const noexcept;

  [[nodiscard]] int IndexOf(const V& data) const;
  [[nodiscard]] int LastIndexOf(const V& data) const;
  Node<K, V>* Find(const K& data) const;

  void PopFront();
  void PopBack();
  void PopAt(int index);
  void PopKey(const K&);

  [[nodiscard]] int Count(const V& value) const;

  bool UpdateIndex(const V& value, int index);

  bool UpdateFirst(const V& value);
  bool UpdateLast(const V& value);

  void Clear();

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
      this->PushBack(otherListHeadNode->key, otherListHeadNode->value);
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
      if (headNode->value != otherListHeadNode->value) {
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

  bool operator>(LinkedList<K, V>& otherList) const {
    return this->Size() > otherList.Size();
  }

  template <typename W, typename X>
  friend std::ostream& operator<<(std::ostream& os,
                                  const LinkedList<W, X>& list);

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
LinkedList<K, V>::LinkedList(const LinkedList<K, V>& otherList) noexcept
    : head{nullptr}, tail{nullptr}, length{0} {
  if (&otherList == this) {
    return;
  }

  Node<K, V>* otherListHeadNode = otherList.head;

  while (otherListHeadNode) {
    this->PushBack(otherListHeadNode->key, otherListHeadNode->value);
    otherListHeadNode = otherListHeadNode->next;
  }
}

template <typename K, typename V>
LinkedList<K, V>::LinkedList(LinkedList<K, V>&& otherList) noexcept
    : head{std::move(otherList.head)},
      tail{std::move(otherList.tail)},
      length{std::move(otherList.length)} {
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
std::ostream& operator<<(std::ostream& os, const LinkedList<K, V>& list) {
  list.Print();
  return os;
}

template <typename K, typename V>
void LinkedList<K, V>::PushFront(const K& key, const V& value) noexcept {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(key, value);
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* currentHead = this->head;
  Node<K, V>* newNode = new Node<K, V>(key, value, nullptr, currentHead);
  currentHead->previous = newNode;
  this->head = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushBack(const K& key, const V& value) {
  if (!this->head && !this->tail) {
    PushFront(key, value);
    return;
  }

  Node<K, V>* currentTail = this->tail;
  Node<K, V>* newNode = new Node<K, V>(key, value, currentTail, nullptr);
  currentTail->next = newNode;
  this->tail = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushBack(const K& key, V&& value) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(key, std::move(value));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* newNode =
      new Node<K, V>(key, std::move(value), this->tail, nullptr);
  this->tail->next = newNode;
  this->tail = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushAt(const K& key, const V& value, int index) {
  if ((!this->head && !this->tail) || index <= 0) {
    this->PushFront(key, value);
    return;
  }

  if (index > this->length - 1) {
    this->PushBack(key, value);
    return;
  }

  Node<K, V>* nodeAtPreviousIndex = this->At(index - 1);

  Node<K, V>* nodeToBeReplacedAtIndex = nodeAtPreviousIndex->next;

  Node<K, V>* newNode =
      new Node<K, V>(key, value, nodeAtPreviousIndex, nodeToBeReplacedAtIndex);

  nodeAtPreviousIndex->next = newNode;
  nodeToBeReplacedAtIndex->previous = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushMiddle(const K& key, const V& value) {
  if (!this->head && !this->tail) {
    this->PushFront(key, value);
    return;
  }

  int midpointIndex = this->FindMidpointIndex();
  this->PushAt(key, value, midpointIndex);
}

template <typename K, typename V>
void LinkedList<K, V>::PushFront(const K& key, V&& value) noexcept {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(key, std::move(value));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* currentHead = this->head;
  Node<K, V>* newNode =
      new Node<K, V>(key, std::move(value), nullptr, currentHead);
  currentHead->previous = newNode;
  this->head = newNode;
  this->length++;
}

template <typename K, typename V>
void LinkedList<K, V>::PushAt(const K& key, V&& value, int index) {
  if ((!this->head && !this->tail) || index <= 0) {
    this->PushFront(key, std::move(value));
    return;
  }

  if (index > this->length - 1) {
    this->PushBack(key, std::move(value));
    return;
  }

  Node<K, V>* nodeAtPreviousIndex = this->At(index - 1);
  Node<K, V>* nodeToBeReplacedAtIndex = nodeAtPreviousIndex->next;
  Node<K, V>* newNode = new Node<K, V>(
      key, std::move(value), nodeAtPreviousIndex, nodeToBeReplacedAtIndex);
  nodeAtPreviousIndex->next = newNode;
  nodeToBeReplacedAtIndex->previous = newNode;
  this->length++;
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
bool LinkedList<K, V>::Contains(const K& key) const noexcept {
  if (!this->head && !this->tail) {
    return false;
  }

  Node<K, V>* node = this->head;

  while (node) {
    if (node->key == key) {
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
int LinkedList<K, V>::Count(const V& value) const {
  if (!this->head && !this->tail) {
    return 0;
  }

  Node<K, V>* node = this->head;
  int counter = 0;

  while (node) {
    if (node->value == value) {
      counter++;
    }
    node = node->next;
  }

  return counter;
}

template <typename K, typename V>
bool LinkedList<K, V>::UpdateIndex(const V& value, int index) {
  if (!this->head && !this->tail) {
    return false;
  }

  if (index < 0 || index > (this->length - 1)) {
    return false;
  }

  Node<K, V>* nodeAtIndex = this->At(index);
  nodeAtIndex->value = value;
  return true;
}

template <typename K, typename V>
bool LinkedList<K, V>::UpdateFirst(const V& value) {
  if (!this->head && !this->tail) {
    return false;
  }

  Node<K, V>* headNode = this->head;
  headNode->value = value;
  return true;
}

template <typename K, typename V>
bool LinkedList<K, V>::UpdateLast(const V& value) {
  if (!this->head && !this->tail) {
    return false;
  }

  Node<K, V>* tailNode = this->tail;
  tailNode->value = value;
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
    std::cout << node->value;
    std::cout << " -> ";
    node = node->next;
  }
  std::cout << "nullptr" << std::endl;
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
void LinkedList<K, V>::EmplaceBack(const K& key, Args&&... args) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(key, V(std::forward<Args>(args)...));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* newNode =
      new Node<K, V>(key, V(std::forward<Args>(args)...), this->tail);
  this->tail->next = newNode;
  this->tail = newNode;
  this->length++;
}

template <typename K, typename V>
template <typename... Args>
void LinkedList<K, V>::EmplaceFront(const K& key, Args&&... args) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode = new Node<K, V>(key, V(std::forward<Args>(args)...));
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* newNode =
      new Node<K, V>(key, V(std::forward<Args>(args)...), nullptr, this->head);
  this->head->previous = newNode;
  this->head = newNode;
  this->length++;
}

template <typename K, typename V>
template <typename... Args>
void LinkedList<K, V>::EmplaceMiddle(const K& key, Args&&... args) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode =
        new Node<K, V>(key, V(std::forward<Args>(args)...), nullptr, nullptr);
    this->head = newNode;
    this->tail = newNode;
    this->length++;
    return;
  }

  Node<K, V>* middleNode = this->FindMidpoint();
  Node<K, V>* nodePreviousToMiddle = middleNode->previous;

  Node<K, V>* newNode = new Node<K, V>(key, V(std::forward<Args>(args)...),
                                       nodePreviousToMiddle, middleNode);
  nodePreviousToMiddle->next = newNode;
  middleNode->previous = newNode;
  this->length++;
}

template <typename K, typename V>
template <typename... Args>
void LinkedList<K, V>::EmplaceAt(int index, const K& key, Args&&... args) {
  if (!this->head && !this->tail) {
    Node<K, V>* newNode =
        new Node<K, V>(key, V(std::forward<Args>(args)...), nullptr, nullptr);
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
  Node<K, V>* newNode =
      new Node<K, V>(key, V(std::forward<Args>(args)...), nodeAtPreviousIndex,
                     nodeToBeReplacedAtIndex);

  nodeAtPreviousIndex->next = newNode;
  nodeToBeReplacedAtIndex->previous = newNode;
  this->length++;
}

template <typename K, typename V>
int LinkedList<K, V>::IndexOf(const V& data) const {
  if (!this->head && !this->tail) {
    return -1;
  }

  Node<K, V>* node = this->head;
  int counter = 0;

  while (node) {
    if (node->value == data) {
      return counter;
    }

    node = node->next;
    counter++;
  }

  return -1;
}

template <typename K, typename V>
int LinkedList<K, V>::LastIndexOf(const V& data) const {
  if (!this->head && !this->tail) {
    return -1;
  }

  Node<K, V>* node = this->head;
  int counter = 0;
  int indexOfNode = -1;

  while (node) {
    if (node->value == data) {
      indexOfNode = counter;
    }

    node = node->next;
    counter++;
  }

  return indexOfNode;
}

template <typename K, typename V>
Node<K, V>* LinkedList<K, V>::Find(const K& key) const {
  if (!this->head && !this->tail) {
    return nullptr;
  }

  Node<K, V>* node = this->head;

  while (node) {
    if (node->key == key) {
      return node;
    }

    node = node->next;
  }

  return nullptr;
}

template <typename K, typename V>
void LinkedList<K, V>::PopKey(const K& key) {
  if (!this->head && !this->tail) {
    return;
  }

  Node<K, V>* node = this->head;
  int index = 0;

  while (node) {
    if (node->key == key) {
      PopAt(index);
      break;
    }

    index++;
    node = node->next;
  }
}

#endif