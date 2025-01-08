#include <gtest/gtest.h>
#include "csp23_jr1.h"
#include<string>

using namespace std;

TEST(CspTest, Csp23jr1Test) {
    string s1 = "kitten";
    string s2 = "sitting";
    int dep = dp_edit_distance(s1, s2);
    EXPECT_EQ(dep, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
