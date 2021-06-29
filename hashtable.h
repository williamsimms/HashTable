#pragma once
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cassert>
#include <functional>
#include <initializer_list>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "linkedlist.h"
#include "utility/util.hpp"

template <typename K, typename V, typename H = std::hash<K>>
class HashTable {
 public:
  using KeyValueType = K;
  using KeyPointerValueType = K*;
  using ConstKeyPointerValueType = const K*;
  using KeyReferenceValueType = K&;
  using ConstKeyReferenceValueType = const K&;
  using ValueType = V;
  using ValuePointerType = V*;
  using ConstValuePointerType = const V*;
  using ValueReferenceType = V&;
  using ConstValueReferenceType = const V&;
  using LinkedListType = LinkedList<K, V>;
  using NodeType = Node<K, V>;
  using NodePointerType = Node<K, V>*;

 private:
  int size;
  int buckets;
  LinkedList<K, V>* table;

 public:
  HashTable();
  HashTable(int);
  HashTable(const HashTable<K, V, H>&) noexcept;
  HashTable(HashTable<K, V, H>&&) noexcept;
  ~HashTable();

  HashTable<K, V, H>& operator=(const HashTable<K, V, H>&) noexcept;
  HashTable<K, V, H>& operator=(HashTable<K, V, H>&&) noexcept;

  [[nodiscard]] bool Empty() const;
  [[nodiscard]] int Size() const;

  void Clear();
  void Free();
  void Insert(const K& key, const V& value);
  void Insert(const K& key, V&& value);

  template <typename... Args>
  void Emplace(const K&, Args&&...);

  bool Erase(const K&);

  [[nodiscard]] V& At(const K&);
  [[nodiscard]] const V& At(const K&) const;
  [[nodiscard]] int Count(const K&) const;
  [[nodiscard]] int Count(int) const;
  [[nodiscard]] V& Find(const K&);
  [[nodiscard]] const V& Find(const K&) const;
  [[nodiscard]] bool Contains(const K&) const;

  [[nodiscard]] int BucketCount() const;

  [[nodiscard]] const LinkedList<K, V>& Bucket(const K&) const;

  void Reserve(int);
  void Rehash();
  void Rehash(int);

  [[nodiscard]] bool Key(const K&, const K&);

  V& operator[](const K&);
  bool operator==(const HashTable<K, V, H>&) const;

  [[nodiscard]] unsigned long long int Hash(const K&) const;
  [[nodiscard]] float LoadFactor() const;
  [[nodiscard]] float MaxLoadFactor() const;
  void PrintBucketSizes() const;

  template <typename X, typename Y, typename Z>
  friend std::ostream& operator<<(std::ostream& os, const HashTable<X, Y>&);
};

template <typename K, typename V, typename H>
HashTable<K, V, H>::HashTable()
    : size(0), buckets(8), table(new LinkedList<K, V>[8]) {}

template <typename K, typename V, typename H>
HashTable<K, V, H>::HashTable(int bucketCount)
    : size(0), buckets(RoundUp(bucketCount, 8)) {
  table = new LinkedList<K, V>[buckets];
}

template <typename K, typename V, typename H>
HashTable<K, V, H>::HashTable(const HashTable<K, V, H>& otherTable) noexcept {
  if (&otherTable == this) {
    return;
  }

  this->table = new LinkedList<K, V>[otherTable.buckets];
  this->buckets = otherTable.buckets;
  this->size = 0;

  for (int i = 0; i < otherTable.buckets; i++) {
    LinkedList<K, V>& bucket = otherTable.table[i];
    Node<K, V>* node = bucket.Head();

    while (node) {
      Insert(node->key, node->value);
      node = node->next;
    }
  }
}

template <typename K, typename V, typename H>
HashTable<K, V, H>::HashTable(HashTable<K, V, H>&& otherTable) noexcept {
  if (&otherTable == this) {
    return;
  }

  this->buckets = std::move(otherTable.buckets);
  this->size = std::move(otherTable.size);
  this->table = std::move(otherTable.table);
  otherTable.size = 0;
  otherTable.buckets = 0;
  otherTable.table = nullptr;
}

