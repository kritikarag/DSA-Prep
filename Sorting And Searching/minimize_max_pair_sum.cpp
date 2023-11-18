// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

int minPairSum(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int result = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        result = max(result, nums[i++] + nums[j--]);
    }
    return result;
}