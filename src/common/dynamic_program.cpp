#include "dynamic_program.h"


// 经典分硬币
int dp_minium_coins(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;

    for(int i = 1; i <= amount; i++) {
        for (const int& coin: coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    int rv = dp[amount] > amount ? -1 : dp[amount];
    cout << "凑齐 " << amount << " 元，" << "最少需要 " << rv << " 张" << endl;

    return rv;
}

// 汉诺塔
void hanoi(int n, string from, string to, string aux) {
    if (n == 1) {
        cout << "1#盘子：" << from << " -> " << to << endl;
        return;
    }

    hanoi(n-1, from, aux, to);
    cout << n << "#盘子 " << from << " -> " << to << endl;
    hanoi(n-1, aux, to, from);
}