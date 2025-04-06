#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

// Memory management functions
void* allocate_memory(size_t size);
void deallocate_memory(void* ptr);
void memory_init();

#endif // MEMORY_H