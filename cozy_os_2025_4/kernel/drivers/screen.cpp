#include "screen.h"

void clear_screen() {
    // Implementation to clear the screen
}

void print_char(char c) {
    // Implementation to print a character to the screen
}

void print_string(const char* str) {
    while (*str) {
        print_char(*str++);
    }
}