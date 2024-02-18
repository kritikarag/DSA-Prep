// https://leetcode.com/problems/cherry-pickup-ii/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;
int n, m;
int solve(int x, int y1, int y2, vector<vector<int>> &grid)
{
    if (x >= n || y1 < 0 || y1 >= m || y2 < 0 || y2 >= m)
        return 0;

    if (dp[x][y1][y2] != -1)
        return dp[x][y1][y2];

    int ans = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int curr = 0;
            if (y1 == y2)
            {
                curr = grid[x][y1] + solve(x + 1, y1 + i, y2 + j, grid);
                ans = max(ans, curr);
            }
            else
            {
                curr = grid[x][y1] + grid[x][y2] + solve(x + 1, y1 + i, y2 + j, grid);
                ans = max(ans, curr);
            }
        }
    }
    return dp[x][y1][y2] = ans;
}
int cherryPickup(vector<vector<int>> &grid)
{
    n = grid.size(), m = grid[0].size();
    dp.resize(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solve(0, 0, m - 1, grid);
}