// https://practice.geeksforgeeks.org/problems/alex-travelling/1

int minimumCost(vector<vector<int>> &flights, int n, int k)
{
    // code here
    vector<int> dist(n + 1, 1e9 + 7);
    vector<pair<int, int>> g[n + 1];
    for (auto it : flights)
    {
        g[it[0]].push_back({it[1], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, k});
    dist[k] = 0;
    while (!q.empty())
    {
        int u = q.top().second;
        int w = q.top().first;
        q.pop();
        if (dist[u] < w)
            continue;
        for (auto it : g[u])
        {
            int to = it.first;
            int w = it.second;
            if (dist[to] > (dist[u] + w))
            {
                dist[to] = dist[u] + w;
                q.push({dist[to], to});
            }
        }
    }
    int mn = -1;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] >= 1e9 + 7)
            return -1;
        mn = max(dist[i], mn);
    }
    return mn;
}