// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

int dfs(int node, int cost, vector<bool> &fill, vector<int> graph[], vector<bool> &vis)
{
    if (vis[node])
        return 0;
    vis[node] = true;
    int childcost = 0;

    for (auto it : graph[node])
    {
        childcost += dfs(it, 2, fill, graph, vis);
    }

    if (childcost == 0 && fill[node] == false)
        return 0;

    return (childcost + cost);
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
    vector<int> graph[n];
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> vis(n, false);
    return dfs(0, 0, hasApple, graph, vis);
}