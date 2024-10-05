# 1. 基础配置
cmake_minimum_required(VERSION 3.30)
project(Calcium VERSION 0.1)

# 2. C++ 版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 3. 基本目录变量定义
set(CALCIUM_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(CALCIUM_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CALCIUM_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

# 4. 全部头文件路径
set(BOOST_ROOT "/usr/local/Cellar/boost/1.86.0")
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CALCIUM_INSTALL_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/src/common)  # 公共模块
include_directories(${PROJECT_SOURCE_DIR}/src/junior)  # CSP-J

# 5. 子模块
add_subdirectory(src)
add_subdirectory(test)
