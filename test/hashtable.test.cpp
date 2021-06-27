#define CATCH_CONFIG_MAIN

#include "../hashtable.h"
#include "../utility/Vector3.hpp"
#include "../vendor/catch.hpp"

TEST_CASE("", "[HashTable()]") {
  //
}

TEST_CASE("", "[HashTable(int)]") {
  //
}

TEST_CASE("", "[HashTable(const HashTable<K,V,H>&)]") {
  //
}

TEST_CASE("", "[HashTable(HashTable<K,V,H>&&)]") {
  //
}

TEST_CASE("", "[operator=]") {
  //
}

TEST_CASE("", "[Empty]") {
  //
}

TEST_CASE("", "[Size]") {
  //
}

TEST_CASE("", "[Clear]") {
  //
}

TEST_CASE("Inserts a New Element to the Hash Table.",
          "[Insert(const K& key, const V& value)]") {
  SECTION("Inserts a new Element to the HashTable.") {
    //
  }
}

TEST_CASE("Inserts a New Element to the Hash Table.",
          "[Insert(const K& key, V&& value)]") {
  SECTION("Inserts a new Element to the HashTable using L Value.") {
    //
  }
}

TEST_CASE("Emplaces a new Element into the hashtable.",
          "[Emplace(const K&, Args&&...)]") {
  SECTION("Inserts a new Element to the HashTable using L Value.") {
    //
  }
}