#define CATCH_CONFIG_MAIN

#include "../hashtable.h"
#include <string>
#include "../utility/Vector3.hpp"
#include "../vendor/catch.hpp"

using std::string;

TEST_CASE("Default Constructor", "[HashTable()]") {
  HashTable<string, int> table;
  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 8);
}

TEST_CASE("Constructor with Bucket Size", "[HashTable(int)]") {
  HashTable<string, int> table(100);
  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 104);
}

TEST_CASE("Copy Constructor", "[HashTable(const HashTable<K,V,H>&)]") {
  HashTable<string, int> table;
  table.Insert("hello", 1);
  REQUIRE(table.Size() == 1);
  REQUIRE(table.BucketCount() == 8);

  HashTable<string, int> tableTwo(table);
  REQUIRE(tableTwo.Size() == 1);
  REQUIRE(tableTwo.BucketCount() == 8);
  REQUIRE(table.Size() == 1);
  REQUIRE(table.BucketCount() == 8);
}

TEST_CASE("Move Contructor", "[HashTable(HashTable<K,V,H>&&)]") {
  HashTable<string, int> table;
  table.Insert("hello", 1);
  REQUIRE(table.Size() == 1);
  REQUIRE(table.BucketCount() == 8);

  HashTable<string, int> tableTwo(std::move(table));
  REQUIRE(tableTwo.Size() == 1);
  REQUIRE(tableTwo.BucketCount() == 8);

  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 0);
}

TEST_CASE("Copy Assignment Operator",
          "[HashTable<K, V, H>& operator=(const HashTable<K, V, H>&)]") {
  //
}

TEST_CASE("Move Assignment Operator",
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

TEST_CASE("Returns a Reference to the Element at the Provided Key.",
          "[V& At(const K&)]") {
  //
}

TEST_CASE("Returns a const Reference to the Element at the Provided Key.",
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

TEST_CASE(
    "Returns a reference to the Element at the provided Key using Find Method.",
    "[V& Find(const K&)]") {
  //
}

TEST_CASE(
    "Returns a const reference to the Element at the provided Key using Find "
    "Method.",
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

TEST_CASE(
    "Returns true if the Two Hash Tables are Deeply Equal, false otherwise.",
    "[bool operator==(const HashTable<K, V, H>&) const]") {
  //
}

TEST_CASE("Hashes the provided key.",
          "[unsigned long long int Hash(const K&) const]") {
  //
}

TEST_CASE("Retuns the current Load Factor of the HashTable.",
          "[float LoadFactor() const]") {
  //
}

TEST_CASE("Returns the maximum allowed Load Factor of the HashTable.",
          "[float MaxLoadFactor() const]") {
  //
}
