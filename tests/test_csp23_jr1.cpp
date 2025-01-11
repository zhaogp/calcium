#include <gtest/gtest.h>
#include "csp23_jr1.h"
#include<string>

using namespace std;

TEST(CspTest, Csp23jr1Test01) {
    string s1 = "kitten";
    string s2 = "sitting";
    int dep = dp_edit_distance(s1, s2);
    EXPECT_EQ(dep, 3);
}

TEST(CspTest, Csp23jr1Test02){
    string s1 = "horse";
    string s2 = "ros";
    int dep = dp_edit_distance(s1, s2);
    EXPECT_EQ(dep, 4);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
