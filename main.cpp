#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "hashtable.h"
#include "linkedlist.h"

using namespace std;

int main() {
  HashTable<string, int> ht(100);

  // ht.Insert("William", 1);
  // ht.Insert("Javier", 2);
  // ht.Insert("Xavier", 2);
  // ht.Insert("Anthony", 2);
  // ht.Insert("s", 2);
  // ht.Insert("Arthdur", 2);
  // ht.Insert("Arthur", 2);
  // ht.Insert("Arthudr", 2);
  // ht.Insert("Arthurd", 2);
  // ht.Insert("Arthur", 2);
  // ht.Insert("Arthusrd", 2);
  // ht.Insert("Arthusr", 2);
  // ht.Insert("Arthudr", 2);
  // ht.Insert("Arthudr", 2);

  cout << ht.BucketCount();

  return 0;
}