// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

void dfs(int index, vector<int> adj[], vector<bool> &vis)
{
    vis[index] = true;
    for (int i : adj[index])
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
        }
    }
}

int makeConnected(int n, vector<vector<int>> &conn)
{
    int len = conn.size();
    if (len < n - 1)
        return -1;
    vector<int> adj[n];
    for (auto v : conn)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            dfs(i, adj, vis);
            ans++;
        }
    return ans - 1;
}