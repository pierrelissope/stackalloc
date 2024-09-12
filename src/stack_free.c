
#include "allocator.h"
#include <stdio.h>
#include <assert.h>

void stack_free(void *ptr)
{
    if (ptr == NULL)
        return;
    const int index = chunk_list_find(&allocated_chunks, ptr);
    size_t size = allocated_chunks.chunks[index].size;

    assert(index != -1);
    chunk_list_remove(&allocated_chunks, index);
    chunk_list_insert(&freed_chunks, ptr, size);
    chunk_list_merge(&freed_chunks);
}
