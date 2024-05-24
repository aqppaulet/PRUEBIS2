#ifndef BUFFERPOOLMANAGER_H
#define BUFFERPOOLMANAGER_H

#include <iostream>

#include "../include/Page.h"
#include "Buffer.h"

class BufferPoolManager {
 private:
  Buffer bf;
  int numFramesTotal;

 public:
  BufferPoolManager();

  void loadPageFromDisk(string blockPath);

  void updatePage();

  void deletePage();

  void flushPage();
};

#endif