#include "allocator.h"
#include <assert.h>

int chunk_list_find(const Chunk_List *list, void *ptr)
{
    for (size_t i = 0; i < list->count; ++i) {
        if (list->chunks[i].start == ptr) {
            return i;
        }
    }
    return -1;
}

void chunk_list_remove(Chunk_List *list, size_t index)
{
    assert(index <= list->count);    

    for (size_t i = index; i < list->count - 1; ++i) {
        list->chunks[i] = list->chunks[i + 1];
    }
    --(list->count);
}

void chunk_list_merge(Chunk_List *src)
{
    size_t i = 0;

    while (i < src->count - 1) {
        if (src->chunks[i].start + src->chunks[i].size == src->chunks[i + 1].start) {
            src->chunks[i].size += src->chunks[i + 1].size;
            chunk_list_remove(src, i + 1);
        } else {
           ++i;
        }
    }
}

void chunk_list_insert(Chunk_List *list, void *start, size_t size)
{
    assert(list->count < CHUNK_LIST_CAPACITY);
    list->chunks[list->count].start = start;
    list->chunks[list->count].size = size;
   

    for (int i = list->count; i > 0 && (list->chunks[i].start < list->chunks[i - 1].start); --i) {
        const Chunk temp = list->chunks[i];
        list->chunks[i] = list->chunks[i - 1];
        list->chunks[i - 1] = temp;
    }
    ++(list->count);
}

Chunk get_splited_chunk(Chunk *chunk, int index, size_t size)
{
    if (chunk->size == size) {
        chunk_list_insert(&allocated_chunks, chunk->start, chunk->size);
        chunk_list_remove(&freed_chunks, index);
        return *chunk;
    } else {
        chunk_list_insert(&allocated_chunks, chunk->start + size, chunk->size - size);
        chunk->size = size;
        return *chunk;
    }
}
