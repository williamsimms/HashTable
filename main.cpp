#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "hashtable.h"
#include "linkedlist.h"
#include "utility/Vector3.hpp"

using namespace std;

int main() {
  cout << boolalpha;

  HashTable<string, int> ht;

  // int x = 5;

  // ht.Insert("William", x);
  // ht.Insert("Javier", x);
  // ht.Insert("Xavier", x);
  // ht.Insert("Anthony", x);
  // ht.Insert("s", x);
  // ht.Insert("Arthdur", x);
  // ht.Insert("Arthur", x);
  // ht.Insert("Arthudr", x);
  // ht.Insert("Arthussfdgr", 2);

  // cout << ht["William"];

  // ht.Insert("Arthur", x);
  // ht.Insert("Arthusrd", x);
  // ht.Insert("Arthusr", x);
  // ht.Insert("Arthudr", x);
  // ht.Insert("Arthudr", x);

  Vector3 v(1, 2, 3);

  HashTable<string, Vector3> htt;
  htt.Insert("Stirng", v);

  // cout << htt["Stirng"] << endl;

  return 0;
}