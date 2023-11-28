// https://leetcode.com/problems/knight-dialer/description/
#include<bits/stdc++.h>
using namespace std;

//Memoization :

vector<vector<int>>pos = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
int mod = 1e9 + 7;
vector<vector<long long>> dp;
int pattern(int len, int index)
{
    if (dp[len][index] != -1)
        return dp[len][index] % mod;
    if (len == 1)
        return dp[len][index] = 1;
    dp[len][index] = 0;
    for (int move : pos[index])
    {
        dp[len][index] += pattern(len - 1, move);
        dp[len][index] %= mod;
    }
    return dp[len][index] % mod;
}
int knightDialer(int n)
{
    dp.resize(n + 1, vector<long long>(10, -1));
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        res += (pattern(n, i)) % mod;
        res %= mod;
    }
    return res;
}

//Tabulation:

vector<vector<int>> pos = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
int mod = 1e9 + 7;
int knightDialer(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(10, 0));
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        dp[1][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k : pos[j])
            {
                dp[i + 1][k] += (dp[i][j]) % mod;
                dp[i + 1][k] %= mod;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        res += dp[n][i];
        res %= mod;
    }
    return res;
}


// Space Optimized

