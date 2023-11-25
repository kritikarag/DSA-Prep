// https://leetcode.com/problems/minimum-number-of-coins-for-fruits/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(int index, vector<int> &prices, int rem)
{
    if (index >= prices.size())
        return 0;
    if (dp[index][rem] != -1)
        return dp[index][rem];
    int take = INT_MAX;
    if (rem)
    {
        take = solve(index + 1, prices, rem - 1);
    }
    int not_take = prices[index] + solve(index + 1, prices, index + 1);

    return dp[index][rem] = min(take, not_take);
}
int minimumCoins(vector<int> &prices)
{
    int n = prices.size();
    dp.resize(n, vector<int>(n + 1, -1));

    return solve(0, prices, 0);
}