// https://leetcode.com/problems/max-area-of-island/

// USING BFS

int DR[4] = {1, 0, -1, 0};
int DC[4] = {0, -1, 0, 1};

bool valid_index(int i, int j, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return false;
    return true;
}

void bfs(int i, int j, vector<vector<int>> &grid, int &count)
{
    grid[i][j] = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        count++;
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ci = DR[k] + i;
            int cj = DC[k] + j;
            if (!valid_index(ci, cj, grid))
                continue;
            if (grid[ci][cj] == 1)
            {
                q.push({ci, cj});
                grid[ci][cj] = 0;
            }
        }
    }
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                int count = 0;
                bfs(i, j, grid, count);
                res = max(res, count);
            }
        }
    }

    return res;
}

// USING DFS -> Memory Optimized
void dfs(int i, int j, int m, int n, vector<vector<int>> &grid, int &count)
{
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
        return;

    grid[i][j] = 0;
    count++;
    dfs(i + 1, j, m, n, grid, count);
    dfs(i, j + 1, m, n, grid, count);
    dfs(i - 1, j, m, n, grid, count);
    dfs(i, j - 1, m, n, grid, count);
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                int count = 0;
                dfs(i, j, m, n, grid, count);
                res = max(res, count);
            }
        }
    }

    return res;
}