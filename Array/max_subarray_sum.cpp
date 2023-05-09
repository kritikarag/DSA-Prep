// https://leetcode.com/problems/maximum-subarray/description/

int maxSubArray(vector<int> &nums)
{
    int res = INT_MIN, curr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        curr = max(nums[i], curr + nums[i]);
        res = max(res, curr);
    }

    return res;
}

int maxSubArray(vector<int> &nums)
{
    int res = INT_MIN, curr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        curr += nums[i];
        res = max(res, curr);
        if (curr < 0)
        {
            curr = 0;
        }
    }
    return res;
}