# 包含Google Test
find_package(GTest REQUIRED)

include_directories(${GTEST_ROOT}/include)

# 添加测试目标
add_executable(test_calcium test_csp23_jr1.cpp)
target_link_libraries(test_calcium common junior GTest::GTest GTest::Main pthread)

enable_testing()

# 添加测试
add_test(NAME Csp23Test COMMAND test_calcium)
add_test(NAME CommonTest COMMAND test_calcium)
