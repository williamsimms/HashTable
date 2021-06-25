#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "hashtable.h"

using namespace std;

int main() {
  HashTable<string, int> ht;

  unordered_map<string, int> ma(100);

  cout << ma.bucket_count() << endl;

  return 0;
}