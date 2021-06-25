#ifndef HASH_TABLE_H
#define HASH_TABLE_H

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

  void Erase(const K&);

  template <typename... Args>
  void Emplace(Args&&...);

  V& At(const K&);
  const V& At(const K&) const;
  int Count(const K&) const;
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

  int MaxLoadFactor();

  // begin()
  // cbegin()
  // end()
  // cend()
  // rbegin()
  // rend();
  // crbegin()
  // crend();
};

template <typename K, typename V, typename H>
HashTable<K, V, H>::HashTable()
    : size(0), buckets(8), table(new LinkedList<K, V>[8]) {}

template <typename K, typename V, typename H>
HashTable<K, V, H>::HashTable(int bucketCount)
    : size(0), buckets(RoundUp(bucketCount, 8)) {
  table = new LinkedList<K, V>[buckets]
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
  return hash % buckets;
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
  bucket.PushBack(value);
  this->size++;
}

template <typename K, typename V, typename H>
V& HashTable<K, V, H>::At(const K& key) {
  unsigned long long int hashedKey = Hash(key);
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
  //
}

template <typename K, typename V, typename H>
template <typename... Args>
void HashTable<K, V, H>::Emplace(Args&&... args) {
  //
}

template <typename K, typename V, typename H>
int HashTable<K, V, H>::BucketSize(const K& key) const {
  unsigned long long int hashedKey = Hash(key);
  LinkedList<K, V> bucket = table[hashedKey];
  return bucket.Size();
}

#endif