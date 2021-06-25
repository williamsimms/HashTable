#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "hashtable.h"

using namespace std;

int main() {
  unordered_map<string, int> ma(100);

  HashTable<string, int> ht;
  ht.Insert("Hello", 4);

  cout << ht.LoadFactor() << endl;

  return 0;
}