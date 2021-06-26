#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cassert>
#include <functional>
#include <initializer_list>
#include <memory>
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

 private:
  int size;
  int buckets;
  LinkedList<K, V>* table;

 public:
  HashTable();
  HashTable(int);
  HashTable(const HashTable<K, V, H>&);
  HashTable(HashTable<K, V, H>&&);
  ~HashTable();

  HashTable<K, V, H>& operator=(const HashTable<K, V, H>&);
  HashTable<K, V, H>& operator=(HashTable<K, V, H>&&);

  bool Empty() const;
  int Size() const;
  int MaxSize() const;

  void Clear();
  void Insert(const K& key, const V& value);
  void Insert(const K& key, V&& value);

  void Erase(const K&);

  template <typename... Args>
  void Emplace(Args&&...);

  V& At(const K&);
  const V& At(const K&) const;
  int Count(const K&) const;
  int Count(int) const;
  V& Find(const K&);
  const V& Find(const K&) const;
  bool Contains(const K&) const;

  int BucketCount() const;
  int MaxBucketCount() const;
  int BucketSize(const K&) const;
  const LinkedList<K, V>& Bucket(const K&) const;

  void Reserve(int);
  void Resize();

  bool Key(const K&, const K&);

  const V& operator[](const K&) const;
  V& operator[](const K&);

  [[nodiscard]] unsigned long long int Hash(const K&);

  float LoadFactor() const;
  float MaxLoadFactor() const;

  void PrintBucketSizes();
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
HashTable<K, V, H>::HashTable(const HashTable<K, V, H>& otherTable) {
  for (int i = 0; i < otherTable.buckets; i++) {
    //
  }
}

template <typename K, typename V, typename H>
HashTable<K, V, H>::HashTable(HashTable<K, V, H>&& otherTable) {
  this->buckets = otherTable.buckets;
  this->size = otherTable.size;
  this->table = otherTable.table;

  otherTable.size = 0;
  otherTable.buckets = 0;
  otherTable.table = nullptr;
}

template <typename K, typename V, typename H>
HashTable<K, V, H>::~HashTable() {
  this->buckets = 0;
  this->size = 0;
  this->table = nullptr;
}

template <typename K, typename V, typename H>
unsigned long long int HashTable<K, V, H>::Hash(const K& key) {
  unsigned long long int hash = H()(key);
  return (hash * 17) % buckets;
}

template <typename K, typename V, typename H>
int HashTable<K, V, H>::BucketCount() const {
  return this->buckets;
}

template <typename K, typename V, typename H>
float HashTable<K, V, H>::LoadFactor() const {
  return this->size / this->buckets;
}

template <typename K, typename V, typename H>
bool HashTable<K, V, H>::Key(const K& keyOne, const K& keyTwo) {
  unsigned long long int hashOne = Hash(keyOne);
  unsigned long long int hashTwo = Hash(keyTwo);
  return hashOne == hashTwo;
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Insert(const K& key, const V& value) {
  if (LoadFactor() >= 1) {
    Resize();
  }

  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = table[hashedKey];
  bucket.PushBack(key, value);
  this->size++;
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Insert(const K& key, V&& value) {
  if (LoadFactor() >= 1) {
    Resize();
  }

  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V>& bucket = table[hashedKey];
  Node<K, V>* node = bucket.Find(key);

  if (!node) {
    bucket.PushBack(key, std::move(value));
    this->size++;
  }

  node->value = value;
}

template <typename K, typename V, typename H>
V& HashTable<K, V, H>::At(const K& key) {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V> bucket = table[hashedKey];
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
  //
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::Resize() {
  int newBucketAmount = buckets * 3;
  LinkedList<K, V>* newTable = new LinkedList<K, V>[newBucketAmount];
  LinkedList<K, V>* oldTable = this->table;
  this->table = newTable;

  for (int i = 0; i < buckets; i++) {
    LinkedList<K, V> bucket = oldTable[i];

    while (bucket.Head() != nullptr) {
      K key = bucket.Head()->key;
      Insert(key, std::move(bucket.Head()->value));
      bucket.PopFront();
    }
  }

  delete[] oldTable;
  this->buckets = newBucketAmount;
}

template <typename K, typename V, typename H>
template <typename... Args>
void HashTable<K, V, H>::Emplace(Args&&... args) {}

template <typename K, typename V, typename H>
int HashTable<K, V, H>::BucketSize(const K& key) const {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V> bucket = table[hashedKey];
  return bucket.Size();
}

template <typename K, typename V, typename H>
const V& HashTable<K, V, H>::operator[](const K&) const {
  //
}

template <typename K, typename V, typename H>
V& HashTable<K, V, H>::operator[](const K&) {
  //
}

template <typename K, typename V, typename H>
int HashTable<K, V, H>::Count(const K& key) const {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V> bucket = this->table[hashedKey];
  return bucket.Size();
}

template <typename K, typename V, typename H>
int HashTable<K, V, H>::Count(int index) const {
  LinkedList<K, V> bucket = this->table[index];
  return bucket.Size();
}

template <typename K, typename V, typename H>
void HashTable<K, V, H>::PrintBucketSizes() {
  for (int i = 0; i < buckets; i++) {
    std::cout << table[i].Size() << " ";
  }
}

template <typename K, typename V, typename H>
const LinkedList<K, V>& HashTable<K, V, H>::Bucket(const K& key) const {
  unsigned long long int hashedKey = Hash(key);
}

template <typename K, typename V, typename H>
V& HashTable<K, V, H>::Find(const K& key) {
  //
}

template <typename K, typename V, typename H>
const V& HashTable<K, V, H>::Find(const K& key) const {
  //
}

template <typename K, typename V, typename H>
bool HashTable<K, V, H>::Contains(const K& key) const {
  //
}

#endif