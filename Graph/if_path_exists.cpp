//

//Using DFS

void dfs(vector<int> graph[], vector<int> &vis, int node, int des)
{
    vis[node] = 1;
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            dfs(graph, vis, it, des);
        }
    }
}

bool validPath(int n, vector<vector<int>> &edges, int src, int des)
{
    vector<int> vis(n, 0);
    vector<int> graph[n];
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    dfs(graph, vis, src, des);

    return vis[des] == 1;
}

//Using BFS


