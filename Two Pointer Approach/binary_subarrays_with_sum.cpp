// https://leetcode.com/problems/binary-subarrays-with-sum/

#include<bits/stdc++.h>
using namespace std;

int atmost(vector<int> &nums, int goal)
{
    int n = nums.size();
    int sum = 0, start = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        while (start <= i && sum > goal)
        {
            sum -= nums[start++];
        }
        ans += (i - start + 1);
    }
    return ans;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atmost(nums, goal) - atmost(nums, goal - 1);
}