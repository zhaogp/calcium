/*
    主入口文件
*/
#include <iostream>
#include "binary_tree.h"
#include "my_sqrt.h"
#include "read_23r1.h"

using namespace std;


int main() {
    cout.flags(ios::fixed);
    cout.precision(4);

    vector<int> nums = {4, 5, 6, 8};

    int mn = ap_find_miss(nums);  // 返回值是缺失元素或最后一个元素
    if (mn == nums[nums.size() - 1]){
        cout << "是连续数组" << endl;
    } else {
        cout << "缺失的元素是：" << mn << endl;
    }

    return 0;
}
