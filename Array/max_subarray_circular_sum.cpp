// https://leetcode.com/problems/maximum-sum-circular-subarray/

int maxSubarraySumCircular(vector<int> &nums)
{
    int total = 0, max_sum = nums[0], min_sum = nums[0], curr_max = 0, curr_min = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        curr_max = max(curr_max + nums[i], nums[i]);
        max_sum = max(max_sum, curr_max);
        curr_min = min(curr_min + nums[i], nums[i]);
        min_sum = min(min_sum, curr_min);
        total += nums[i];
    }
    return (max_sum > 0) ? max(max_sum, total - min_sum) : max_sum;
}