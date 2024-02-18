// https://leetcode.com/problems/apply-operations-to-make-two-strings-equal/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(int i, int j, vector<int> &indexes, int x)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    ans = min(ans, min(x, indexes[i + 1] - indexes[i]) + solve(i + 2, j, indexes, x));
    ans = min(ans, min(x, indexes[j] - indexes[i]) + solve(i + 1, j - 1, indexes, x));
    ans = min(ans, min(x, indexes[j] - indexes[j - 1]) + solve(i, j - 2, indexes, x));

    return dp[i][j] = ans;
}
int minOperations(string s1, string s2, int x)
{
    int n = s1.length();

    vector<int> indexes;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            indexes.push_back(i);
        }
    }

    int m = indexes.size();
    if (m == 0)
        return 0;
    if (m & 1)
        return -1;
    dp.resize(m, vector<int>(m, -1));

    return solve(0, m - 1, indexes, x);
}