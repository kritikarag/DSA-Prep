// https://leetcode.com/problems/unique-paths-iii/description/

int count = 1, ans = 0;

void dfs(vector<vector<int>> &grid, int x, int y, int check)
{
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1)
        return;

    if (grid[x][y] == 2)
    {
        if (check == count)
            ans++;
        return;
    }

    grid[x][y] = -1;

    dfs(grid, x + 1, y, check + 1);
    dfs(grid, x - 1, y, check + 1);
    dfs(grid, x, y + 1, check + 1);
    dfs(grid, x, y - 1, check + 1);

    grid[x][y] = 0;
}
int uniquePathsIII(vector<vector<int>> &grid)
{
    int start_x = 0, start_y = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                start_x = i;
                start_y = j;
            }
            else if (grid[i][j] == 0)
                count++;
        }
    }

    dfs(grid, start_x, start_y, 0);
    return ans;
}