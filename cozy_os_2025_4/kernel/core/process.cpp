#include "process.h"

static Process process_table[256]; // Example process table
static int next_pid = 1; // PID counter

void init_process_management() {
    // Initialize the process table
    for (int i = 0; i < 256; i++) {
        process_table[i].pid = 0; // Mark as unused
    }
}

int create_process() {
    for (int i = 0; i < 256; i++) {
        if (process_table[i].pid == 0) { // Find an unused slot
            process_table[i].pid = next_pid++;
            // Additional process initialization can be done here
            return process_table[i].pid; // Return the new PID
        }
    }
    return -1; // No available process slots
}

void terminate_process(int pid) {
    for (int i = 0; i < 256; i++) {
        if (process_table[i].pid == pid) {
            process_table[i].pid = 0; // Mark as unused
            // Additional cleanup can be done here
            return;
        }
    }
}

void schedule() {
    // Implement scheduling logic here
}
