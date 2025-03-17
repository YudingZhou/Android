cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CppTypesProject)

# define headers
include_directories(${CMAKE_SOURCE_DIR}/includes)

# define source files
set(SRC
    src/m1_w1_d1_helloworld.cpp)

# Add the executable
add_executable(cpp_vector cpp_vector.cpp)
add_executable(cpp_pass_copy_vs_reference cpp_pass_copy_vs_reference.cpp)
add_executable(cpp_constructor cpp_construtors.cpp)
add_executable(m1_w1_d1 src/m1_w1_d1_helloworld.cpp)
