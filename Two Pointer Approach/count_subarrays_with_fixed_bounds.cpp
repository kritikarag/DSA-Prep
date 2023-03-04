// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

long long countSubarrays(vector<int> &nums, int minK, int maxK)
{
    int n = nums.size();
    long long res = 0;
    int ibad = -1, imin = -1, imax = -1;
    for (int i = 0; i < n; i++)
    {
        if (minK > nums[i] || maxK < nums[i])
            ibad = i;
        if (nums[i] == minK)
            imin = i;
        if (nums[i] == maxK)
            imax = i;

        res += max(0, min(imax, imin) - ibad);
    }
    return res;
}