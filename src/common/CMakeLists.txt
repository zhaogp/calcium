cmake_minimum_required(VERSION 3.30)
project(common C CXX)

set(SOURCE_FILES
    my_sqrt.h
    my_sqrt.cpp

)

add_library(common SHARED STATIC ${SOURCE_FILES})

install(TARGETS common DESTINATION ${CALCIUM_INSTALL_LIB_DIR})
install(FILES my_sqrt.h DESTINATION ${CALCIUM_INSTALL_INCLUDE_DIR})
