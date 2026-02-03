#include "MemoryManager.h"
#include <iostream>

int main() {
    MemoryManager mm(1024); // 1 KB heap for testing

    std::cout << "Initial heap state:\n";
    mm.printHeap();

    return 0;
}