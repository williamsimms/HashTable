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
};

template <typename K, typename V>
class HashTable {
 private:
  Node** nodes;
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

#endif