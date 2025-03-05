cmake_minimum_required(VERSION 3.30)
project(calcium VERSION 0.1)

add_subdirectory(src)
add_subdirectory(tests)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")  # 确保调试信息完整且无优化