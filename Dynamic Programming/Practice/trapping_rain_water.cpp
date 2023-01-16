// https://leetcode.com/problems/trapping-rain-water/description/

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

int trap(vector<int> &heights)
{
    int n = heights.size();
    int left = 0;
    int right = n - 1;
    int res = 0;
    int currlevel = 0, maxlevel = 0;
    while (left <= right)
    {
        currlevel = heights[heights[left] < heights[right] ? left++ : right--];
        maxlevel = max(currlevel, maxlevel);
        res += maxlevel - currlevel;
    }
    return res;
}