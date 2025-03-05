set(SOURCE_FILES
    my_sqrt.cpp
    dynamic_program.cpp
)

add_library(common SHARED STATIC ${SOURCE_FILES})
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})