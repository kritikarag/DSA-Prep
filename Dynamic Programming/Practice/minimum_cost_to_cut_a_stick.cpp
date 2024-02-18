// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int solve(int start, int end, vector<int> &cuts)
{
    if (start > end)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];
    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, cuts[end + 1] - cuts[start - 1] + solve(start, i - 1, cuts) + solve(i + 1, end, cuts));
    }
    return dp[start][end] = ans;
}
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    dp.resize(c + 1, vector<int>(c + 1, -1));
    return solve(1, c, cuts);
}