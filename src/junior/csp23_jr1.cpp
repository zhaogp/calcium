/**
 * 23 年 CSP-J1，阅读题
 */
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include "csp23_jr1.h"

using namespace std;

// 2.1 海伦公式
double heron_formula(double a, double b, double c) {
    /**
     * 三角形面积：海伦公式
     */
    cout.flags(ios::fixed);
    cout.precision(4);
    cout << "求三角形面积，三边长分别是：" << a << " " << b << " " << c << endl;
    double s = (a + b + c) / 2;
    double square = sqrt(s * (s-a) * (s-b) * (s-c));
    cout << "求出的面积是：" << square << endl;
    
    // 对 square 取4位小数
    double factor = pow(10, 4);
    square = round(square * factor) / factor;

    return square;
}

// 阅读程序，第二小题
int longest_common_subsequence(string str01, string str02){
    /**
     * 动态规划求两个字符串的最长子序列(不是子串，不要求连续)
     * 
     * 1. 定义状态
     *      dp[i][j] 表示 str01 的前 i 个字符和 str02 的前 j 个字符的最长子序列
     * 2. 状态转移方程
     *      dp[i][j] = dp[i-1][j-1] + 1              相等，对角线加一
     *      dp[i][j] = max(dp[i-1][j], dp[i][j-1])   不等，邻位最大值
     * 3. 初始化
     *      dp[0][j] = 0, dp[i][0] = 0，表示其一为空字符串时，公共子串长度为 0
     * 4. 结果
     *      dp[m][n]，回溯找到最长子序列
     */
    cout << "输入的字符串01是：" << str01 << endl;
    cout << "输入的字符串02是：" << str02 << endl;
    int m = str01.size();
    int n = str02.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); 
    for(int i=1; i<=m; i++){
        for(int j=1; j <= n; j++) {
            if(str01[i-1] == str02[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << "构造的动态规划数组：" << endl;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout << setw(5) << dp[i][j];
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
        } else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    // reverse(lcs.begin(), lcs.end());
    cout << "最长子序列是：" << lcs << endl;
    cout << "长度：" << dp[m][n] << endl;

    return dp[m][n];
}

int longest_common_substring(string str01, string str02){
    /**
     * 动态规划求两个字符串的最长公共子串(要求连续)
     * 
     * 1. 定义状态
     *     dp[i][j] 表示 str01 的前 i 个字符和 str02 的前 j 个字符的最长公共子串
     * 2. 状态转移方程
     *    dp[i][j] = dp[i-1][j-1] + 1              相等，对角线加一
     *    dp[i][j] = 0                             不等，清零
     * 3. 初始化
     *   dp[0][j] = 0, dp[i][0] = 0         表示其一为空字符串时，公共子串长度为 0
     * 4. 结果
     *   max_len = max(dp[i][j])                        取二维数组中最大值
     *   end_index = i                                  最长子串的结束位置
     *   str01.substr(end_index - max_len, max_len)     截取最长子串
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

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); 
    int max_len = 0;
    int end_index = 0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j <= n; j++) {
            if(str01[i-1] == str02[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                    end_index = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // 输出动态规划数组
    cout << "构造的动态规划数组：" << endl;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout << setw(5) << dp[i][j];
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

// 3.1 二分查找
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
        // 如果相等，说明左半边是连续的，缺失的数在右半边
        if (vp[mid] == vp[0] + mid) {  
            left = mid + 1;
        // 缺失的数在右半边
        } else {  
            right = mid;
        }
    }
    int rv = vp[0] + left;
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
    /**
     * 动态规划求两个字符串的编辑距离
     * 1. 定义状态
     *     dp[i][j] 表示 str1 的前 i 个字符和 str2 的前 j 个字符的编辑距禽
     * 2. 状态转移方程
     *    dp[i][j] = dp[i-1][j-1]                                       相等，对角线平移
     *    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1      不等，最小周围数加一
     * 3. 初始化
     *   dp[0][j] = j, dp[i][0] = i         表示其一为空字符串时，编辑距离为另一个字符串的长度
     * 4. 结果
     *  dp[m][n]             最终的编辑距离
     */
    cout << "字符串一：" << str1 << endl;
    cout << "字符串二：" << str2 << endl;

    int m = str1.length();
    int n = str2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++) {
            // str01 为空，编辑距离就是 str02 的长度，全部是新增操作
            if (i == 0) {
                dp[i][j] = j;  
            // str02 为空，编辑距离就是 str01 的长度，全部是删除操作
            } else if (j == 0) {
                dp[i][j] = i;  
            // 相同，对角线平移
            } else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];  
            // 不同，取周围最小值加一，也就是从插入、删除、替换中选一个操作
            } else {
                dp[i][j] = three_min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
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
    cout << "最少操作次数是：" << dp[m][n] << endl;

    return dp[m][n];
}

int dp_knapsack(int W, vector<int> wt, vector<int> val) {
    /**
     * 动态规划求背包问题

     * 1. 定义状态
     *   dp[i][j] 表示前 i 个物品，背包容量为 j 时的最大价值

     * 2. 状态转移方程
     *   wt[i] > w  -->  dp[i][j] = dp[i-1][j]                                      装不下 -> 上值下移
     *   wt[i] <= w  -->  dp[i][j] = max(dp[i-1][j], dp[i-1][j-wt[i]] + val[i])     装得下 -> 上上取大    

     * 3. 初始化
     *   dp[0][j] = 0     第一行，没有物品时价值为 0
     *   dp[i][0] = 0     第一列，背包容量为 0 时价值也为 0

     * 4. 结果
     *     dp[n][W]
     * 
     *  W 是背包容量，wt 是物品重量列表，val 是物品价值列表
     */
    int n = wt.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            // 容量不够，不放入第 i 个物品
            if (w < wt[i-1]) {
                dp[i][w] = dp[i-1][w];
            // 容量够，可以放入第 i 个物品，但是要比较放入和不放入的价值
            } else {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]] + val[i-1]);
            }
        }
    }

    cout << "重量列表：";
    for (int i : wt) {
        cout << i << " ";
    }
    cout << endl;
    cout << "价值列表：";
    for (int i : val) {
        cout << i << " ";
    }
    cout << endl;
    cout << "背包容量：" << W << endl;
    cout << "动态规划数组：" << endl;
    for (int i=0 ; i<=n; i++){
        for (int j=0; j<=W; j++){
            cout << setw(5) << dp[i][j];
        }
        cout << endl;
    }

    // 回溯放入的物品
    int i = n, w = W;
    vector<int> items;
    while (i > 0 && w > 0) {
        if (dp[i][w] == dp[i-1][w]) {
            i--;
        } else {
            items.push_back(i);
            w -= wt[i-1];
            i--;
        }
    }
    reverse(items.begin(), items.end());

    cout << "放入的物品是：";
    for (int i : items) {
        cout << i << " ";
    }
    cout << endl;

    return dp[n][W];
}

