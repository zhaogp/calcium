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
    hanoi_wrapper(5, "原始柱子", "目标柱子", "中间柱子");

    return 0;
}
