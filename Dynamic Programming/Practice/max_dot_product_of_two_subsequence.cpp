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

