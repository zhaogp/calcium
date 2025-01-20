#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
void hanoi(int n, string from, string to, string aux, int& move_count) {
    if (n == 1) {
        cout << "1#盘子：" << from << " -> " << to << endl;
        move_count++;
        return;
    }

    hanoi(n-1, from, aux, to, move_count);
    cout << n << "#盘子 " << from << " -> " << to << endl;
    move_count++;
    hanoi(n-1, aux, to, from, move_count);
}

int hanoi_wrapper(int n, string from, string to, string aux) {
    int move_count = 0;
    hanoi(n, from, to, aux, move_count);
    cout << "总共移动次数: " << move_count << endl;
    
    return move_count;
}
