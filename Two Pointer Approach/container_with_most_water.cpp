int maxArea(vector<int> &height)
{
    int n = height.size();
    int low = 0, high = n - 1;
    int water = INT_MIN;
    while (low < high)
    {
        int h = min(height[high], height[low]);
        int base = abs(high - low);
        water = max(water, h * base);
        while (height[low] <= h && low < high)
            low++;
        while (height[high] <= h && low < high)
            high--;
    }

    return water;
}