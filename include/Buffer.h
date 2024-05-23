#ifndef BUFFER_H
#define BUFFER_H

#include <vector>

#include "include/Page.h"

using namespace std;

class Buffer {
 private:
  int numFrames;
  long int capacity;
  vector<Page> frames;

 public:
  vector<Page>& getFrames();
  void setPage(Page& page);
};

#endif