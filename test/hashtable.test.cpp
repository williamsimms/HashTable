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

TEST_CASE(
    "Checks if the Hash Table is Empty, Return true if the Hash Table is "
    "Empty, returns false otherwise.",
    "[bool Empty() const]") {
  //
}

TEST_CASE("Returns the Size of the Hash Table.", "[int Size() const]") {
  //
}

TEST_CASE("Clears the HashTable, sets the size to zero.", "[void Clear()]") {
  //
}

TEST_CASE("Inserts a New Element to the Hash Table using L Value.",
          "[void Insert(const K& key, const V& value)]") {
  //
}

TEST_CASE("Inserts a New Element to the Hash Table Using R Value.",
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

TEST_CASE("Erases an Element in the Hash Table Using the provided Key.",
          "[bool Erase(const K&)]") {
  //
}

TEST_CASE("Returns a Reference to th Element at the Provided Key.",
          "[V& At(const K&)]") {
  //
}

TEST_CASE("Returns a Reference to th Element at the Provided Key.",
          "[const V& At(const K&)]") {
  //
}

TEST_CASE("Returns the Size of the bucket at the provided Key.",
          "[int Count(const K&) const]") {
  //
}

TEST_CASE("Returns the Size of the bucket at the provided index.",
          "[int Count(int) const]") {
  //
}

TEST_CASE("Returns a reference to the Element at the provided Key.",
          "[V& Find(const K&)]") {
  //
}

TEST_CASE("Returns a reference to the Element at the provided Key.",
          "[const V& Find(const K&) const]") {
  //
}

TEST_CASE("Returns true if the element is in the HashTable, false otherwise.",
          "[bool Contains(const K&) const]") {
  //
}

TEST_CASE("Retruns the amount of Buckets in the HashTable.",
          "[int BucketCount() const]") {
  //
}

TEST_CASE("Retunrns the bucket at the specified key.",
          "[const LinkedList<K, V>& Bucket(const K&) const]") {
  //
}

TEST_CASE("Reserves the amount of buckets, provided in the parameter.",
          "[void Reserve(int)]") {
  //
}

TEST_CASE(
    "Rehashes the Hash Table, increases the bucket size by three times its "
    "current size.",
    "[void Rehash()]") {
  //
}

TEST_CASE("Checks if two provided keys are equal.",
          "[bool Key(const K&, const K&)]") {
  //
}

TEST_CASE(
    "Returns a Reference to an Element in the HashTable. Can also be used to "
    "insert a new element in the HashTable.",
    "[V& operator[](const K&)]") {
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
