#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

// Interrupt descriptor table entry structure
struct IDTEntry {
    uint16_t offset_low;   // Lower 16 bits of the offset to the handler
    uint16_t selector;      // Selector in the GDT or LDT
    uint8_t zero;           // Reserved, must be zero
    uint8_t type_attr;      // Type and attributes
    uint16_t offset_high;  // Upper 16 bits of the offset to the handler
} __attribute__((packed));

// Function to initialize the interrupt descriptor table
void init_idt();

// Function to set an interrupt handler
void set_interrupt_handler(uint8_t interrupt_number, void (*handler)());

void interrupts_init();

// Function to handle interrupts
extern "C" void interrupt_handler(uint32_t interrupt_number);

#endif // INTERRUPTS_H