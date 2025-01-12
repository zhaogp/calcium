#include <gtest/gtest.h>
#include "csp23_jr1.h"
#include<string>

using namespace std;

TEST(Csp23jr1Test, BS3101) {
    vector<int> v = {5, 6, 7, 9};
    int miss = bs_find_miss(v);
    EXPECT_EQ(miss, 8);
}

TEST(Csp23jr1Test, Dp3201) {
    string s1 = "kitten";
    string s2 = "sitting";
    int dep = dp_edit_distance(s1, s2);
    EXPECT_EQ(dep, 3);
}

TEST(Csp23jr1Test, Dp3202){
    string s1 = "horse";
    string s2 = "ros";
    int dep = dp_edit_distance(s1, s2);
    EXPECT_EQ(dep, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
