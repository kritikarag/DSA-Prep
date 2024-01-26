// https://leetcode.com/problems/out-of-boundary-paths/description/

#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> dp;
int mod = 1e9 + 7;
int solve(int i, int j, int m, int n, int left)
{
    if (i < 0 || j < 0 || i == m || j == n)
        return 1;
    if (left == 0)
        return 0;

    if (dp[i][j][left] != -1)
        return dp[i][j][left];
    int ans = 0;
    ans += solve(i + 1, j, m, n, left - 1) % mod;
    ans %= mod;
    ans += solve(i, j + 1, m, n, left - 1) % mod;
    ans %= mod;
    ans += solve(i - 1, j, m, n, left - 1) % mod;
    ans %= mod;
    ans += solve(i, j - 1, m, n, left - 1) % mod;
    ans %= mod;

    return dp[i][j][left] = ans % mod;
}
int findPaths(int m, int n, int mm, int sr, int sc)
{
    dp.assign(m, vector<vector<int>>(n, vector<int>(mm + 1, -1)));
    return solve(sr, sc, m, n, mm);
}