/*
    主入口文件
*/
#include<iostream>
#include<vector>

#include "binary_tree.h"
#include "my_sqrt.h"
#include "csp23_jr1.h"
#include "dynamic_program.h"

using namespace std;


int main() {
    string s1 = "kitten";
    string s2 = "sitting";
    int dep = dp_edit_distance(s1, s2);

    return 0;
}
