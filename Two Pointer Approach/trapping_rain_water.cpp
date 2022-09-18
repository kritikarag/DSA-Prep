// https://leetcode.com/problems/trapping-rain-water/

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