// https://leetcode.com/problems/house-robber-ii/

int maxAmount(int ind, int end, vector<int> &vec)
{
    int prev2 = vec[ind];
    int prev1 = max(prev2, vec[ind + 1]);

    for (int i = ind + 2; i < end; i++)
    {
        int curr = max(prev1, prev2 + vec[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    int start = maxAmount(0, n - 1, nums);
    int finish = maxAmount(1, n, nums);
    return max(start, finish);
}