cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CppTypesProject)

# define headers
include_directories(${CMAKE_SOURCE_DIR}/includes)

# define source files
set(SRC
    src/m1_w1_d1_helloworld.cpp
    src/m1_w1_d2_datatype_variables_operators.cpp
    src/helper.cpp)

# Add the executable
add_library(cpp_lib ${SRC})

add_executable(cpp_vector cpp_vector.cpp)
add_executable(cpp_pass_copy_vs_reference cpp_pass_copy_vs_reference.cpp)
add_executable(cpp_constructor cpp_construtors.cpp)
add_executable(m1_w1_d1 src/m1_w1_d1_helloworld.cpp)
add_executable(m1_w1_d2 src/m1_w1_d2_datatype_variables_operators)
add_executable(m1w1d4 src/m1w1d4_inlinefunc.cpp)
add_executable(m1w2d3 src/m1w2d3_polymorphism.cpp)
add_executable(m1w2d4 src/m1w2d4_friendfunc.cpp)
add_executable(m1w2d42 src/m1w2d4_operator_overload.cpp)
add_executable(m1w3d1 src/m1w3d1_array.cpp)
add_executable(m1w3d2 src/m1w3d2_dynamic_memory.cpp)
add_executable(m1w3d3 src/m1w3d3_reference_vs_pointer.cpp)
add_executable(m1w3d4 src/m1w3d4_smart_pointers.cpp)
add_executable(m1w4d1 src/m1w4d1_stl.cpp)
add_executable(m2w1d1 src/m2w1d1_template.cpp)
add_executable(m2w1d2 src/m2w1d2_excpt.cpp)


target_link_libraries(m1w3d3 cpp_lib)
target_link_libraries(m1w3d4 cpp_lib)
target_link_libraries(m1w4d1 cpp_lib)
target_link_libraries(m2w1d1 cpp_lib)
find_package(Threads REQUIRED)
target_link_libraries(m2w1d2 PRIVATE Threads::Threads cpp_lib)