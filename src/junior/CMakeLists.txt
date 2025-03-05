set(SOURCE_FILES
    binary_tree.cpp
    static_const.cpp
    csp23_jr1.cpp
)
add_library(junior STATIC ${SOURCE_FILES})
target_include_directories(junior PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    $ENV{BOOST_HOME}
)
# target_link_libraries(junior PUBLIC ${Boost_LIBRARIES})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)