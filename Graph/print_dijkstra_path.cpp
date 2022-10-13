// https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // Code here
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, INT_MAX), parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    dis[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int temp = it.first;
            int curr = it.second;

            if (dis[temp] > curr + weight)
            {
                dis[temp] = curr + weight;
                parent[temp] = node;
                pq.push({dis[temp],temp});
            }
        }
    }
    if (dis[n] == INT_MAX)
        return {-1};

    vector<int> path;
    int node = n;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = path[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return path;
}