template <typename K, typename V, typename H>
HashTable<K, V, H>::~HashTable() {
  delete[] table;
  this->buckets = 0;
  this->size = 0;
  this->table = nullptr;
}

template <typename K, typename V, typename H>
HashTable<K, V, H>& HashTable<K, V, H>::operator=(
    const HashTable<K, V, H>& otherTable) noexcept {
  if (this == &otherTable) {
    return *this;
  }

  this->Free();
  this->table = new LinkedList<K, V>[otherTable.buckets];
  this->buckets = otherTable.buckets;

  for (int i = 0; i < otherTable.buckets; i++) {
    LinkedList<K, V>& bucket = otherTable.table[i];
    Node<K, V>* node = bucket.Head();

    while (node) {
      Insert(node->key, node->value);
      node = node->next;
    }
  }

  return *this;
}

template <typename K, typename V, typename H>
HashTable<K, V, H>& HashTable<K, V, H>::operator=(
    HashTable<K, V, H>&& otherTable) noexcept {
  if (this == &otherTable) {
    return *this;
  }

  this->Free();
  this->buckets = std::move(otherTable.buckets);
  this->size = std::move(otherTable.size);
  this->table = std::move(otherTable.table);
  otherTable.size = 0;
  otherTable.buckets = 0;
  otherTable.table = nullptr;
  return *this;
}

template <typename K, typename V, typename H>
unsigned long long int HashTable<K, V, H>::Hash(const K& key) const {
  unsigned long long int hash = H()(key);
  return (hash * 17) % buckets;
}

template <typename K, typename V, typename H>
int HashTable<K, V, H>::BucketCount() const {
  return this->buckets;
}

template <typename K, typename V, typename H>
float HashTable<K, V, H>::LoadFactor() const {
  float loadFactor = (float)this->size / (float)this->buckets;
  return loadFactor;
}

template <typename K, typename V, typename H>
float HashTable<K, V, H>::MaxLoadFactor() const {
  return 1;
}

