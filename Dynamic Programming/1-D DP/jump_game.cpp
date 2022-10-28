// https://leetcode.com/problems/jump-game/

Linear: 
bool canJump(vector<int> &nums)
{
    int jump = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (i > jump)
            return false;
        jump = max(jump, i + nums[i]);
    }

    return true;
}

Recursion: ->TLE
bool solve(int ind, vector<int> &nums)
{
    if (ind == nums.size() - 1)
        return true;
    int jump = ind + nums[ind];
    for (int i = ind + 1; i <= jump; i++)
    {
        if (solve(i, nums))
            return true;
    }

    return false;
}
bool canJump(vector<int> &nums)
{
    return solve(0, nums);
}

Memorization :

bool solve(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == nums.size() - 1)
        return true;
    if (dp[ind] != -1)
        return dp[ind];
    int jump = ind + nums[ind];
    for (int i = ind + 1; i <= jump; i++)
    {
        if (solve(i, nums, dp))
            return dp[ind] = true;
    }

    return dp[ind] = false;
}
bool canJump(vector<int> &nums)
{
    vector<int> dp(nums.size(), -1);
    return solve(0, nums, dp);
}

Tabulation :

bool canJump(vector<int> &nums)
{
    vector<int> dp(nums.size(), false);
    dp[0] = true;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j] && j + nums[j] >= i)
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[nums.size() - 1];
}