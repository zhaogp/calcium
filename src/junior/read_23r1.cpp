/**
 * 23 年 CSP-J1，阅读题
 */
#include<iostream>
#include<cmath>
#include "read_23r1.h"

using namespace std;


double aa_heron_formula(double a, double b, double c) {
    /**
     * 三角形面积：海伦公式
     */
    cout << "求三角形面积，三边长分别是：" << a << " " << b << " " << c << endl;
    double s = (a + b + c) / 2;
    double square = sqrt(s * (s-a) * (s-b) * (s-c));
    cout << "求出的面积是：" << square << endl;

    return square;
}

int ml_common_substring(string x, string y){
    /**
     * 求两个字符串的最长公共字串长度，用二维数组实现
     */
    cout << "输入的字符串是：" << x << " 和" << y << endl;
    int m = x.size();
    int n = y.size();
    vector<vector<int>> v(m+1,vector<int>(n+1, 0)); 
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

int af_square_sum(int n) {
    /**
     * 求 n 的所有因子的平方和
     */
    cout << "求 " << n << " 的所有因子的和" << endl;

    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {  // 是平方根时，只计算一次
                sum += i * i;
            } else {
                sum += i * i + (n / i) * (n / i);
            }
        }
    }
    cout << "结果是：" << sum << endl; 

    return sum;
}


bool func03(string x, string y) {
    if(x.size() != y.size()) {
        return false;
    }

    int temp = ml_common_substring(x + x, y); 

    return temp == y.size();
}

int ap_find_miss(vector<int>& vp) {
    /**
     * 二分法查找
     * 查找等差数列中缺失的那一个
     */
    int left = 0, right = vp.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (vp[mid] == mid + vp[0]) {  // 如果相等，说明被找的数在右半边
            left = mid + 1;
        } else {  // 否则被查找的数在左半边
            right = mid;
        }
    }
    int rv = vp[0] + left;
    cout << "缺失的数组元素是：" << rv << endl;

    return rv;

}

int demo(int dn, int n) {
    int rv = dn / n;
    cout << dn << " 除以 " << n << " 的整数值为：" << rv << endl;

    return rv;
}