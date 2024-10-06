/**
 * 23 年 CSP-J1，阅读题
 */
#include<iostream>
#include<cmath>
#include "read_23r1.h"

using namespace std;


// 三角形面积：海伦公式
double func01(double a, double b, double c) {
    cout << "求三角形面积，三边长分别是：" << a << " " << b << " " << c << endl;
    double s = (a + b + c) / 2;
    double square = sqrt(s * (s-a) * (s-b) * (s-c));
    cout << "求出的面积是：" << square << endl;

    return square;
}

// 二维向量处理字符串
int func02(string x, string y){
    cout << "输入的字符串是：" << x << " 和" << y << endl;
    int m = x.size();
    int n = y.size();
    vector<vector<int>> v(m+1,vector<int>(n+1,0)); 
    for(int i=1; i<=m; i++){
        for(int j = 1; j <= n; j++) {
            if(x[i-1] == y[j-1]) {
                v[i][j] = v[i-1][j-1] + 1;
            } else {
                v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
    }
    int rv = v[m][n];
    cout << "返回值是：" << rv << endl;

    return rv;
}

// 求平方
int solve01(int n) {
    return n * n;
}

// 求 XX 和
int solve02(int n) {
    int sum = 0;
    for (int i=1; i<sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                sum += i * i;
            } else {
                sum += i * i + (n / i) * (n / i);
            }
        }
    }

    return sum;
}
