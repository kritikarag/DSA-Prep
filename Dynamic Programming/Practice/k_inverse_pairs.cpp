// https://leetcode.com/problems/k-inverse-pairs-array/

#include<bits/stdc++.h>
using namespace std;

// Memoization (n*n*k)
int mod = 1e9 + 7;
vector<vector<int>> dp;
int solve(int n, int k)
{
    if (k < 0 || n < 0)
        return 0;
    if (k == 0)
        return dp[n][k] = 1;
    if (dp[n][k] != -1)
        return dp[n][k];

    int ans = 0;
    for (int i = 0; i < min(n, k + 1); i++)
    {
        ans += solve(n - 1, k - i);
        ans %= mod;
    }
    dp[n][k] = ans % mod;
    return dp[n][k] % mod;
}
int kInversePairs(int n, int k)
{
    dp.resize(n + 1, vector<int>(k + 1, -1));
    return solve(n, k);
}

// Tabulation  (n*n*k)

int kInversePairs(int n, int k)
{
    dp.resize(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int x = 0; x < min(i, j + 1); x++)
            {
                dp[i][j] += (dp[i - 1][j - x]) % mod;
                dp[i][j] %= mod;
            }
        }
    }

    return dp[n][k] % mod;
    // return solve(n,k);
}