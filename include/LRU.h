#ifndef LRU_H
#define LRU_H

#include <iostream>
#include <vector>
using namespace std;

class LRU {
 private:
  vector<int> lru;

 public:
  void pin(int pageID);
  void unPin();
  int getLRUforDelete();
};

#endif