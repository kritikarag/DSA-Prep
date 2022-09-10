#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coin, int amount)
{
    int n = coin.size();

    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= amount; i++)
        dp[0][i] = INT_MAX;
    for (int i = 1; i <= amount; i++)
    {
        if (i % coin[0] != 0)
            dp[1][i] = INT_MAX - 1;
        else
            dp[1][i] = i / coin[0];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (coin[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i][j]);
        }
    }
    
    if (dp[n][amount] == INT_MAX - 1)
        return -1;
    else
        return dp[n][amount];
}