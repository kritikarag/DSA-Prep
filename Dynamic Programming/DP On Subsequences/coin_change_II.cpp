// https://leetcode.com/problems/coin-change-ii/

Recursion :

int count(int ind, vector<int> &coins, int target)
{
    if (ind == 0)
    {
        return (target % coins[0] == 0);
    }
    int not_take = count(ind - 1, coins, target);
    int take = 0;
    if (coins[ind] <= target)
        take = count(ind, coins, target - coins[ind]);

    return not_take + take;
}

int change(int amount, vector<int> &coins)
{
    return count(coins.size() - 1, coins, amount);
}

Memorization :

int count(int ind, vector<int> &coins, int target, vector<vector<int>>&dp)
{
    if (ind == 0)
    {
        return (target % coins[0] == 0);
    }

    if(dp[ind][target]!=-1)return dp[ind][target];
    int not_take = count(ind - 1, coins, target, dp);
    int take = 0;
    if (coins[ind] <= target)
        take = count(ind, coins, target - coins[ind], dp);

    return dp[ind][target] = not_take + take;
}

int change(int amount, vector<int> &coins)
{
    vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
    return count(coins.size() - 1, coins, amount, dp);
}

Tabulation :

int change(int amount, vector<int> &coins)
{
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= coins.size(); i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[1][i] = 1;
    }

    for (int i = 2; i <= coins.size(); i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            int not_take = dp[i - 1][j];
            int take = 0;
            if (coins[i - 1] <= j)
            {
                take = dp[i][j - coins[i - 1]];
            }

            dp[i][j] = take + not_take;
        }
    }

    return dp[coins.size()][amount];
}

Space Optimized :

int change(int amount, vector<int> &coins)
{
    vector<int>prev(amount + 1, 0);
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = 1;
    }

    for (int i = 2; i <= coins.size(); i++)
    {
        vector<int> curr(amount + 1, 0);
        curr[0] = 1;
        for (int j = 1; j <= amount; j++)
        {
            int not_take = prev[j];
            int take = 0;
            if (coins[i - 1] <= j)
            {
                take = curr[j - coins[i - 1]];
            }

            curr[j] = take + not_take;
        }

        prev = curr;
    }

    return prev[amount];
}