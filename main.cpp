#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "hashtable.h"
#include "linkedlist.h"

using namespace std;

int main() {
  HashTable<string, int> ht;

  int x = 5;

  ht.Insert("William", x);
  ht.Insert("Javier", x);
  ht.Insert("Xavier", x);
  ht.Insert("Anthony", x);
  ht.Insert("s", x);
  ht.Insert("Arthdur", x);
  ht.Insert("Arthur", x);
  ht.Insert("Arthudr", x);

  // ht.Insert("Arthussfdgr", x);

  // ht.Insert("Arthur", x);
  // ht.Insert("Arthusrd", x);
  // ht.Insert("Arthusr", x);
  // ht.Insert("Arthudr", x);
  // ht.Insert("Arthudr", x);

  cout << ht.LoadFactor() << endl;
  cout << ht.Size() << endl;
  cout << ht.BucketCount() << endl;

  return 0;
}