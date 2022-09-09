// https://leetcode.com/problems/minimum-path-sum/
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = grid[i][j];
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                dp[i][j] += dp[i][j - 1];
            else if (j == 0)
                dp[i][j] += dp[i - 1][j];
            else
                dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m - 1][n - 1];
}

//Recursion

int minpathsum(int i, int j){
    if(i>=n||j>=m)return INT_MAX;
    if(i==n-1 && j==m-1)return a[n-1][m-1];

    return grid[i][j]+min(minpathsum(i,j+1),minpathsum(i+1,j));
}

int dp[n][m]={-1};
int minpathsum(int i, int j)
{
    if (i >= n || j >= m)
        return INT_MAX;
    if (i == n - 1 && j == m - 1)
        return a[n - 1][m - 1];

    if(dp[i][j]!=-1)return dp[i][j];

    dp[i][j] = grid[i][j] + min(minpathsum(i, j + 1), minpathsum(i + 1, j));
    return dp[i][j];
}