// https://leetcode.com/problems/sliding-subarray-beauty/description/

#include<bits/stdc++.h>
using namespace std;
vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
{
    vector<int> ans;
    int n = nums.size();
    map<int, int> mp;
    for (int i = 0; i < k - 1; i++)
    {
        if (nums[i] <= 0)
            mp[nums[i]]++;
    }
    for (int i = k - 1; i < n; i++)
    {
        if (nums[i] <= 0)
            mp[nums[i]]++;
        int temp = x;
        for (auto it : mp)
        {
            temp -= it.second;
            if (temp <= 0)
            {
                ans.push_back(it.first);
                break;
            }
        }
        if (temp > 0)
            ans.push_back(0);
        mp[nums[i - k + 1]]--;
    }
    return ans;
}