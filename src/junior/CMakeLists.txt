# 定义源文件和库
set(SOURCE_FILES
    binary_tree.cpp
    static_const.cpp
    csp23_jr1.cpp
)
add_library(junior STATIC ${SOURCE_FILES})
target_include_directories(junior PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    C:/Boost/include/boost-1_86
)
target_link_libraries(junior PUBLIC ${Boost_LIBRARIES})
