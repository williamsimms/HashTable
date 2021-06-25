#include <iostream>
#include <unordered_map>
#include <vector>

#include "hashtable.h"

using namespace std;

int main(void) {
  HashTable<string, int> ht;

  string k = "Hello";
  auto h = ht.Hash(k);

  cout << h << endl;

  return 0;
}