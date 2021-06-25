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

  cout << ht.LoadFactor() << endl;

  return 0;
}