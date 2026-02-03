#pragma once
#include <cstddef>
#include <cstdint>

class MemoryManager {
public:
    explicit MemoryManager(size_t heapSize);
    ~MemoryManager();

    void* allocate(size_t bytes);
    bool freeBlock(void* ptr);

    void printHeap() const;

private:
    struct BlockHeader {
        size_t size;   // payload size
        bool free;
        size_t next;   // offset to next block
        size_t prev;   // offset to previous block
    };

    uint8_t* heap;
    size_t heapSize;
    size_t headOffset;

    size_t align(size_t n) const;
};