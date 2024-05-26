#include <iostream>

#include "include/BufferPoolManager.h"
#include "include/Page.h"

int main() {
  BufferPoolManager BfManger;

  while (true) {
    int instruction;
    std::cout << "1. Load page " << endl;
    std::cout << "2. Read a page " << endl;
    std::cout << "3. Update a page " << endl;
    std::cout << "4. Save page " << endl;
    std::cout << "5. Exit" << endl;
    std::cin >> instruction;

    if (instruction == 5) {
      break;
    } else if (instruction == 1) {
      BfManger.loadPageFromDisk("bloque1");
    } else if (instruction == 3) {
      BfManger.updatePage();
    }
  }
  return 0;
}