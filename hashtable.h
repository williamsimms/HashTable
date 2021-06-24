#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>
#include <initializer_list>
#include <memory>
#include <string>
#include <utility>
#include <vector>

template <typename K, typename V>
class Node {
 public:
  K key;
  V value;

  Node(const K& key, const V& value);
};

template <typename K, typename V>
Node<K, V>::Node(const K& key, const V& value) : key(key), value(value) {}

template <typename K, typename V>
class HashTable {
 public:
  using KeyValueType = K;
  using KeyPointerValueType = K*;
  using KeyReferenceValueType = K&;
  using ValueType = V;
  using ValuePointerType = V*;
  using ValueReferenceType = V&;

 private:
  Node<K, V>** nodes;
  int size;
  int count;

 public:
  HashTable();
  HashTable(const HashTable&);
  HashTable(HashTable&&);
  ~HashTable();

  HashTable<K, V>& operator=(const HashTable<K, V>&);
  HashTable<K, V>& operator=(HashTable<K, V>&&);

  int Hash(const std::string& key);

  void Insert(const K& key, const V& value);
};

template <typename K, typename V>
int HashTable<K, V>::Hash(const std::string& key) {
  int hash = 0;
  int lengthOfString = key.length();

  for (int i = 0; i < lengthOfString; i++) {
    hash += (int)key[i];
  }

  return hash;
}

template <typename K, typename V>
void HashTable<K, V>::Insert(const K& key, const V& value) {
  Node<K, V>* node = new Node<K, V>;
}

#endif