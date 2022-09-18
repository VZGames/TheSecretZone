set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 3.2.0)
project(TheSecretZone VERSION 0.1.0 DESCRIPTION "TheSecretZone By Be Studio" LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message("Root: ${CMAKE_SOURCE_DIR}")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(utils)
add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_14)
