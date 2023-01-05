// https://leetcode.com/problems/house-robber/description/

Time Complexity - O(N), Space Complexity - O(N): 

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int not_take = dp[i - 1];
        int take = dp[i - 2] + nums[i];

        dp[i] = max(not_take, take);
    }

    return dp[n - 1];
}

// Space Optimized

Time Complexity - O(N), Space Complexity - O(1) :

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    int prev2 = nums[0], prev1 = max(nums[0], nums[1]), res = 0;
    for (int i = 2; i < n; i++)
    {
        int take = prev2 + nums[i];
        int not_take = prev1;

        res = max(take, not_take);

        prev2 = prev1;
        prev1 = res;
    }

    return res;
}