#include <gtest/gtest.h>
#include <string>

#include "csp23_jr1.h"
#include "dynamic_program.h"

using namespace std;

TEST(Csp23Test, Af2201) {
    int n = longest_common_subsequence("kitten", "sitting");
    EXPECT_EQ(n, 4);
}

TEST(Csp23Test, Af2203) {
    int n = longest_common_substring("kitten", "sitting");
    EXPECT_EQ(n, 3);
}

TEST(Csp23Test, Dp3201) {
    int dep = dp_edit_distance("kitten", "sitting");
    EXPECT_EQ(dep, 3);
}

TEST(Csp23Test, Dp3202){
    string s1 = "horse";
    string s2 = "ros";
    int dep = dp_edit_distance(s1, s2);
    EXPECT_EQ(dep, 3);
}

TEST(Csp23Test, Dp3203) {
    int dep = dp_knapsack(10, {2, 3, 4, 5, 9}, {3, 4, 5, 8, 10});
    EXPECT_EQ(dep, 15);
}

TEST(Csp23Test, Af2301) {
    int n = 5;
    int afs = af_square_sum(n);
    EXPECT_EQ(afs, 26);
}

TEST(Csp23Test, Af2302) {
    int n = 12;
    int afs = af_square_sum(n);
    EXPECT_EQ(afs, 210);
}
              
TEST(Csp23Test, Bs3101) {
    vector<int> v = {5, 6, 7, 9};
    int miss = bs_find_miss(v);
    EXPECT_EQ(miss, 8);
}

TEST(Csp23Test, Bs3102) {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    int miss = bs_find_miss(v);
    EXPECT_EQ(miss, 9);
}

TEST(CommonTest, Hanoi) {
    int move_count = hanoi_wrapper(3, "原始柱子", "目标柱子", "中间柱子");
    EXPECT_EQ(move_count, 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
