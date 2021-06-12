#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <initializer_list>
#include <memory>
#include <string>

template <typename K, typename T>
class HashTable {
  HashTable();
  HashTable(const HashTable&);
  HashTable(HashTable&&);
  ~HashTable();

  HashTable<K, T>& operator=(const HashTable<K, T>&);
  HashTable<K, T>& operator=(HashTable<K, T>&&);

  // At();
  // Bucket()
  // BucketCount();
  // Cbegin()
  // Clear()
  // Count
  // Cend()
  // begin();
  // end();
  // crbegin()
  // crend()
  // BucketSize()
};

#endif