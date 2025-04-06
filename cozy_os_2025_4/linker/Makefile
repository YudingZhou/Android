# Makefile

CC = g++
AS = nasm
LD = ld

CFLAGS = -m32 -ffreestanding -c
LDFLAGS = -m32 -T build/linker.ld -o cozy_os.bin

KERNEL_OBJS = kernel/core/kernel.o \
              kernel/core/memory.o \
              kernel/core/process.o \
              kernel/core/interrupts.o \
              kernel/drivers/keyboard.o \
              kernel/drivers/screen.o

LIBC_OBJS = lib/libc/string.o \
            lib/libc/stdio.o

UTILS_OBJS = lib/utils/utils.o

BOOT_OBJS = boot/bootloader.o \
             boot/multiboot_header.o

all: cozy_os.bin

cozy_os.bin: $(BOOT_OBJS) $(KERNEL_OBJS) $(LIBC_OBJS) $(UTILS_OBJS)
	$(LD) $(LDFLAGS) $(BOOT_OBJS) $(KERNEL_OBJS) $(LIBC_OBJS) $(UTILS_OBJS)

%.o: %.asm
	$(AS) -f elf32 $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BOOT_OBJS) $(KERNEL_OBJS) $(LIBC_OBJS) $(UTILS_OBJS) cozy_os.bin

.PHONY: all clean