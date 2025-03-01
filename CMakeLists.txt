# 1. 基础配置
cmake_minimum_required(VERSION 3.30)
project(calcium VERSION 0.1)

# 2. C++ 版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 3. 基本目录变量定义
set(CALCIUM_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(CALCIUM_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CALCIUM_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

# 4. 全部头文件路径
if(APPLE)
    set(BOOST_ROOT "/usr/local/Cellar/boost/1.86.0/include")
    set(GTEST_ROOT "/usr/local/Cellar/googletest/1.15.2/include")
endif()
if(WIN32) 
    set(BOOST_ROOT "C:/Program Files/boost_1_86_0")
    set(GTEST_ROOT "C:/Users/guopi/googletest-distribution")
endif()

# 三方库
include_directories(${BOOST_ROOT})
include_directories(${GTEST_ROOT})

# 本项目库
include_directories(${CALCIUM_INSTALL_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/common)  # 公共模块
include_directories(${PROJECT_SOURCE_DIR}/src/junior)  # CSP-J

# 5. 子模块
add_subdirectory(src)
add_subdirectory(tests)

