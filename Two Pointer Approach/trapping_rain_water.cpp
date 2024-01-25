// https://leetcode.com/problems/trapping-rain-water/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &height)
{
    int n = height.size();
    vector<int> prefix(n), suffix(n);

    prefix[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], height[i]);
    }
    suffix[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], height[i]);
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += min(prefix[i], suffix[i]) - height[i];
    }
    return result;
}

int trap(vector<int> &heights)
{
    int n = heights.size();
    int left = 0;
    int right = n - 1;
    int res = 0;
    int maxleft = 0, maxright = 0;
    while (left <= right)
    {
        if (heights[left] <= heights[right])
        {
            if (heights[left] >= maxleft)
                maxleft = heights[left];
            else
                res += maxleft - heights[left];
            left++;
        }
        else
        {
            if (heights[right] >= maxright)
                maxright = heights[right];
            else
                res += maxright - heights[right];
            right--;
        }
    }
    return res;
}