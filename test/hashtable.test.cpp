#define CATCH_CONFIG_MAIN

#include "../hashtable.h"
#include "../utility/Vector3.hpp"
#include "../vendor/catch.hpp"

TEST_CASE("Default Constructor", "[HashTable()]") {
  //
}

TEST_CASE("Constructor with Bucket Size", "[HashTable(int)]") {
  //
}

TEST_CASE("Copy Constructor", "[HashTable(const HashTable<K,V,H>&)]") {
  //
}

TEST_CASE("Move Contructor", "[HashTable(HashTable<K,V,H>&&)]") {
  //
}

TEST_CASE("Copy Assignment Operator",
          "[HashTable<K, V, H>& operator=(const HashTable<K, V, H>&)]") {
  //
}

TEST_CASE("Copy Assignment Operator",
          "[HashTable<K, V, H>& operator=(HashTable<K, V, H>&&)]") {
  //
}

TEST_CASE("", "[bool Empty() const]") {
  //
}

TEST_CASE("", "[int Size() const]") {
  //
}

TEST_CASE("", "[void Clear()]") {
  //
}

TEST_CASE("Inserts a New Element to the Hash Table.",
          "[void Insert(const K& key, const V& value)]") {
  SECTION("Inserts a new Element to the HashTable.") {
    //
  }
}

TEST_CASE("Inserts a New Element to the Hash Table.",
          "[void Insert(const K& key, V&& value)]") {
  SECTION("Inserts a new Element to the HashTable using L Value.") {
    //
  }
}

TEST_CASE("Emplaces a new Element into the hashtable.",
          "[void Emplace(const K&, Args&&...)]") {
  SECTION("Inserts a new Element to the HashTable using L Value.") {
    //
  }
}

TEST_CASE("", "[bool Erase(const K&)]") {
  //
}

TEST_CASE("", "[V& At(const K&)]") {
  //
}

TEST_CASE("", "[const V& At(const K&)]") {
  //
}

TEST_CASE("", "[int Count(const K&) const]") {
  //
}

TEST_CASE("", "[int Count(int) const]") {
  //
}

TEST_CASE("", "[V& Find(const K&)]") {
  //
}

TEST_CASE("", "[const V& Find(const K&) const]") {
  //
}

TEST_CASE("", "[bool Contains(const K&) const]") {
  //
}

TEST_CASE("", "[int BucketCount() const]") {
  //
}

TEST_CASE("", "[int BucketSize(const K&) const]") {
  //
}

TEST_CASE("", "[const LinkedList<K, V>& Bucket(const K&) const]") {
  //
}

TEST_CASE("", "[void Reserve(int)]") {
  //
}

TEST_CASE("", "[void Rehash()]") {
  //
}

TEST_CASE("", "[bool Key(const K&, const K&)]") {
  //
}

TEST_CASE("", "[V& operator[](const K&)]") {
  //
}

TEST_CASE("", "[bool operator==(const HashTable<K, V, H>&) const]") {
  //
}

TEST_CASE("", "[unsigned long long int Hash(const K&) const]") {
  //
}

TEST_CASE("", "[float LoadFactor() const]") {
  //
}

TEST_CASE("", "[float MaxLoadFactor() const]") {
  //
}

TEST_CASE("", "[void PrintBucketSizes() const]") {
  //
}
