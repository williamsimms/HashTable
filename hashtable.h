#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>
#include <vector>

template <typename K, typename V, typename H = std::hash<K>>
class HashTable {
 public:
  using KeyValueType = K;
  using KeyPointerValueType = K*;
  using KeyReferenceValueType = K&;
  using ValueType = V;
  using ValuePointerType = V*;
  using ConstValuePointerType = const V*;
  using ValueReferenceType = V&;
  using ConstValueReferenceType = const V&;

 private:
  int size;
  int buckets;

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
  void Emplace();
  void Erase();

  V& At(const K&);
  const V& At(const K&) const;
  int Count(const K&) const;
  V& Find(const K&);
  const V& Find(const K&) const;
  bool Contains(const K&) const;

  int BucketCount() const;
  int MaxBucketCount() const;
  int BucketSize(const K&) const;
  // const LinkedList<K,V>& Bucket(const K&) const;

  void Reserve();

  // check key for equality
  bool Key(const K&, const K&);

  const V& operator[](const K&) const;
  V& operator[](const K&);

  [[nodiscard]] unsigned long long int Hash(const K&);

  // average number of elements per bucket
  int LoadFactor();

  // manages maximum average number of elements per bucket
  int MaxLoadFactor();

  // Begin()
  // CBegin()
  // End()
  // CEnd()
  // RBegin()
  // REnd();
  // CRBegin()
  // CREnd();
};

template <typename K, typename V, typename H>
HashTable<K, V, H>::HashTable() : buckets(20) {}

template <typename K, typename V, typename H>
HashTable<K, V, H>::HashTable(int bucketCount) : buckets(bucketCount) {}

template <typename K, typename V, typename H>
HashTable<K, V, H>::~HashTable() {
  buckets = 0;
}

template <typename K, typename V, typename H>
unsigned long long int HashTable<K, V, H>::Hash(const K& key) {
  auto hash = H()(key);
  return hash % size;
}

#endif