int dp_coin_change(vector<int> coins, int amount) {
    /**
     * 动态规划求硬币找零问题

     * 1. 定义状态
     *   dp[i] 表示凑齐 i 元的最少硬币数

     * 2. 状态转移方程
     *   dp[i] = min(dp[i], dp[i - coin] + 1)

     * 3. 初始化
     *   dp[0] = 0，dp[i] = amount + 1，表示最多需要 amount 枚硬币

     * 4. 结果
     *   dp[amount]
     */

    // 初始化一个 amount+1 大小的数组，全部初始化为 amount+1
    vector<int> dp(amount+1, amount+1);
    // 第一个元素为 0
    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {
        for (const int coin: coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // 输出动态规划数组
    cout << "构造的动态规划数组：" << endl;
    for(int i=0; i<=amount; i++){
        cout << setw(5) << dp[i];
    }
    cout << endl;

    // 输出全部可选硬币
    cout << "可选的硬币是：";
    for (int i : coins) {
        cout << i << " ";
    }
    cout << endl;

    // 输出选择的硬币
    int i = amount;
    vector<int> selected_coins;
    while (i > 0) {
        for (const int coin: coins) {
            if (i >= coin && dp[i] == dp[i - coin] + 1) {
                selected_coins.push_back(coin);
                i -= coin;
                break;
            }
        }
    }
    cout << "选择的硬币是：";
    for (int i : selected_coins) {
        cout << i << " ";
    }
    cout << endl;

    int rv = dp[amount] > amount ? -1 : dp[amount];
    cout << "凑齐 " << amount << " 元，" << "最少需要 " << dp[amount] << " 枚硬币" << endl;

    return dp[amount];
}
