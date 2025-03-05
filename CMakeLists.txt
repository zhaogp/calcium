cmake_minimum_required(VERSION 3.30)
project(calcium VERSION 0.1)

add_subdirectory(src)
add_subdirectory(tests)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)