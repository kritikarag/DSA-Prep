// https://leetcode.com/problems/distinct-subsequences/

#include <bits/stdc++.h>
using namespace std;

//MEMORIZATION
int solve(int i, int j, vector<vector<int>> &dp, string s, string t)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int take = 0;
    if (s[i] == t[j])
    {
        take = solve(i - 1, j - 1, dp, s, t);
    }
    int not_take = solve(i - 1, j, dp, s, t);

    return dp[i][j] = take + not_take;
}
int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, dp, s, t);
}

//TABULATION

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int take = 0;
            if (s[i - 1] == t[j - 1])
            {
                take = dp[i - 1][j - 1];
            }
            int not_take = dp[i - 1][j];
            dp[i][j] = (take + not_take) % mod;
        }
    }

    return dp[n][m];
}