set(GTEST_ROOT C:/gtest)
find_package(GTest REQUIRED)

add_executable(test_calcium test_csp23_jr1.cpp)
target_include_directories(test_calcium PRIVATE C:/gtest/include)
target_link_libraries(test_calcium PRIVATE 
    common 
    junior 
    GTest::GTest 
    GTest::Main
)

enable_testing()
add_test(NAME Csp23Test COMMAND test_calcium)
add_test(NAME CommonTest COMMAND test_calcium)