template <typename K, typename V, typename H>
bool HashTable<K, V, H>::Key(const K& keyOne, const K& keyTwo) {
  unsigned long long int hashOne = Hash(keyOne);
  unsigned long long int hashTwo = Hash(keyTwo);
  return hashOne == hashTwo;
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Insert(const K& key, const V& value) {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = table[hashedKey];
  Node<K, V>* node = bucket.Find(key);

  if (node) {
    node->value = value;
    return;
  }

  if (LoadFactor() >= MaxLoadFactor()) {
    Rehash();
  }

  bucket.PushBack(key, value);
  this->size++;
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Insert(const K& key, V&& value) {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = table[hashedKey];
  Node<K, V>* node = bucket.Find(key);

  if (node) {
    node->value = value;
    return;
  }

  if (LoadFactor() >= MaxLoadFactor()) {
    Rehash();
  }

  bucket.PushBack(key, std::move(value));
  this->size++;
}

template <typename K, typename V, typename H>
template <typename... Args>
void HashTable<K, V, H>::Emplace(const K& key, Args&&... args) {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = table[hashedKey];
  Node<K, V>* node = bucket.Find(key);

  V value = V(std::forward<Args>(args)...);

  if (node) {
    node->value = value;
    return;
  }

  if (LoadFactor() >= MaxLoadFactor()) {
    Rehash();
  }

  bucket.PushBack(key, std::move(value));
  this->size++;
}

template <typename K, typename V, typename H>
V& HashTable<K, V, H>::At(const K& key) {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = table[hashedKey];
  Node<K, V>* node = bucket.Find(key);
  assert(node != nullptr);
  return node->value;
}

template <typename K, typename V, typename H>
const V& HashTable<K, V, H>::At(const K& key) const {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = table[hashedKey];
  Node<K, V>* node = bucket.Find(key);
  assert(node != nullptr);
  return node->value;
}

template <typename K, typename V, typename H>
int HashTable<K, V, H>::Size() const {
  return size;
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Reserve(int count) {
  int newBucketAmount = RoundUp(count, 8);
  Rehash(newBucketAmount);
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Rehash() {
  int oldBucketAmount = this->buckets;
  int newBucketAmount = oldBucketAmount * 3;
  LinkedList<K, V>* newTable = new LinkedList<K, V>[newBucketAmount];
  LinkedList<K, V>* oldTable = this->table;
  this->table = newTable;
  this->size = 0;
  this->buckets = newBucketAmount;

  for (int i = 0; i < oldBucketAmount; i++) {
    LinkedList<K, V>& bucket = oldTable[i];
    Node<K, V>* node = bucket.Head();

    while (node != nullptr) {
      Insert(node->key, std::move(node->value));
      node = node->next;
      bucket.PopFront();
    }
  }

  delete[] oldTable;
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Rehash(int newBucketAmount) {
  int oldBucketAmount = this->buckets;
  LinkedList<K, V>* newTable = new LinkedList<K, V>[newBucketAmount];
  LinkedList<K, V>* oldTable = this->table;
  this->table = newTable;
  this->size = 0;
  this->buckets = newBucketAmount;

  for (int i = 0; i < oldBucketAmount; i++) {
    LinkedList<K, V>& bucket = oldTable[i];
    Node<K, V>* node = bucket.Head();

    while (node != nullptr) {
      Insert(node->key, std::move(node->value));
      node = node->next;
      bucket.PopFront();
    }
  }

  delete[] oldTable;
}

template <typename K, typename V, typename H>
V& HashTable<K, V, H>::operator[](const K& key) {
  bool alreadyInTable = Contains(key);

  if (!alreadyInTable) {
    Insert(key, V{});
  }

  return At(key);
}

template <typename K, typename V, typename H>
int HashTable<K, V, H>::Count(const K& key) const {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = this->table[hashedKey];
  return bucket.Size();
}

template <typename K, typename V, typename H>
int HashTable<K, V, H>::Count(int index) const {
  assert(index >= 0);
  assert(index < buckets);
  LinkedList<K, V>& bucket = this->table[index];
  return bucket.Size();
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::PrintBucketSizes() const {
  for (int i = 0; i < buckets; i++) {
    std::cout << table[i].Size() << " ";
  }

  std::cout << std::endl;
}

template <typename K, typename V, typename H>
const LinkedList<K, V>& HashTable<K, V, H>::Bucket(const K& key) const {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = this->table[hashedKey];
  return bucket;
}

template <typename K, typename V, typename H>
bool HashTable<K, V, H>::Contains(const K& key) const {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = table[hashedKey];
  bool bucketContainsKey = bucket.Contains(key);

  if (bucketContainsKey) {
    return true;
  }
  return false;
}

template <typename K, typename V, typename H>
bool HashTable<K, V, H>::Empty() const {
  if (size > 0) {
    return false;
  }

  return true;
}

template <typename K, typename V, typename H>
bool HashTable<K, V, H>::Erase(const K& key) {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = table[hashedKey];
  bool nodeGotRemoved = bucket.PopKey(key);
  if (nodeGotRemoved) {
    this->size--;
    return true;
  }

  return false;
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Clear() {
  delete[] table;
  table = new LinkedList<K, V>[8];
  buckets = 8;
  size = 0;
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Free() {
  delete[] table;
  table = nullptr;
  buckets = 0;
  size = 0;
}

template <typename K, typename V, typename H>
bool HashTable<K, V, H>::operator==(
    const HashTable<K, V, H>& otherTable) const {
  if (this == &otherTable) {
    return true;
  }

  if (size != otherTable.size) {
    return false;
  }

  if (buckets != otherTable.buckets) {
    return false;
  }

  for (int i = 0; i < buckets; i++) {
    LinkedList<K, V>& bucket = table[i];
    LinkedList<K, V>& otherTableBucket = otherTable.table[i];

    if (bucket != otherTableBucket) {
      return false;
    }
  }

  return true;
}

template <typename K, typename V, typename H>
std::ostream& operator<<(std::ostream& os, const HashTable<K, V, H>& table) {
  table.PrintBucketSizes();
  return os;
}

#endif