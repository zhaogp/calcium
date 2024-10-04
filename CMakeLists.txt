cmake_minimum_required(VERSION 3.30)
project(Calcium VERSION 0.1)

# 构建选项
file(GLOB MY_SOURCES "src/*.cpp" "src/*.hpp" "src/*.h" "include/calcium/*.h" "include/calcium/*.hpp" "include/*.h" "include/*.hpp")
add_executable("${PROJECT_NAME}" ${MY_SOURCES})

# 依赖库
add_library("${PROJECT_NAME}_lib" "lib/src/lib.cpp" "lib/include/lib/lib.hpp")
target_include_directories("${PROJECT_NAME}_lib"
    PUBLIC 
    "lib/include"
    PRIVATE
    "lib/include/lib"
)

# 两个 target （executable 和 librat）
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_compile_features(${PROJECT_NAME}_lib PRIVATE cxx_std_17)

# 三方库
# add_subdirectory("3rdparty/external_library1")
# add_subdirectory("3rdparty/external_library2")

# 链接
target_link_libraries(
    "${PROJECT_NAME}"
    PRIVATE
    "${PROJECT_NAME}_lib"
#    external_library1
#    external_library2
)

# 添加头文件搜索路径
include_directories(include)

# 添加子目录
add_subdirectory(src)

# 添加测试
enable_testing()
add_subdirectory(tests)

