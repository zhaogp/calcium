cmake_minimum_required(VERSION 3.30)
project(junior C CXX)

set(SOURCE_FILES
    binary_tree.h
    binary_tree.cpp
    static_const.h
    static_const.cpp
)

add_library(junior SHARED STATIC ${SOURCE_FILES})

install(TARGETS junior DESTINATION ${CALCIUM_INSTALL_LIB_DIR})
install(FILES binary_tree.h static_const.h DESTINATION ${CALCIUM_INSTALL_INCLUDE_DIR})
