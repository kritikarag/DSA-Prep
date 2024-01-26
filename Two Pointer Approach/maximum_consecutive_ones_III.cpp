// https://leetcode.com/problems/max-consecutive-ones-iii/description/

#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();

    int ans = 0, start = 0, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count++;
            while (count > k)
            {
                if (nums[start] == 0)
                {
                    count--;
                }
                start++;
            }
        }
        ans = max(ans, i - start + 1);
        cout << ans << " ";
    }
    return ans;
}