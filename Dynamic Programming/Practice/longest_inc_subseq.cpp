// https://leetcode.com/problems/longest-increasing-subsequence/

#include<bits/stdc++.h>
using namespace std;

// MEMOIZATION
vector<vector<int>> dp;
int n;
int solve(int prev, int curr, vector<int> &nums)
{
    if (curr >= n)
        return 0;
    if (dp[prev + 1][curr] != -1)
        return dp[prev + 1][curr];

    int take = INT_MIN;
    if (prev == -1 || nums[prev] < nums[curr])
    {
        take = 1 + solve(curr, curr + 1, nums);
    }
    int not_take = solve(prev, curr + 1, nums);
    return dp[prev + 1][curr] = max(take, not_take);
}
int lengthOfLIS(vector<int> &nums)
{
    n = nums.size();
    dp.resize(n, vector<int>(n, -1));
    return solve(-1, 0, nums);
}

//TABULATION
int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1, 0));
        
        for(int ind=nums.size()-1; ind>=0; ind--){
            for(int prev=ind-1; prev>=-1; prev--){
                int take=0;
                if(prev==-1 || nums[prev]<nums[ind])
                    take = 1+dp[ind+1][ind+1];
                int not_take = dp[ind+1][prev+1];
                dp[ind][prev+1] = max(take, not_take);
            }
        }
        return dp[0][0];
    }

// Memory Optimized

// Print the lis