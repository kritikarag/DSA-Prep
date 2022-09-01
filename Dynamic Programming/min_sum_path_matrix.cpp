int minsumpath(vector<vector<int>>&matrix){
    int n = matrix.size();
    vector<vector<int>>res(n,vector<int>(n,-1));
    dp[0][0]=matrix[0][0]; 
    for(int i=0;i<n;i++) 
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