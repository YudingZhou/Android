#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>

// Function to initialize the screen
void init_screen();

// Function to clear the screen
void clear_screen();

// Function to print a character to the screen
void putchar(char c);

// Function to print a string to the screen
void puts(const char* str);

// Function to set the cursor position
void set_cursor_position(uint16_t x, uint16_t y);

#endif // SCREEN_H