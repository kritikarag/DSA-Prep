// https://leetcode.com/problems/is-graph-bipartite/

Note : A graph with odd length cycle can never be bipartite graph but the reverse might not be true

Using BFS
Runtime: 27 ms, faster than 90.27% of C++ online submissions for Is Graph Bipartite?.
Memory Usage: 14.2 MB, less than 17.72% of C++ online submissions for Is Graph Bipartite?.

bool bipartite(vector<vector<int>>& adj)
{
    int n = adj.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int node = q.front();
                int temp = color[node];
                q.pop();

                for (auto it : adj[node])
                {
                    if (color[it] == -1)
                    {
                        color[it] = 1 - temp;
                        q.push(it);
                    }
                    else
                    {
                        if (color[it] == color[node])
                            return false;
                    }
                }
            }
        }
    }
    return true;
}

Using DFS - Recursion
Runtime: 64 ms, faster than 22.87% of C++ online submissions for Is Graph Bipartite?.
Memory Usage: 13.5 MB, less than 84.65% of C++ online submissions for Is Graph Bipartite?.

bool dfs(vector<vector<int>>& adj, int node, vector<int> &color)
{
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (dfs(adj, it, color))
                return true;
        }
        else
        {
            if (color[it] == color[node])
                return false;
        }
    }

    return true;
}

bool bipaartite(vector<vector<int>> &adj)
{
    int n =adj.size;
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (dfs(adj, i, color))
                return false;
        }
    }
    return true;
}

Using DFS - Stack
Runtime: 35 ms, faster than 73.64% of C++ online submissions for Is Graph Bipartite?.
Memory Usage: 13.5 MB, less than 60.74% of C++ online submissions for Is Graph Bipartite?.

bool bipartite(vector<vector<int>>& adj)
{
    int n = adj.size();
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            stack<int> st;

            color[i] = 0;
            st.push(i);

            while (!st.empty())
            {
                int node = st.top();
                st.pop();

                for (auto it : adj[node])
                {
                    if (color[it] == -1)
                    {
                        color[it] = 1 - color[node];
                        st.push(it);
                    }
                    else
                    {
                        if (color[it] == color[node])
                            return false;
                    }
                }
            }
        }
    }
    return true;
}