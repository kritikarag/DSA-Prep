// https://leetcode.com/problems/next-permutation/description/

#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int index = n;
    for (int i = n - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i])
        {
            index = i - 1;
            break;
        }
    }
    if (index == n)
    {
        sort(nums.begin(), nums.end());
    }
    else
    {
        int high = n - 1;
        while (high > index)
        {
            if (nums[high] > nums[index])
                break;
            high--;
        }
        swap(nums[high], nums[index]);
        reverse(nums.begin() + index + 1, nums.end());
    }
}