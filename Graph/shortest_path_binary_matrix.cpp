// https://leetcode.com/problems/shortest-path-in-binary-matrix/

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int r = grid.size();
    int c = grid[0].size();
    int ans = 0;

    queue<pair<int, int>> q;
    vector<vector<bool>> visit(r, vector(c, false));

    if (grid[0][0] == 1 || grid[r - 1][c - 1] == 1)
        return -1;

    q.push(make_pair(0, 0));
    visit[0][0] = true;

    while (!q.empty())
    {
        int steps = q.size();
        ans++;

        for (int i = 0; i < steps; i++)
        {
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if (x == r - 1 && y == c - 1)
                return ans;

            for (int j = 0; j < 8; j++)
            {
                int x1 = x + dir[j][0];
                int y1 = y + dir[j][1];

                if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c)
                {
                    if (!grid[x1][y1] && !visit[x1][y1])
                    {
                        q.push(make_pair(x1, y1));
                        visit[x1][y1] = true;
                    }
                }
            }
        }
    }
    return -1;
}


// Space Optimized

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        return -1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (r == n - 1 && c == m - 1)
            return grid[r][c];
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (i != 0 || j != 0)
                {
                    int nx = r + i;
                    int ny = c + j;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = grid[r][c] + 1;
                    }
                }
            }
        }
    }

    return -1;
}