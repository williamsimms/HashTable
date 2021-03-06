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
  HashTable<string, int> table;
  table.Insert("hello", 1);
  REQUIRE(table.Size() == 1);
  REQUIRE(table.BucketCount() == 8);

  HashTable<string, int> tableTwo;
  tableTwo = table;
  REQUIRE(tableTwo.Size() == 1);
  REQUIRE(tableTwo.BucketCount() == 8);
  REQUIRE(table == tableTwo);
}

TEST_CASE("Move Assignment Operator",
          "[HashTable<K, V, H>& operator=(HashTable<K, V, H>&&)]") {
  HashTable<string, int> table;
  table.Insert("hello", 1);
  REQUIRE(table.Size() == 1);
  REQUIRE(table.BucketCount() == 8);

  HashTable<string, int> tableTwo;
  tableTwo = std::move(table);
  REQUIRE(tableTwo.Size() == 1);
  REQUIRE(tableTwo.BucketCount() == 8);

  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 0);
}

TEST_CASE(
    "Checks if the Hash Table is Empty, Return true if the Hash Table is "
    "Empty, returns false otherwise.",
    "[bool Empty() const]") {
  HashTable<string, int> table;

  bool isEmpty = table.Empty();
  REQUIRE(isEmpty == true);

  table.Insert("hello", 1);
  REQUIRE(table.Size() == 1);
  REQUIRE(table.BucketCount() == 8);

  isEmpty = table.Empty();
  REQUIRE(isEmpty == false);
}

TEST_CASE("Returns the Size of the Hash Table.", "[int Size() const]") {
  HashTable<string, int> table;

  table.Insert("hello", 1);
  REQUIRE(table.Size() == 1);

  table.Insert("hello", 1);
  REQUIRE(table.Size() == 1);

  table.Insert("Hi", 2);
  REQUIRE(table.Size() == 2);

  table.Insert("Hey", 3);
  REQUIRE(table.Size() == 3);
}

TEST_CASE("Clears the HashTable, sets the size to zero and resets the memory.",
          "[void Clear()]") {
  HashTable<string, int> table;

  table.Insert("Hello", 1);
  REQUIRE(table.Size() == 1);

  table.Insert("Hi", 2);
  REQUIRE(table.Size() == 2);

  table.Clear();

  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 8);
}

TEST_CASE("Clears the HashTable, sets the size to zero & frees the memory.",
          "[void Free()]") {
  HashTable<string, int> table;

  table.Insert("Hello", 1);
  REQUIRE(table.Size() == 1);

  table.Insert("Hi", 2);
  REQUIRE(table.Size() == 2);

  table.Free();

  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 0);
}

TEST_CASE("Inserts a New Element to the Hash Table using L Value.",
          "[void Insert(const K& key, const V& value)]") {
  HashTable<string, int> table;

  int x = 5;
  table.Insert("Hello", x);
  REQUIRE(table.Size() == 1);

  int y = 55;
  table.Insert("Hi", y);
  REQUIRE(table.Size() == 2);
}

TEST_CASE("Inserts a New Element to the Hash Table Using R Value.",
          "[void Insert(const K& key, V&& value)]") {
  SECTION("Inserts a new Element to the HashTable using L Value.") {
    HashTable<string, int> table;

    table.Insert("Hello", 5);
    REQUIRE(table.Size() == 1);

    table.Insert("Hi", 55);
    REQUIRE(table.Size() == 2);
  }
}

TEST_CASE("Emplaces a new Element into the hashtable.",
          "[void Emplace(const K&, Args&&...)]") {
  SECTION("Inserts a new Element to the HashTable using L Value.") {
    HashTable<string, Vector2> table;

    table.Emplace("Hello", 1, 2);
    REQUIRE(table.Size() == 1);

    table.Emplace("Hi", 5, 5);
    REQUIRE(table.Size() == 2);
  }
}

TEST_CASE("Erases an Element in the Hash Table Using the provided Key.",
          "[bool Erase(const K&)]") {
  HashTable<string, int> table;

  table.Insert("Hello", 5);
  REQUIRE(table.Size() == 1);

  table.Insert("Hi", 55);
  REQUIRE(table.Size() == 2);

  bool elementAtKeyRemoved = table.Erase("Hey");
  REQUIRE(elementAtKeyRemoved == false);
  REQUIRE(table.Size() == 2);

  elementAtKeyRemoved = table.Erase("Hello");
  REQUIRE(elementAtKeyRemoved == true);
  REQUIRE(table.Size() == 1);

  elementAtKeyRemoved = table.Erase("Hi");
  REQUIRE(elementAtKeyRemoved == true);
  REQUIRE(table.Size() == 0);

  elementAtKeyRemoved = table.Erase("Yellow");
  REQUIRE(elementAtKeyRemoved == false);
  REQUIRE(table.Size() == 0);
}

