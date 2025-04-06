; bootloader.asm
; This file contains the assembly code for the bootloader, responsible for initializing the system and loading the kernel.

section .text
    global _start

_start:
    ; Set up the stack
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7c00

    ; Load the kernel (assuming it is located at 0x1000)
    mov si, kernel_load_message
    call print_string

    ; Load the kernel into memory
    mov ax, 0x1000
    mov bx, 0x0000
    mov cx, 0x0001
    mov dx, 0x0000
    int 0x13

    ; Jump to the kernel
    jmp 0x1000

print_string:
    ; Print a string pointed to by SI
    mov ah, 0x0E
.next_char:
    lodsb
    test al, al
    jz .done
    int 0x10
    jmp .next_char
.done:
    ret

section .data
kernel_load_message db 'Loading kernel...', 0