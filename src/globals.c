#include "allocator.h"

char heap[HEAP_CAPACITY] = {0};

Chunk_List allocated_chunks = {0};
Chunk_List freed_chunks = {
    .count = 1,
    .chunks = {
        [0] = {.start = heap, .size = sizeof(heap)}
    }
};
