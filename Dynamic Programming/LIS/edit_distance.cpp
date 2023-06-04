// https://leetcode.com/problems/edit-distance/

#include<bits/stdc++.h>
using namespace std;
int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i <= 0)
        return j;
    if (j <= 0)
        return i;

    if (dp[i][j] != -1)
        return dp[i][j];

    int take = 0;
    if (s1[i - 1] == s2[j - 1])
    {
        return dp[i][j] = solve(i - 1, j - 1, s1, s2, dp);
    }

    int ins = solve(i, j - 1, s1, s2, dp);
    int del = solve(i - 1, j, s1, s2, dp);
    int upd = solve(i - 1, j - 1, s1, s2, dp);

    return dp[i][j] = 1 + min(ins, min(del, upd));
}
int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return solve(n, m, word1, word2, dp);
}


//TABULATION

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int ins = dp[i][j - 1];
                int del = dp[i - 1][j];
                int upd = dp[i - 1][j - 1];

                dp[i][j] = 1 + min(ins, min(del, upd));
            }
        }
    }
    return dp[n][m];
}
