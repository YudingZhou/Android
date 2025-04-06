#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdint.h>

// Function to initialize the keyboard driver
void keyboard_init();

// Function to read a key from the keyboard
uint8_t keyboard_read();

// Function to handle keyboard interrupts
void keyboard_interrupt_handler();

#endif // KEYBOARD_H