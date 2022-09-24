// https://leetcode.com/problems/number-of-islands/

//USING DFS
void eraseisland(int i, int j, int n, int m, vector<vector<char>> &grid)
{
    if (i < 0 || i == n || j < 0 || j == m || grid[i][j] == '0')
        return;

    grid[i][j] = '0';

    eraseisland(i + 1, j, n, m, grid);
    eraseisland(i, j + 1, n, m, grid);
    eraseisland(i, j - 1, n, m, grid);
    eraseisland(i - 1, j, n, m, grid);
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                eraseisland(i, j, n, m, grid);
            }
        }
    }
    return count;
}

//USING BFS

int DR[4] = {1, 0, -1, 0};
int DC[4] = {0, -1, 0, 1};

bool valid_index(int i, int j, vector<vector<char>> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return false;
    return true;
}

void bfs(int i, int j, vector<vector<char>> &grid)
{
    grid[i][j] = '0';
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ci = DR[k] + i;
            int cj = DC[k] + j;
            if (!valid_index(ci, cj, grid))
                continue;
            if (grid[ci][cj] == '1')
            {
                q.push({ci, cj});
                grid[ci][cj] = '0';
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int no_of_islands = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                no_of_islands++;
                bfs(i, j, grid);
            }
        }
    }
    return no_of_islands;
}