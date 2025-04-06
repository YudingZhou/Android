cmake_minimum_required(VERSION 3.16)
project(cozy_os_2025_4 LANGUAGES C CXX ASM)

# Set the target architecture to 32-bit
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32 -ffreestanding")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32 -ffreestanding")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -f elf32")

# includes 
include_directories(
    ${CMAKE_SOURCE_DIR}/kernel/include
)

if (EXISTS ${CMAKE_SOURCE_DIR}/kernel/include)
    message("include exists" )
else()
    message("include does not exist" )
endif()

# Specify the linker script
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/linker/linker.ld)

# Add source files
set(BOOT_SOURCES
    #boot/bootloader.asm  for bootloaders than GRUB
    boot/multiboot_header.asm
)

set(KERNEL_SOURCES
    kernel/core/kernel.cpp
    kernel/core/memory.cpp
    kernel/core/process.cpp
    kernel/core/interrupts.cpp
    kernel/drivers/keyboard.cpp
    kernel/drivers/screen.cpp
)

set(LIBC_SOURCES
    #lib/libc/string.cpp
    #lib/libc/stdio.cpp
)

set(UTILS_SOURCES
    #lib/utils/utils.cpp
)

# Assemble bootloader files
foreach(ASM_FILE ${BOOT_SOURCES})
    get_filename_component(ASM_NAME ${ASM_FILE} NAME_WE)
    add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/${ASM_NAME}.o
        COMMAND nasm -f elf32 ${CMAKE_SOURCE_DIR}/${ASM_FILE} -o ${CMAKE_BINARY_DIR}/${ASM_NAME}.o
        DEPENDS ${CMAKE_SOURCE_DIR}/${ASM_FILE}
    )
    list(APPEND BOOT_OBJECTS ${CMAKE_BINARY_DIR}/${ASM_NAME}.o)
endforeach()

# Compile kernel, libc, and utils sources
add_library(kernel_objects OBJECT ${KERNEL_SOURCES})
#add_library(libc_objects OBJECT ${LIBC_SOURCES})
#add_library(utils_objects OBJECT ${UTILS_SOURCES})

# Link everything into the final binary

message("BOOT_OBJECTS: ${BOOT_OBJECTS}")
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message("TARGET_OBJECTS:KERNEL_OBJECT: $<TARGET_OBJECTS:kernel_objects> ")

get_target_property(KERNEL_OBJECTS_FILES kernel_objects OBJECTS)
message("kernel objects file ${KERNEL_OBJECTS_FILES}")
add_custom_target(cozy_os.bin ALL
    DEPENDS kernel_objects  ${BOOT_OBJECTS} #libc_objects utils_objects

    COMMAND ld -m elf_i386 -T ${LINKER_SCRIPT} -o ${CMAKE_BINARY_DIR}/cozy_os.bin ${BOOT_OBJECTS} 
    
    $<TARGET_OBJECTS:kernel_objects>  
    #$<TARGET_OBJECTS:libc_objects> $<TARGET_OBJECTS:utils_objects>
)

# Clean target
add_custom_target(clean_1
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_BINARY_DIR}/cozy_os.bin ${BOOT_OBJECTS}
)