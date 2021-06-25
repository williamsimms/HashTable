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
  using ValueReferenceType = V&;

 private:
  int size;

 public:
  HashTable();
  HashTable(const HashTable<K, V, H>&);
  HashTable(HashTable<K, V, H>&&);
  ~HashTable();

  HashTable<K, V, H>& operator=(const HashTable<K, V, H>&);
  HashTable<K, V, H>& operator=(HashTable<K, V, H>&&);

  [[nodiscard]] int Hash(const K&);

  void Insert(const K& key, const V& value);
};

template <typename K, typename V, typename H>
int HashTable<K, V, H>::Hash(const K& key) {
  auto hash = H()(key);
  return hash;
}

#endif