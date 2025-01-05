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
    cout.flags(ios::fixed);
    cout.precision(4);

    vector<int> coins = {1, 4, 5};
    int amount = 13;  // 返回值是缺失元素或最后一个元素
    dp_minium_coins(coins, amount);

    return 0;
}
