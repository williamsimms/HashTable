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

  ht.Insert("Heldasdaslo", 4);
  ht.Insert("Helasdaslo", 4);
  ht.Insert("Helsdasdsadlo", 4);
  ht.Insert("Helssdlo", 4);
  ht.Insert("Hessadasdallo", 4);
  ht.Insert("Heslasdlo", 4);
  ht.Insert("Hedlsdasdlo", 4);
  ht.Insert("Headasdsdllo", 4);
  ht.Insert("sd", 4);
  ht.Insert("Helasdasdaslo", 4);
  ht.Insert("Helasdasdlo", 4);
  ht.Insert("asdasd", 4);
  ht.Insert("Hesdllo", 4);
  ht.Insert("Heasdsallo", 4);
  ht.Insert("dasd", 4);
  ht.Insert("Hesadllo", 4);

  float x = ht.LoadFactor();
  cout << x << endl;

  return 0;
}