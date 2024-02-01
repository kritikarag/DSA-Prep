// https://leetcode.com/problems/subarrays-with-k-different-integers/

#include<bits/stdc++.h>
using namespace std;

int atmost(vector<int> &nums, int k)
{
    int n = nums.size();
    int ans = 0, start = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
        while (mp.size() > k)
        {
            mp[nums[start]]--;
            if (mp[nums[start]] == 0)
                mp.erase(nums[start]);
            start++;
        }
        ans += i - start + 1;
    }
    return ans;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return atmost(nums, k) - atmost(nums, k - 1);
}