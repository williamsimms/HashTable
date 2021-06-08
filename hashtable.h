#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <initializer_list>
#include <memory>

template <typename T>
class HashTable {
  HashTable();
  HashTable(const HashTable&);
  HashTable(HashTable&&);
  ~HashTable();

  HashTable<T>& operator=(const HashTable<T>&);
  HashTable<T>& operator=(HashTable<T>&&);
};

#endif