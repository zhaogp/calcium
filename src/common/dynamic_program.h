/**
 * 动态规划，硬币问题
 */
#include<iostream>
#include<vector>

using namespace std;


int dp_minium_coins(vector<int>& coins, int amount);
int hanoi_wrapper(int n, string from, string to, string aux);
