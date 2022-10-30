// https://leetcode.com/problems/maximum-product-subarray/
#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums)
{
    int ans, mini, maxi;
    ans = maxi = mini = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            swap(mini, maxi);
        mini = min(nums[i], mini * nums[i]);
        maxi = max(nums[i], nums[i] * maxi);

        ans = max(ans, maxi);
    }
    return ans;
}