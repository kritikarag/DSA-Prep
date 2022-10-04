// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

vector<int> search(vector<int> &nums, int low, int high, int target)
{
    if (nums[low] == target && nums[high] == target)
        return {low, high};
    if (nums[low] <= target && target <= nums[high])
    {
        int mid = low + (high - low) / 2;
        vector<int> left = search(nums, low, mid, target);
        vector<int> right = search(nums, mid + 1, high, target);

        if (left[0] == -1)
            return right;
        if (right[0] == -1)
            return left;
        return {left[0], right[1]};
    }
    return {-1, -1};
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 0)
    {
        return {-1, -1};
    }
    return search(nums, 0, n - 1, target);
}