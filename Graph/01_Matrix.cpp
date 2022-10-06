// https://leetcode.com/problems/01-matrix/

int row[5] = {0, 1, 0, -1, 0};
int dir[5] = {0, 1, 0, -1, 0};
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({i, j});
            }
            else
                mat[i][j] = -1;
        }
    }

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int cr = r + dir[i];
            int cc = c + dir[i + 1];

            if (cr < 0 || cc < 0 || cr >= n || cc >= m || mat[cr][cc] != -1)
                continue;

            mat[cr][cc] = mat[r][c] + 1;
            q.push({cr, cc});
        }
    }

    return mat;
}

//Using Dynamic Programming

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int INF = m + n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
                continue;
            int top = INF, left = INF;
            if (i - 1 >= 0)
                top = mat[i - 1][j];
            if (j - 1 >= 0)
                left = mat[i][j - 1];

            mat[i][j] = min(top, left) + 1;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (mat[i][j] == 0)
                continue;

            int bottom = INF, right = INF;
            if (i + 1 < n)
                bottom = mat[i + 1][j];
            if (j + 1 < m)
                right = mat[i][j + 1];

            mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
        }
    }

    return mat;
}

// Needs modifications

int row[4] = {0, 0, -1, 1};
int col[4] = {1, -1, 0, 0};
int bfs(int i, int j, vector<vector<int>> &grid)
{
    int steps = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty())
    {
        int n = q.size();
        steps++;
        while (n--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (grid[x][y] == 0)
                return steps - 1;

            for (int i = 0; i < 4; i++)
            {
                int r = row[i] + x;
                int c = col[i] + y;
                if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size())
                {
                    q.push({r, c});
                }
            }
        }
    }
    return steps - 1;
}
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] != 0)
            {
                ans[i][j] = bfs(i, j, mat);
            }
        }
    }

    return ans;
}