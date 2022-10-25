// https://leetcode.com/problems/n-th-tribonacci-number/

Recursion -> Possible Solution but gives TLE

int tribonacci(int n)
{
    if (n == 0)
        return n;
    if (n == 1 || n == 2)
        return 1; 
    return tribonacci(n-1)+ tribonacci(n-2) + tribonacci(n-3);
}

Memorization :

int solve_tribonacci(int n, vector<int>&dp)
{
    if (n == 0)
        return dp[0] = 0;
    if (n == 1 || n == 2)
        return dp[n] = 1;
    
    if(dp[n]!=-1) return dp[n];
    return dp[n] = solve_tribonacci(n - 1, dp) + solve_tribonacci(n - 2 , dp) + solve_tribonacci(n - 3 , dp);
}

int tribonacci(int n){
    vector<int>dp(n+1,-1);
    solve_tribonacci(n,dp);
    return dp[n];
}

Tabulation :

int tribonacci(int n)
{
    vector<int>dp(n+1,0);
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];  
    }
    return dp[n];
}

Space Optimized : 

int tribonacci(int n)
{
    if (n == 0)
        return n;
    if (n == 1 || n == 2)
        return 1;

    int prev1 = 1, prev2 = 1, prev3 = 0, res;
    for (int i = 3; i <= n; i++)
    {
        res = prev1 + prev2 + prev3;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = res;
    }

    return res;
}