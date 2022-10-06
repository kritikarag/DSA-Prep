// https://leetcode.com/problems/shortest-bridge/

queue<pair<int, int>> q;

void dfs(int i, int j, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || grid[i][j] == 2)
    {
        return;
    }

    grid[i][j] = 2;
    q.push({i, j});

    dfs(i + 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i - 1, j, grid);
    dfs(i, j - 1, grid);
}

int bfs(vector<vector<int>> &grid)
{
    int steps = 0;
    int dis = INT_MAX;

    int dir[5] = {0, 1, 0, -1, 0};

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int r = x + dir[i];
                int c = y + dir[i + 1];

                if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size())
                {
                    if (grid[r][c] == 1)
                    {
                        dis = min(steps, dis);
                    }
                    else if (grid[r][c] == 0)
                    {
                        q.push({r, c});
                        grid[r][c] = 2;
                    }
                }
            }
        }
        steps++;
    }
    return dis;
}

int shortestBridge(vector<vector<int>> &grid)
{
    bool flag = false;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(i, j, grid);
                q.push({i, j});
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    return bfs(grid);
}

/* INTITUTION 
    Given in the question is that there exist only two islands which means we need to 
    form a pair of group of 1's.
    First of all we will traverse through the grid and when we'll get our first 1 we'll use dfs and get 
    our first group of 1's i.e, our first island. 
*/