TEST_CASE("Returns a Reference to the Element at the Provided Key.",
          "[V& At(const K&)]") {
  HashTable<string, int> table;

  table.Insert("Hello", 5);
  REQUIRE(table.Size() == 1);

  table.Insert("Hi", 55);
  REQUIRE(table.Size() == 2);

  int value = table.At("Hi");
  REQUIRE(value == 55);

  value = table.At("Hello");
  REQUIRE(value == 5);
}

TEST_CASE("Returns the Size of the bucket at the provided Key.",
          "[int Count(const K&) const]") {
  HashTable<string, int> table;

  int count = table.Count("Hello");
  REQUIRE(count == 0);

  table.Insert("Hello", 2);
  count = table.Count("Hello");
  REQUIRE(count == 1);
}

TEST_CASE("Returns the Size of the bucket at the provided index.",
          "[int Count(int) const]") {
  HashTable<string, int> table;

  int count = table.Count(1);
  REQUIRE(count == 0);
}

TEST_CASE("Returns true if the element is in the HashTable, false otherwise.",
          "[bool Contains(const K&) const]") {
  HashTable<string, int> table;
  table.Insert("Hello", 2);

  bool contains = table.Contains("Hello");
  REQUIRE(contains == true);

  contains = table.Contains("Hi");
  REQUIRE(contains == false);
}

TEST_CASE("Retruns the amount of Buckets in the HashTable.",
          "[int BucketCount() const]") {
  SECTION("Uses 8 as the default bucket size.") {
    HashTable<string, int> table;
    REQUIRE(table.BucketCount() == 8);
  }

  SECTION(
      "Rounds up to the nearest multiple of 8, when a size is provided in the "
      "constructor.") {
    HashTable<string, int> table(100);
    REQUIRE(table.BucketCount() == 104);
  }
}

TEST_CASE("Retunrns the bucket at the specified key.",
          "[const LinkedList<K, V>& Bucket(const K&) const]") {
  HashTable<string, int> table;
  table.Insert("Hello", 5);
  const LinkedList<string, int>& bucket = table.Bucket("Hello");
  REQUIRE(bucket.Size() == 1);
  REQUIRE(bucket.At(0)->value == 5);
}

TEST_CASE("Reserves the amount of buckets, provided in the parameter.",
          "[void Reserve(int)]") {
  HashTable<string, int> table;
  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 8);
  table.Reserve(100);
  REQUIRE(table.BucketCount() == 104);
}

TEST_CASE(
    "Rehashes the Hash Table, increases the bucket size by three times its "
    "current size.",
    "[void Rehash()]") {
  HashTable<string, int> table;
  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 8);
  table.Rehash();
  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 24);
}

TEST_CASE(
    "Rehashes the Hash Table, increases the bucket size by the amount "
    "provided.",
    "[void Rehash(int))]") {
  HashTable<string, int> table;
  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 8);
  table.Rehash(100);
  REQUIRE(table.Size() == 0);
  REQUIRE(table.BucketCount() == 100);
}

TEST_CASE("Checks if two provided keys are equal.",
          "[bool Key(const K&, const K&)]") {
  HashTable<string, int> table;
  bool isEqual = table.Key("Hello", "Hello");
  REQUIRE(isEqual == true);
  isEqual = table.Key("Hello", "Hi");
  REQUIRE(isEqual == false);
}

TEST_CASE(
    "Returns a Reference to an Element in the HashTable. Can also be used to "
    "insert a new element in the HashTable.",
    "[V& operator[](const K&)]") {
  HashTable<string, int> table;
  table.Insert("Hello", 4);
  REQUIRE(table["Hello"] == 4);
}

TEST_CASE(
    "Returns true if the Two Hash Tables are Deeply Equal, false otherwise.",
    "[bool operator==(const HashTable<K, V, H>&) const]") {
  HashTable<string, int> tableOne;
  HashTable<string, int> tableTwo;
  HashTable<string, int> tableThree;
  HashTable<string, int> tableFour;

  tableOne.Insert("Hello", 5);
  tableTwo.Insert("Hello", 5);
  tableThree.Insert("Ok", 12);
  tableFour.Insert("Hello", 11);

  REQUIRE((tableOne == tableTwo) == true);
  REQUIRE((tableTwo == tableThree) == false);
  REQUIRE((tableOne == tableThree) == false);
  REQUIRE((tableOne == tableFour) == false);
}

TEST_CASE("Retuns the current Load Factor of the HashTable.",
          "[float LoadFactor() const]") {
  HashTable<string, int> table;
  REQUIRE(table.LoadFactor() == 0);

  table.Insert("Hello", 2);
  REQUIRE(table.LoadFactor() > 0);
}

TEST_CASE("Returns the maximum allowed Load Factor of the HashTable.",
          "[float MaxLoadFactor() const]") {
  HashTable<string, int> table;
  REQUIRE(table.MaxLoadFactor() == 1);
}
