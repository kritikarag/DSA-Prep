// https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1

#include <bits/stdc++.h>
using namespace std;

int numOfWays(int target, int x)
{
    // code here
    int mod = 1e9 + 7;
    vector<long long> nums;
    for (long long i = 1; pow(i, x) <= target; i++)
    {
        nums.push_back(pow(i, x));
    }

    long long n = nums.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
    for (long long i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    if (nums[0] <= target)
        dp[1][nums[0]] = 1;

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= target; j++)
        {
            long long not_take = dp[i - 1][j] % mod;
            long long take = 0;
            if (j >= nums[i - 1])
            {
                take = (dp[i - 1][j - nums[i - 1]]) % mod;
            }
            dp[i][j] = (take + not_take) % mod;
        }
    }
    return dp[n][target] % mod;
}