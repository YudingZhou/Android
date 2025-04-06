#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>

// Process control block structure
struct Process {
    uint32_t pid;          // Process ID
    uint32_t state;        // Process state (e.g., running, waiting, etc.)
    uint32_t priority;     // Process priority
    uint32_t stack_pointer_addr; // Stack pointer for the process
    // Additional fields can be added as needed
    void* stack_pointer;   // Pointer to the process's stack
};


// Function declarations
void process_init();                // Initialize process management
uint32_t create_process(void (*entry_point)()); // Create a new process
void schedule();                    // Schedule processes for execution
void terminate_process(uint32_t pid); // Terminate a process

#endif // PROCESS_H