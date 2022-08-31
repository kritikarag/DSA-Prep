// https://leetcode.com/problems/pacific-atlantic-water-flow/

void dfs(vector<vector<int>> &heights, int i, int j, int prev, vector<vector<bool>> &vis)
{
    if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size() || prev > heights[i][j] || vis[i][j])
        return;

    vis[i][j] = true;

    dfs(heights, i - 1, j, heights[i][j], vis);
    dfs(heights, i + 1, j, heights[i][j], vis);
    dfs(heights, i, j + 1, heights[i][j], vis);
    dfs(heights, i, j - 1, heights[i][j], vis);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> heights)
{
    int n = heights.size();
    if (n == 0)
        return {};

    int m = heights[0].size();

    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        dfs(heights, i, 0, INT_MIN, pacific);
        dfs(heights, i, m - 1, INT_MIN, atlantic);
    }

    for (int j = 0; j < m; j++)
    {
        dfs(heights, 0, j, INT_MIN, pacific);
        dfs(heights, n - 1, i, INT_MIN, atlantic);
    }

    vector<vector<int>> res;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (pacific[i][j] && atlantic[i][j])
                res.push_back({i, j});
        }
    }

    return res;
}