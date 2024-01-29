// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include<bits/stdc++.h>
using namespace std;
int atmost(vector<int> &nums, int k)
{
    int n = nums.size();

    int start = 0, count = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & 1)
            count++;

        while (start <= i && count > k)
        {
            if (nums[start] & 1)
                count--;
            start++;
        }
        ans += (i - start + 1);
    }
    return ans;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    return atmost(nums, k) - atmost(nums, k - 1);
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0, ans = 0;
    unordered_map<int, int> mp;

    for (int i : nums)
    {
        if (i & 1)
            count++;
        if (count == k)
            ans++;
        int req = count - k;

        if (mp.find(req) != mp.end())
            ans += mp[req];
        mp[count]++;
    }
    return ans;
}