// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

int specialArray(vector<int> &nums)
{
    sort(nums.begin(), nums.end()); // O(NlogN)
    const int N = nums.size();
    if (nums[0] >= N)
        return N;
    int l = 1, r = N - 1;
    while (l <= r)
    { // O(LogN) * O(1)
        int m = l + (r - l) / 2;
        if (nums[m] >= (N - m) && nums[m - 1] < (N - m))
            return (N - m);
        else if (nums[m] >= (N - m))
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}