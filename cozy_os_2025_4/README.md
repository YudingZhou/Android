# Cozy OSS 2025.4

Cozy OSS 2025.4 is a mini operating system designed for x86 architecture, focusing on bootloading and essential kernel functions such as memory management and process management. This project aims to provide a lightweight and efficient operating system framework that can be further developed and customized.

## Project Structure

The project is organized into several directories, each serving a specific purpose:

- **boot**: Contains the bootloader and multiboot header necessary for initializing the system and loading the kernel.
- **kernel**: Implements core functionalities of the operating system, including memory management, process management, and interrupt handling.
  - **core**: Contains the main kernel code.
  - **include**: Header files for kernel functionalities.
  - **drivers**: Implements drivers for hardware interaction, such as keyboard and screen.
- **lib**: Contains libraries for basic functionalities, including standard C library implementations.
- **build**: Contains build scripts and linker scripts for compiling the operating system.
- **docs**: Documentation related to the design and architecture of the operating system.

## Getting Started

To build and run Cozy OSS 2025.4, follow these steps:

1. **Clone the Repository**: 
   ```
   git clone <repository-url>
   cd cozy_oss_2025_4
   ```

2. **Build the Project**: 
   Use the provided Makefile to compile the operating system.
   ```
   make
   ```

3. **Run the Operating System**: 
   You can use an emulator like QEMU to run the built operating system.
   ```
   qemu-system-x86_64 -kernel path/to/your/kernel
   ```

## Features

- **Bootloader**: A simple bootloader that initializes the system and loads the kernel.
- **Memory Management**: Basic memory allocation and deallocation functionalities.
- **Process Management**: Functions for creating, scheduling, and terminating processes.
- **Interrupt Handling**: Setup and management of interrupts for hardware interaction.
- **Drivers**: Basic drivers for keyboard input and screen output.

## Contributing

Contributions are welcome! Please feel free to submit issues or pull requests to enhance the functionality of Cozy OSS 2025.4.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Troubleshooting
1. qemu-system-x86_64: symbol lookup error: /snap/core20/current/lib/x86_64-linux-gnu/libpthread.so.0: undefined symbol: __libc_pthread_init, version GLIBC_PRIVATE
- this happens when launching qemu from vs terminal. solution is to launch from system terminal


2. ydzhou@iPotato:~/lab/android/cozy_os_2025_4/build$ make
[ 85%] Built target kernel_objects
ld: warning: /home/ydzhou/lab/android/cozy_os_2025_4/build/multiboot_header.o: missing .note.GNU-stack section implies executable stack
ld: NOTE: This behaviour is deprecated and will be removed in a future version of the linker
ld: warning: /home/ydzhou/lab/android/cozy_os_2025_4/build/cozy_os.bin has a LOAD segment with RWX permissions
/bin/sh: 1: /home/ydzhou/lab/android/cozy_os_2025_4/build/CMakeFiles/kernel_objects.dir/kernel/core/memory.cpp.o: Permission denied
/bin/sh: 1: /home/ydzhou/lab/android/cozy_os_2025_4/build/CMakeFiles/kernel_objects.dir/kernel/core/process.cpp.o: Permission denied
/bin/sh: 1: /home/ydzhou/lab/android/cozy_os_2025_4/build/CMakeFiles/kernel_objects.dir/kernel/core/interrupts.cpp.o: Permission denied
/bin/sh: 1: /home/ydzhou/lab/android/cozy_os_2025_4/build/CMakeFiles/kernel_objects.dir/kernel/drivers/keyboard.cpp.o: Permission denied
/bin/sh: 1: /home/ydzhou/lab/android/cozy_os_2025_4/build/CMakeFiles/kernel_objects.dir/kernel/drivers/screen.cpp.o: Permission denied
make[2]: *** [CMakeFiles/cozy_os.bin.dir/build.make:70: CMakeFiles/cozy_os.bin] Error 126
make[1]: *** [CMakeFiles/Makefile2:112: CMakeFiles/cozy_os.bin.dir/all] Error 2
make: *** [Makefile:91: all] Error 2
ydzhou@iPotato:~/lab/android/cozy_os_2025_4/build$ ls

- not RCA. workaround is not compiling other module from other source file, all files are in kernel.cpp. so there is one kernel object that needs to be linked with boot header. 