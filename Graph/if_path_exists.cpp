// https://leetcode.com/problems/find-if-path-exists-in-graph/

Using DFS :-
Runtime: 686 ms, faster than 90.78% of C++ online submissions for Find if Path Exists in Graph.
Memory Usage: 209.9 MB, less than 29.62% of C++ online submissions for Find if Path Exists in Graph.

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


Using BFS:-
Runtime: 643 ms, faster than 93.66% of C++ online submissions for Find if Path Exists in Graph.
Memory Usage: 148.8 MB, less than 83.87% of C++ online submissions for Find if Path Exists in Graph.

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int src, int des)
    {
        vector<int> vis(n, 0);
        vector<int> graph[n];
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        queue<int> q;
        q.push(src);
        vis[src] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : graph[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

        return vis[des] == 1;
    }
};
