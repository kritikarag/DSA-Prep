//https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

#include<bits/stdc++.h>
using namespace std;
long long zeroFilledSubarray(vector<int>&nums)
{
    long long ans = 0, count = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            ans += count;
            count++;
        }
        else
        {
            count = 1;
        }
    }
    return ans;
}