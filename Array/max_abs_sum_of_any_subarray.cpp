// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/

#include<bits/stdc++.h>
using namespace std;

int maxAbsoluteSum(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 0, mini = 0, curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += nums[i];
        mini = min(curr, mini);
        maxi = max(maxi, curr);
    }
    return maxi - mini;
}