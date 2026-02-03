#include "MemoryManager.h"
#include <iostream>
#include <cstring>

MemoryManager::MemoryManager(size_t size)
    : heapSize(size), headOffset(0) {

    heap = new uint8_t[heapSize];
    std::memset(heap, 0, heapSize);

    auto* head = reinterpret_cast<BlockHeader*>(heap);
    head->size = heapSize - sizeof(BlockHeader);
    head->free = true;
    head->next = SIZE_MAX;
    head->prev = SIZE_MAX;
}

MemoryManager::~MemoryManager() {
    delete[] heap;
}

size_t MemoryManager::align(size_t n) const {
    return (n + 7) & ~static_cast<size_t>(7);
}

void* MemoryManager::allocate(size_t) {
    return nullptr; // stub for now
}

bool MemoryManager::freeBlock(void*) {
    return false; // stub for now
}

void MemoryManager::printHeap() const {
    size_t offset = headOffset;
    int index = 0;

    while (offset != SIZE_MAX) {
        const auto* block =
            reinterpret_cast<const BlockHeader*>(heap + offset);

        std::cout << "Block " << index++
                  << ": " << (block->free ? "FREE " : "USED ")
                  << " size=" << block->size << "\n";

        offset = block->next;
    }
}