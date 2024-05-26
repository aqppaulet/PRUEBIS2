#ifndef BUFFER_H
#define BUFFER_H

#include <unordered_map>
#include <vector>

#include "Page.h"

using namespace std;

class Buffer {
 private:
  int numFrames;
  int capacity;
  vector<Page> frames;

 public:
  Buffer();
  unordered_map<int, int> page_table;
  vector<Page>& getFrames();
  void setPage(Page& page, int frameID);
  void printPage(int frameID);

  void addRecord(int frameID);

  int freeFrame();
  void printPage_table();
};

#endif