# 1. 基础配置
cmake_minimum_required(VERSION 3.30)
project(Calcium VERSION 0.1)
file(GLOB MY_SOURCES 
    "src/main.cpp" 
    "src/junior/binary_tree.cpp" 
    "src/junior/binary_tree.h" 
    "src/math_functions/my_sqrt.cpp"
    "src/math_functions/my_sqrt.h"
    "src/math_functions/my_tools.cpp" 
    "src/math_functions/my_tools.h" 
)
add_executable("${PROJECT_NAME}" ${MY_SOURCES})

# 2. C++ 版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 3. 依赖库
add_library("${PROJECT_NAME}_lib" "lib/src/lib.cpp" "lib/include/lib/lib.hpp")
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC 
    "${CMAKE_SOURCE_DIR}/include"
)

# 4. 添加子目录
add_subdirectory(src/math_functions)
add_subdirectory(src/junior)

# 5. 链接库
target_link_libraries(
    "${PROJECT_NAME}"
    PUBLIC
    math_functions
    # PRIVATE
    # "${PROJECT_NAME}_lib"
#    external_library1
#    external_library2
)

# 两个 target （executable 和 librat）
# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
# target_compile_features(${PROJECT_NAME}_lib PRIVATE cxx_std_17)

# 三方库
# add_subdirectory("3rdparty/external_library1")
# add_subdirectory("3rdparty/external_library2")

# 添加头文件搜索路径
include_directories(include)

# 添加测试
enable_testing()
add_subdirectory(tests)
