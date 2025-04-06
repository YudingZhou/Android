; multiboot_header.asm
; This file defines the multiboot header for the Cozy OSS 2025.4 operating system.

section .multiboot_header
    align 4
    dd 0x1BADB002          ; magic number
    dd 0x00                ; flags
    dd - (0x1BADB002 + 8)  ; checksum

section .text
    ; The entry point for the bootloader will jump here
    global _start
_start:
    ; Bootloader code will go here
    ; This is where the kernel will be loaded and executed.