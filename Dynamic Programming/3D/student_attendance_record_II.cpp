// https://leetcode.com/problems/student-attendance-record-ii/description/
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
vector<vector<vector<long long>>> dp;
int s;
long long solve(int index, int late, int absent)
{
    if (index >= s)
        return 1;
    if (dp[index][absent][late] != -1)
        return dp[index][absent][late] % mod;
    long long a = 0, l = 0, p = 0;
    if (absent > 0)
    {
        a = solve(index + 1, 2, absent - 1) % mod;
        a %= mod;
    }
    if (late > 0)
    {
        l = solve(index + 1, late - 1, absent) % mod;
        l %= mod;
    }
    p = solve(index + 1, 2, absent) % mod;
    p %= mod;

    dp[index][absent][late] = (a + l + p) % mod;

    return dp[index][absent][late];
}
int checkRecord(int n)
{
    s = n;
    dp.resize(n, vector<vector<long long>>(2, vector<long long>(3, -1)));

    return solve(0, 2, 1) % mod;
}