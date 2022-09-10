// https://leetcode.com/problems/minimum-path-sum/
#include<bits/stdc++.h>
using namespace std;

//RECUSION

int minPathSum(int i, int j, vector<vector<int>> &grid)
{
    if(i<=0||j<=0)return INT_MAX;
    if(i==1 && j==1)return grid[i-1][j-1];

    return grid[i-1][j-1]+min(minPathSum(i,j-1,grid),minPathSum(i-1,j,grid));
}

//MEMORIZATION

int dp[n][m]={-1};
int minpathsum(int i, int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
{
    if (i <= 0 || j <= 0)
        return INT_MAX;
    if (i == 1 && j == 1)
        return grid[n - 1][m - 1];

    if(dp[i][j]!=-1)return dp[i][j];

    dp[i][j] = grid[i-1][j-1] + min(minpathsum(i, j - 1,grid,dp), minpathsum(i - 1, j,grid,dp));
    return dp[i][j];
}

// //TABULATION

int minPathSum(int m, int n, vector<vector<int>> &grid)
{ 
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                dp[i][j] = grid[i - 1][j - 1];
            else
                dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

// //SPACE OPTIMIZATION
int minPathSum(int m, int n, vector<vector<int>> &grid)
{ 
    vector<int> prev(m + 1, INT_MAX);

    for (int i = 1; i <= m; i++)
    {
        vector<int> curr(n + 1, INT_MAX);
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                curr[j] = grid[i-1][j-1];
            else
                curr[j] = grid[i-1][j-1] + min(prev[j],curr[j - 1]);
        }
        prev = curr;
    }
    return prev[n];
}

int main()
{

    vector<vector<int>> matrix{{5, 9, 6},
                               {11, 5, 2}};

    int n = matrix.size();
    int m = matrix[0].size();

    cout << minPathSum(n, m, matrix);
}