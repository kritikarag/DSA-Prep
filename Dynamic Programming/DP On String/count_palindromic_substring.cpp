#include<bits/stdc++.h>
using namespace std;

// MEMOIZATION
string str;
vector<vector<int>> dp;
int solve(int l, int r)
{
    if (l > r)
        return 1;
    if (l == r)
        return 1;
    if (dp[l][r] != -1)
        return dp[l][r];
    if (str[l] != str[r])
        return dp[l][r] = 0;
    if (solve(l + 1, r - 1))
        return dp[l][r] = 1;

    return dp[l][r] = 0;
}
int countSubstrings(string s)
{
    int n = s.size(), res = 0;
    str = s;
    dp = vector<vector<int>>(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            res += solve(i, j);
        }
    }

    
    return res;
}


// TABULATION