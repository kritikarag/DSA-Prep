// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

Recursive -> TLE

int knap(int W, int wt[], int val[], int ind)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    int not_take = knap(W, wt, val, ind - 1);
    int take = INT_MIN;

    if (wt[ind] <= W)
        take = val[ind] + knap(W - wt[ind], wt, val, ind - 1);

    return max(take, not_take);
}
// Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n)
{
    return knap(W, wt, val, n - 1); 
}

Memorization:

int knap(int W, int wt[], int val[], int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }
    if (dp[ind][W] != -1)
        return dp[ind][W];
    int not_take = knap(W, wt, val, ind - 1, dp);
    int take = INT_MIN;

    if (wt[ind] <= W)
        take = val[ind] + knap(W - wt[ind], wt, val, ind - 1, dp);

    return dp[ind][W] = max(take, not_take);
}
// Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knap(W, wt, val, n - 1, dp); 
}

Tabulation:
 
int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(W + 1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=weight;j++){
            int not_take = dp[i-1][j];
            int take = 0;
            if(wt[i-1]<=j)take = dp[i-1][j-wt[i-1]] + val[i-1];

            dp[i][j] = max(take, not_take);
        }
    }
    dp[n][W]; 
}