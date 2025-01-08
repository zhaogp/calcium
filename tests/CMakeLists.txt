# 包含Google Test
find_package(GTest REQUIRED)
include_directories("C:/Users/guopi/googletest-distribution/include")

# 添加测试目标
add_executable(csp23_jr1 test_csp23_jr1.cpp)
target_link_libraries(csp23_jr1 junior GTest::GTest GTest::Main pthread)

enable_testing()

# 添加测试
add_test(NAME Csp23Test COMMAND csp23_jr1)
