/**
 * 23 年 CSP-J1，阅读题
 */
#include<iostream>
#include<vector>
#include<cmath>
#include "csp23_jr1.h"

using namespace std;


// 2.1 海伦公式
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

// 2.2 动态规划求两个字符串的最长子串
int dp_common_substring(string x, string y){
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

// 2.3 求整数 n 的所有因子的平方和
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

    int temp = dp_common_substring(x + x, y); 

    return temp == y.size();
}

// 3.1 二分查找等差数列中缺失的一个数
int bs_find_miss(vector<int>& vp) {
    /**
     * 二分法查找
     * 查找等差数列中缺失的那一个
     */
    int left = 0, right = vp.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (vp[mid] == mid + vp[0]) {  // 如果相等，说明左半边是连续的，缺失的数在右半边
            left = mid + 1;  // mid 计算过了，左指针移到下一位
        } else {  // 否则被查找的数在左半边，包括 mid，所以右指针移到 mid 位置
            right = mid;
        }
    }
    int rv = vp[0] + left;  // 如果是连续数组，left 指向最后一个元素，rv 就是最后一个元素

    return rv;

}

int demo(int dn, int n) {
    int rv = dn / n;
    cout << dn << " 除以 " << n << " 的整数值为：" << rv << endl;

    return rv;
}

// 3.2 动态规划编辑距离
int three_min(int x, int y, int z){
    return min(min(x, y), z);
}

int dp_edit_distance(string str1, string str2) {
    cout << "字符串一：" << str1 << endl;
    cout << "字符串二：" << str2 << endl;

    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;  // 将空字符串转换为 str2 的前 j 个字符所需要的操作数
            } else if (j == 0) {
                dp[i][j] = i;  // 将 str1 的前 i 个字符串转换为空字符串所需要的操作数
            } else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  // 字符相同，不需要操作
            } else {
                dp[i][j] = three_min(
                    dp[i-1][j] + 1,  // 删除操作
                    dp[i][j-1] +1,  // 插入操作
                    dp[i-1][j-1] + 1  // 替换操作
                );
            }
        }
    }
    cout << "最终输出的动态规划数组：" << dp[m][n] << endl;

    return dp[m][n];
}
