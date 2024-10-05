#include <iostream>
#include<cmath>

#include "my_sqrt.h"

using namespace std;


double my_sqrt(double x) {
    cout << "自定义的平方根运算方法" << endl;
    double rv = sqrt(x);
    cout << x << " 的平方根是：" << rv << endl;
    
    return rv;
}
