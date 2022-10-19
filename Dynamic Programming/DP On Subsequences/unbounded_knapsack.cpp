// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

Recursion :

int knapSack(int ind, int weight, int val[], int wt[])
{
    if (ind == 0)
    {
        return (weight / wt[0]) * val[0];
    }

    int not_take = knapSack(ind - 1, weight, val, wt);
    int take = INT_MIN;
    if (wt[ind] <= weight)
        take = val[ind] + knapSack(ind, weight - wt[ind], val, wt);

    return max(take, not_take);
    // code here
}

Memorization :

int unboundKnapsack(int ind, int wt[], int val[], int weight, vector<vector<int>>&dp)
{
    if (ind == 0)
    {
        return (weight / wt[0]) * val[0];
    }

    if(dp[ind][weight]!=-1)return dp[ind][weight];

    int not_take = unbounKnapsack(ind - 1, wt, val, weight,dp);
    int take = INT_MIN;
    if (wt[ind] <= wt)
        take = val[ind] + unboundKnapsack(ind, wt, val, weight - wt[ind],dp);

    return dp[ind][weight] = max(take, not_take);
}

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return unboundKnapsack(N - 1, wt, val, W, dp); 
}

Tabulation :

int knapSack(int n, int weight, int val[], int wt[])
{
    vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));
    for (int i = 0; i <= weight; i++)
    {
        dp[1][i] = (i / wt[0]) * val[0];
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= weight; j++)
        {
            int not_take = dp[i - 1][j];
            int take = INT_MIN;
            if (wt[i - 1] <= j)
                take = val[i - 1] + dp[i][j - wt[i - 1]];

            dp[i][j] = max(take, not_take);
        }
    }
    return dp[n][weight];
}

Space Optimized :

int knapSack(int n, int weight, int val[], int wt[])
{
    vector<int>prev(weight + 1, 0);
    for (int i = 0; i <= weight; i++)
    {
        prev[i] = (i / wt[0]) * val[0];
    }
    for (int i = 2; i <= n; i++)
    {
        vector<int> curr(weight + 1, 0);
        for (int j = 1; j <= weight; j++)
        {
            int not_take = prev[j];
            int take = INT_MIN;
            if (wt[i - 1] <= j)
                take = val[i - 1] + curr[j - wt[i - 1]];

            curr[j] = max(take, not_take);
        }
        prev = curr;
    }
    return prev[weight];
    // code here
}
