// https://leetcode.com/problems/min-cost-climbing-stairs/

Recursion : ->TLE
int solve(int ind, vector<int> &cost)
{
    if (ind == 0 || ind == 1)
        return cost[ind];
    return cost[ind] + min(solve(ind - 1, cost), solve(ind - 2, cost));
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    return min(solve(n - 1, cost), solve(n - 2, cost));
}

Memorization : ->TLE

int solve(int ind, vector<int> &cost, vector<int>&dp)
{
    if (ind == 0 || ind == 1)
        return cost[ind];
    if(dp[ind]!=-1)return dp[ind];
    return cost[ind] + min(solve(ind - 1, cost, dp), solve(ind - 2, cost, dp));
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int>dp(n,-1);
    return min(solve(n - 1, cost, dp), solve(n - 2, cost, dp));
}

Tabulation :

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 2], dp[n - 1]);
}

Space Optimized :

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size(); 
    prev2 = cost[0];
    prev1 = cost[1];
    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev2=prev1;
        prev1 =curr;
    }

    return min(prev1, prev2);
}