// https://leetcode.com/problems/number-of-closed-islands/

//DFS -> SPACE OPTIMIZED

bool dfs(int i, int j, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
    {
        return false;
    }
    if (grid[i][j] == 1)
        return true;
    grid[i][j] = 1;

    bool right = dfs(i + 1, j, grid);
    bool top = dfs(i, j + 1, grid);
    bool left = dfs(i - 1, j, grid);
    bool down = dfs(i, j - 1, grid);

    return ((right && left) && (top && down));
}
int closedIsland(vector<vector<int>> &grid)
{
    int res = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 0)
            {
                if (dfs(i, j, grid))
                    res++;
            }
        }
    }
    return res;
}

