// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

void dfs(vector<vector<int>> &grid, int i, int j, vector<pair<int, int>> &vis)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 0)
        return;
    grid[i][j] = 0;
    vis.push_back({i, j});
    dfs(grid, i + 1, j, vis);
    dfs(grid, i, j + 1, vis);
    dfs(grid, i - 1, j, vis);
    dfs(grid, i, j - 1, vis);
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    int count = 0;
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                vector<pair<int, int>> vis;
                dfs(grid, i, j, vis);
                auto t = vis[0];
                for (auto &it : vis)
                {
                    it.first -= t.first;
                    it.second -= t.second;
                }
                st.insert(vis);
            }
        }
    }
    return st.size();
}