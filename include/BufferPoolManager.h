#ifndef BUFFERPOOLMANAGER_H
#define BUFFERPOOLMANAGER_H

#include <iostream>
#include <unordered_map>

class BufferPoolManager {
 public:
  std::unordered_map<int, int> page_table;
};

#endif