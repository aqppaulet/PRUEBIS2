#ifndef BUFFERPOOLMANAGER_H
#define BUFFERPOOLMANAGER_H

#include <iostream>

#include "../include/LRU.h"
#include "Buffer.h"
#include "Page.h"

class BufferPoolManager {
 private:
  Buffer bf;
  LRU LRU_replace;
  int numFramesTotal;

 public:
  BufferPoolManager();

  void loadPageFromDisk(string blockPath);

  void updatePage();

  void deletePage();

  void savePageToDisk(int pageId);
};

#endif