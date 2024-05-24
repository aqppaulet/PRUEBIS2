#include <iostream>

#include "include/BufferPoolManager.h"
#include "include/Page.h"

int main() {
    while (true) {
        int instruction;
        std::cout << "Select an instruction: 1. Create a new page 2. Read a page 3. Write a page 4. Exit" << std::endl;
        std::cin >> instruction;
        if (instruction == 4) {
            break;
        }
    }
    return 0;
}