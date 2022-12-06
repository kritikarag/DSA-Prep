// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

vector<vector<int>> ans; 
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int m = grid.size(), n = grid[0].size();
    ans.resize(m, vector<int>(n, INT_MAX));

    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                ans[i][j] = 0;
            }
        }
    }

    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                dfs(i, j, grid, 0);
            }
        }
    }
    return ans;
}

void dfs(int i, int j, vector<vector<int>> &grid, int steps)
{
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> dr = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (auto r : dr)
    {
        int x = r.first + i, y = r.second + j;
        if (x < 0 || y < 0 || x >= m || y >= n)
            continue;
        if (ans[x][y] > steps + 1)
        {
            ans[x][y] = steps + 1;
            dfs(x, y, grid, steps + 1);
        }
    }
}