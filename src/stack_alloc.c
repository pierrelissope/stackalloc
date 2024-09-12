#include "allocator.h"
#include <stdio.h>

void *stack_alloc(size_t size)
{
    if (size <= 0)
        return NULL;
    for (size_t i = 0; i < freed_chunks.count; ++i) {
        if (freed_chunks.chunks[i].size >= size) {
            if (freed_chunks.chunks[i].size == size) {
                chunk_list_insert(&allocated_chunks, freed_chunks.chunks[i].start, freed_chunks.chunks[i].size); 
                chunk_list_remove(&freed_chunks, i);
                return freed_chunks.chunks[i].start;
            } else {
                chunk_list_insert(&allocated_chunks, freed_chunks.chunks[i].start, size);
                freed_chunks.chunks[i].start += size;
                freed_chunks.chunks[i].size -= size;
                return freed_chunks.chunks[i].start - size;

            }
        }
    }
    return NULL;
}


