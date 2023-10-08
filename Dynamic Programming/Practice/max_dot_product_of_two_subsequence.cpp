// https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?

#include<bits/stdc++.h>
using namespace std;
// Memoization

vector<vector<int>> dp;
int solve(int i, int j, vector<int> &nums1, vector<int> &nums2)
{
    if (i < 0 || j < 0)
        return -1e9;

    if (dp[i][j] != -1)
        return dp[i][j];

    int not_take_i = solve(i - 1, j, nums1, nums2);
    int not_take_j = solve(i, j - 1, nums1, nums2);
    int take = max(nums1[i] * nums2[j], nums1[i] * nums2[j] + solve(i - 1, j - 1, nums1, nums2));

    return dp[i][j] = max({not_take_i, not_take_j, take});
}
int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    dp.resize(n, vector<int>(m, -1));

    return solve(n - 1, m - 1, nums1, nums2);
}

//Tabulation

int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int not_take_i = dp[i - 1][j];
            int not_take_j = dp[i][j - 1];

            int take = nums1[i - 1] * nums2[j - 1];
            take = max(take, take + dp[i - 1][j - 1]);

            dp[i][j] = max({not_take_i, not_take_j, take});
        }
    }
    return dp[n][m];
}