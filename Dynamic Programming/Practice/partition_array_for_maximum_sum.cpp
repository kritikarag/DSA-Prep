// https://leetcode.com/problems/partition-array-for-maximum-sum/

#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
int solve(int index, vector<int> &arr, int k)
{
    if (index >= arr.size())
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int ans = 0, maxi = 0, n = arr.size();

    for (int i = index; i < min(index + k, n); i++)
    {
        maxi = max(maxi, arr[i]);
        ans = max(ans, (i - index + 1) * maxi + solve(i + 1, arr, k));
    }

    return dp[index] = ans;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();

    dp.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int ans = 0, maxi = 0;
        for (int j = i; j > max(i - k, 0); j--)
        {
            maxi = max(arr[j - 1], maxi);
            ans = max(ans, (i - j + 1) * maxi + dp[j - 1]);
        }
        dp[i] = ans;
    }
    return dp[n];
    // return solve(0,arr,k);
}