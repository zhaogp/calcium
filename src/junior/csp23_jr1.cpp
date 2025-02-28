/**
 * 23 年 CSP-J1，阅读题
 */
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>

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

// 阅读程序，第二小题
int longest_common_subsequence(string str01, string str02){
    /**
     * 动态规划求两个字符串的最长子序列(不是子串，不要求连续)
     */
    cout << "输入的字符串01是：" << str01 << endl;
    cout << "输入的字符串02是：" << str02 << endl;
    int m = str01.size();
    int n = str02.size();

    vector<vector<int>> v(m+1, vector<int>(n+1, 0)); 
    for(int i=1; i<=m; i++){
        for(int j=1; j <= n; j++) {
            if(str01[i-1] == str02[j-1]) {
                v[i][j] = v[i-1][j-1] + 1;
            } else {
                v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
    }

    cout << "构造的动态规划数组：" << endl;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout << setw(5) << v[i][j];
        }
        cout << endl;
    }

    int i = m, j = n;
    string lcs;
    while(i > 0 && j > 0) {
        if(str01[i-1] == str02[j-1]) {
            // cout << str01[i-1];
            lcs = str01[i-1] + lcs; // 从后往前加, 所以下面不需要逆序了
            i--;
            j--;
        } else if(v[i-1][j] > v[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    // reverse(lcs.begin(), lcs.end());
    cout << "最长子序列是：" << lcs << endl;
    cout << "长度：" << v[m][n] << endl;

    return v[m][n];
}

int longest_common_substring(string str01, string str02){
    /**
     * 动态规划求两个字符串的最长公共子串(要求连续)
     */
    cout << "输入的字符串01是：" << str01 << endl;
    cout << "输入的字符串02是：" << str02 << endl;
    int m = str01.size();
    int n = str02.size();

    // 处理空字符串情况
    if (m == 0 || n == 0) {
        cout << "最长公共子串：\"\"" << endl;
        cout << "长度：0" << endl;
        return 0;
    }

    vector<vector<int>> v(m+1, vector<int>(n+1, 0)); 
    int max_len = 0;
    int end_index = 0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j <= n; j++) {
            if(str01[i-1] == str02[j-1]) {
                v[i][j] = v[i-1][j-1] + 1;
                if (v[i][j] > max_len) {
                    max_len = v[i][j];
                    end_index = i;
                }
            } else {
                v[i][j] = 0;
            }
        }
    }

    // 输出动态规划数组
    cout << "构造的动态规划数组：" << endl;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout << setw(5) << v[i][j];
        }
        cout << endl;
    }

    cout << "最长公共子串：" << str01.substr(end_index - max_len, max_len) << endl;
    cout << "长度：" << max_len << endl;

    return max_len;
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

    int temp = longest_common_subsequence(x + x, y); 

    return temp == y.size();
}

// 3.1 二分查找等差数列中缺失的一个数
int bs_find_miss(vector<int>& vp) {
    /**
     * 二分法查找
     * 查找等差数列中缺失的那一个
     */
    cout << "要查找的等差数列是：";
    for (int i : vp){
        cout << i << " ";
    }
    cout << endl;

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
    cout << "缺少的数是：" << rv << endl;

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
                dp[i][j] = j;  // 第一行就是 0 1 2 ...
            } else if (j == 0) {
                dp[i][j] = i;  // 第一列就是 0 1 2 ...
            } else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  // 对应位置的字符相同，回对角线的上一个位置
            } else {
                dp[i][j] = three_min(
                    dp[i-1][j] + 1,  // 从左往右是新增操作，新增 str2 中独有的字符
                    dp[i][j-1] +1,  // 从上往下是删除操作，删除 str1 中多余的字符
                    dp[i-1][j-1] + 1  // 替换操作，从左上角往右下角加一
                );
            }
        }
    }
    cout << "最终输出的动态规划数组：" << endl;
    for (int i=0 ; i<=m; i++){
        for (int j=0; j<=n; j++){
            cout << setw(5) << dp[i][j];
        }
        cout << endl;
    }
    int rv = dp[m][n];
    cout << "最少操作次数是：" << rv << endl;

    return rv;
}
       