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