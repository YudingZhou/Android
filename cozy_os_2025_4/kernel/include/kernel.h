#ifndef KERNEL_H
#define KERNEL_H

#include <stddef.h>
#include "interrupts.h"
#include "memory.h"
#include "process.h"

// Function declarations for kernel initialization and main loop
void kernel_init();
void kernel_main();

// Function declarations for process management
void create_process(Process* proc);
void schedule_process();
void terminate_process(int pid);

// Function declarations for memory management
// size_t is the memory address size. it is hardware dependent.
// reflecting the range of the address space.
// like on 32-bit it is 4 bytes, on 64-bit it is 8 bytes.
void* allocate_memory(size_t size);
void free_memory(void* ptr);

#endif // KERNEL_H