// https://leetcode.com/problems/coin-change/

Recursion :

int solve(int ind, vector<int> &coins, int amount)
{
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }
        else
        {
            return 1e9;
        }
    }

    int not_take = solve(ind - 1, coins, amount);
    int take = 1e9;
    if (coins[ind] <= amount)
        take = 1 + solve(ind, coins, amount - coins[ind]);

    return min(not_take, take);
}

int coinChange(vector<int> &coins, int amount)
{
    int res = solve(coins.size() - 1, coins, amount);
    return res >= 1e9 ? -1 : res;
}

Memorization :

int solve(int ind, vector<int> &coins, int amount, vector<vector<int>>&dp)
{
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }
        else
        {
            return 1e9;
        }
    }

    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int not_take = solve(ind - 1, coins, amount,dp);
    int take = 1e9;
    if (coins[ind] <= amount)
        take = 1 + solve(ind, coins, amount - coins[ind],dp);

    return dp[ind][amount] = min(not_take, take);
}

int coinChange(vector<int> &coins, int amount)
{

    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int res = solve(coins.size() - 1, coins, amount,dp);
    return res >= 1e9 ? -1 : res;
}

Tabulation :

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    for (int i = 0; i <= amount; i++)
        dp[0][i] = INT_MAX;
    for (int i = 1; i <= amount; i++)
    {
        if (i % coins[0] != 0)
            dp[1][i] = 1e9;
        else
            dp[1][i] = i / coins[0];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            int not_take = dp[i - 1][j];
            int take = 1e9;
            if (coins[i - 1] <= j)
            {
                take = 1 + dp[i][j - coins[i - 1]];
            }

            dp[i][j] = min(take, not_take);
        }
    }

    if (dp[n][amount] >= 1e9)
        return -1;
    else
        return dp[n][amount];
}

Space Optimized:

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<int>prev(amount + 1, 0); 
    for (int i = 1; i <= amount; i++)
    {
        if (i % coins[0] != 0)
            prev[i] = 1e9;
        else
            prev[i] = i / coins[0];
    }

    for (int i = 2; i <= n; i++)
    {
        vector<int>curr(amount+1,0);
        for (int j = 1; j <= amount; j++)
        {
            int not_take = prev[j];
            int take = 1e9;
            if (coins[i - 1] <= j)
            {
                take = 1 + curr[j - coins[i - 1]];
            }

            curr[j] = min(take, not_take);
        }
        prev = curr;
    }

    if (prev[amount] >= 1e9)
        return -1;
    else
        return prev[amount];
}