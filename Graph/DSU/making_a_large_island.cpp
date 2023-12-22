// https://leetcode.com/problems/making-a-large-island/description/

#inlude<bits/stdc++.h>
using namespace std;

vector<int> parent, cap, vis;
int dir[5] = {0, 1, 0, -1, 0};
bool check(int x, int y, vector<vector<int>> grid)
{
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())
        return false;
    return true;
}
void dfs(int par, int x, int y, vector<vector<int>> grid)
{
    if (!check(x, y, grid) || grid[x][y] == 0)
        return;

    int curr = x * grid[0].size() + y;
    if (vis[curr])
        return;
    vis[curr] = true;
    if (curr != par)
        cap[par]++;
    parent[curr] = par;
    for (int i = 0; i < 4; i++)
    {
        dfs(par, x + dir[i], y + dir[i + 1], grid);
    }
}
int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vis.resize(n * m, 0);
    parent.resize(n * m);
    for (int i = 0; i < n * m; i++)
    {
        parent[i] = i;
    }
    cap.resize(n * m, 1);
    vector<int> store;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int node = i * m + j;
            if (grid[i][j] == 1 && !vis[node])
            {
                // cout<<node<<endl;
                dfs(node, i, j, grid);
                result = max(result, cap[node]);
            }
            else if (grid[i][j] == 0)
            {
                store.push_back(node);
            }
        }
    }
    // for(int i:store)cout<<i<<" ";
    for (int i = 0; i < store.size(); i++)
    {
        int node = store[i];
        int x = node / m, y = node % m;

        int temp = 0;
        unordered_set<int> s;
        for (int j = 0; j < 4; j++)
        {
            if (check(x + dir[j], y + dir[j + 1], grid) && grid[x + dir[j]][y + dir[j + 1]] == 1)
            {
                int curr = (x + dir[j]) * m + (y + dir[j + 1]);
                int par = parent[curr];
                s.insert(par);
            }
        }
        for (auto it : s)
        {
            temp += cap[it];
        }
        result = max(result, temp + 1);
    }
    return result;
}