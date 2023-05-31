#include<bits/stdc++.h>
using namespace std;

bool valid(int i,int j, int n, int m){
    if(i<0||i>=n||j<0||j>=m)return false;
    return true;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

    for (int i = 0; i < m; i++)
    {
        dp[0][i] = matrix[0][i];
    }

    int col[3] = {-1, 0, 1};

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                int r = i - 1, c = j + col[k];
                if (valid(r, c, n, m))
                {
                    dp[i][j] = max(dp[i][j], matrix[i][j] + dp[r][c]);
                }
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, dp[n - 1][i]);
    }
    return ans;
}