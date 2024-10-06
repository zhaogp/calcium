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

    int a, b, c;
    cin >> a >> b >> c;
    func01(a, b, c);

    return 0;
}
