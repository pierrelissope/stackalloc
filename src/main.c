#include "allocator.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

void chunk_list_dump(const Chunk_List *list)
{
    for (size_t i = 0; i < list->count; ++i) {
        printf("---------CHUNK---------\n");
        printf("START: %p\nSIZE: %zu\n", list->chunks[i].start, list->chunks[i].size);
        for (size_t j = 0; j < list->chunks[i].size; ++j) {
            char *mem = list->chunks[i].start;
            printf("%c", mem[j]);
        }
        printf("\n-----------------------\n\n");
    }
}

void dump_chunks(void)
{
    printf("Allocated Chunks: %zu\n", allocated_chunks.count);
    chunk_list_dump(&allocated_chunks);
    printf("\n");
    printf("Freed Chunks: %zu\n", freed_chunks.count);
    chunk_list_dump(&freed_chunks); 
}

void heap_collect(void)
{
    assert(0 && "Heap Collect Not implemented yet");
}

char *my_dupplicate(char *string)
{
    size_t len = strlen(string);
    char *p2 = stack_alloc(sizeof(char) * len);

    for (size_t i = 0; i <= len; ++i) {
        p2[i] = string[i];
    }
    return p2;
}

int main(void)
{
    void *p1 = stack_alloc(15);
    void *p2 = my_dupplicate("Hello World\n");

    void *p3 = stack_alloc(5);
    void *p4 = stack_alloc(5);

    stack_free(p1);
    stack_free(p3);

    dump_chunks();
}
