#include "kernel.h"

void kernel_init() {
    // Initialize the kernel components
    memory_init();
    process_init();
    interrupts_init();
}

void kernel_main() {
    // Main kernel loop
    while (true) {
        // Handle processes and interrupts
    }
}