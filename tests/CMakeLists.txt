set(GTEST_ROOT $ENV{GTEST_HOME})
find_package(GTest REQUIRED)

add_executable(test_calcium test_csp23_jr1.cpp)
target_include_directories(test_calcium PRIVATE $ENV{GTEST_HOME}/include)
target_link_libraries(test_calcium PRIVATE 
    common 
    junior 
    GTest::GTest 
    GTest::Main
)
install(TARGETS test_calcium DESTINATION ${CMAKE_SOURCE_DIR}/bin)

enable_testing()
add_test(NAME Csp23Test COMMAND test_calcium)
add_test(NAME CommonTest COMMAND test_calcium)

