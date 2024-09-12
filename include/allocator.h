#pragma once

#define HEAP_CAPACITY 6000
#define CHUNK_LIST_CAPACITY 1024

#include <stdio.h>

typedef struct {
    void *start;
    size_t size;
} Chunk;

typedef struct {
    size_t count;
    Chunk chunks[CHUNK_LIST_CAPACITY];
} Chunk_List;

extern char heap[HEAP_CAPACITY];
extern Chunk_List freed_chunks;
extern Chunk_List allocated_chunks;

int chunk_list_find(const Chunk_List *list, void *ptr);
void chunk_list_remove(Chunk_List *list, size_t index);
void chunk_list_merge(Chunk_List *src);
void chunk_list_insert(Chunk_List *list, void *start, size_t size);
Chunk get_splited_chunk(Chunk *chunk, int index, size_t size);

void *stack_alloc(size_t size);
void stack_free(void *ptr);
