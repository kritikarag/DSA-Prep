// https://leetcode.com/problems/minimum-size-subarray-sum/description/
int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0, sum = 0;
    int len = INT_MAX;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum >= target)
        {
            len = min(len, i - j + 1);
            while (sum >= target)
            {
                len = min(len, i - j + 1);
                sum -= nums[j++];
            }
        }
    }

    return (len == INT_MAX) ? 0 : len;
}