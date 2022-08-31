set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 3.2.0)
project(MyUtils VERSION 0.0.1 LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(memory)
add_subdirectory(TinyXML2)
add_subdirectory(TinyXML2_6_2)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)