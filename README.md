# Stack-Based Memory Allocator

This repository contains a stack-based memory allocator. Below are the annotations and descriptions for the various components and functions within the allocator.

### Components

1. **Memory Block**: Represents a block of memory in the stack.
2. **Stack Pointer**: Points to the current top of the stack.
3. **Allocator**: Manages the allocation and deallocation of memory blocks.

### Functions

- `stack_alloc(size_t size) -> pointer`: Allocates a block of memory of the given size.
- `stack_free(void *ptr) -> None`: Deallocates the given block of memory.

### Usage

2. **Allocation**: Allocate memory blocks as needed.
3. **Deallocation**: Deallocate memory blocks when they are no longer needed.

### Example

```c
void *ptr = stack_alloc(6);

strcpy(ptr, "hello");
printf("Content: %s\n", ptr);

stack_free(ptr);
```

### Notes

- Ensure that the stack size is sufficient for the application's memory requirements.
- Always deallocate memory blocks to prevent memory leaks.

### License

This project is licensed under the MIT License.

##### Made by Pierre LISSOPE
