// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
vector<vector<int>> dp;
int solve(int n, int target, int k)
{
    if (n == 0 && target == 0)
        return dp[n][target] = 1;
    if (n < 0)
        return 0;
    if (dp[n][target] != -1)
        return dp[n][target];
    dp[n][target] = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i <= target)
        {
            dp[n][target] += (solve(n - 1, target - i, k)) % mod;
            dp[n][target] %= mod;
        }
    }
    return dp[n][target] % mod;
}
int numRollsToTarget(int n, int k, int target)
{
    dp.resize(n + 1, vector<int>(target + 1, -1));

    return solve(n, target, k);
}

int numRollsToTarget(int d, int f, int target)
{
    int m = 1000000007;
    vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            for (int k = 1; k <= f; k++)
            {
                if (k <= j)
                    dp[i][j] = ((dp[i][j] % m) + (dp[i - 1][j - k] % m)) % m;
            }
        }
    }
    return dp[d][target];
}