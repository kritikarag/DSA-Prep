// https://leetcode.com/problems/wildcard-matching/
#include<bits/stdc++.h>
using namespace std;

//MEMORIZATION

bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    if (i <= 0 && j <= 0)
        return dp[i][j] = true;
    if (i <= 0)
    {
        for (int k = j; k > 0; k--)
        {
            if (p[k - 1] != '*')
                return dp[i][j] = false;
        }
        return dp[i][j] = true;
    }
    if (j <= 0)
        return dp[i][j] = false;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
        return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
    else if (p[j - 1] == '*')
    {
        return dp[i][j] = solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp);
    }
    return dp[i][j] = false;
}
bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solve(n, m, s, p, dp);
}

//TABULATION

bool isMatch(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= m; i++)
    {
        if (p[i - 1] == '*')
            dp[0][i] = true;
        else
            break;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}