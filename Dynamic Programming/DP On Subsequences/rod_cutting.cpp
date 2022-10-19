// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

Recursion :

int solve(int ind, int n, int price[])
{
    if (ind == 0)
    {
        return n * price[0];
    }

    int not_take = solve(ind - 1, n, price);
    int take = INT_MIN;
    if (ind + 1 <= n)
    {
        take = price[ind] + solve(ind, n - ind - 1, price);
    }

    return max(take, not_take);
}

int cutRod(int price[], int n)
{
    return solve(n - 1, n, price);
}

Memorization :

int solve(int ind, int n, int price[], vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return n * price[0];
    }

    if (dp[ind][n] != -1)
        return dp[ind][n];

    int not_take = solve(ind - 1, n, price, dp);
    int take = INT_MIN;
    if (ind + 1 <= n)
    {
        take = price[ind] + solve(ind, n - ind - 1, price, dp);
    }

    return dp[ind][n] = max(take, not_take);
}
int cutRod(int price[], int n)
{
    // code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(n - 1, n, price, dp);
}

Tabulation :

int cutRod(int price[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = i * price[0];
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int not_take = dp[i - 1][j];
            int take = INT_MIN;
            if (i <= j)
                take = price[i - 1] + dp[i][j - i];

            dp[i][j] = max(take, not_take);
        }
    }

    return dp[n][n];
}

Space Optimization :

int cutRod(int price[], int n)
{
    vector<int>prev(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prev[i] = i * price[0];
    }

    for (int i = 2; i <= n; i++)
    {
        vector<int> curr(n + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            int not_take = prev[j];
            int take = INT_MIN;
            if (i <= j)
                take = price[i - 1] + curr[j - i];

            curr[j] = max(take, not_take);
        }
        prev = curr;
    }
    return prev[n];
}

More Space Optimized :

int cutRod(int price[], int n)
{
    vector<int> curr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        curr[i] = i * price[0];
    }

    for (int i = 2; i <= n; i++)
    { 
        for (int j = 1; j <= n; j++)
        {
            int not_take = curr[j];
            int take = INT_MIN;
            if (i <= j)
                take = price[i - 1] + curr[j - i];

            curr[j] = max(take, not_take);
        }
    }

    return curr[n];
}