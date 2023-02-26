// https://practice.geeksforgeeks.org/problems/1a4b617b70f0142a5c2b454e6fbe1b9a69ce7861/1

bool bfs(int src, vector<vector<int>> &adj, vector<int> &vis)
{
    queue<int> q;
    int e = adj[src].size();
    int v = 0;
    q.push(src);
    vis[src] = 1;
    bool f = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        v++;

        if (adj[cur].size() != e)
            f = false;

        for (int x : adj[cur])
        {
            if (!vis[x])
            {
                vis[x] = 1;
                q.push(x);
            }
        }
    }

    return f && v == e + 1;
}
int findNumberOfGoodComponent(int v, vector<vector<int>> &adj)
{
    // code here
    vector<int> vis(v + 1, 0);
    int ans = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if (bfs(i, adj, vis))
            {
                ans += 1;
            }
        }
    }
    return ans;
}