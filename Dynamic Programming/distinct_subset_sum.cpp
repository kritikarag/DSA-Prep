// https://practice.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums4424/1
vector<int> DistinctSum(vector<int> nums)
{
    // Code here
    vector<int> res;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int n = nums.size();
    bool dp[n + 1][sum + 1];
    for (int j = 0; j <= sum; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = (dp[i - 1][j - nums[i - 1]] || dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i])
            res.push_back(i);
    }

    return res;
}