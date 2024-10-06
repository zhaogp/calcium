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

    int n;
    cout << "请输入数组长度：";
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int mn = ap_find_miss(nums);
    if (mn == nums[n-1]){
        cout << "是连续数组" << endl;
    } else {
        cout << "缺失的元素是：" << mn << endl;
    }

    return 0;
}
