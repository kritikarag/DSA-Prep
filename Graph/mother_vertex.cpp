//

Brute Force:-

void dfs(int node, vector<bool> &vis, vector<int> adj[], int &count)
{
    count++;
    vis[node] = true;

    for (int child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, vis, adj, count);
        }
    }
}
// Function to find a Mother Vertex in the Graph.
int findMotherVertex(int V, vector<int> adj[])
{
    // Code here

    for (int i = 0; i < V; i++)
    {
        int count = 0;
        vector<bool> vis(V, false);

        dfs(i, vis, adj, count);

        if (count == V)
            return i;
    }

    return -1;
}

Brute Force : -

void dfs(int node, vector<bool> &vis, vector<int> adj[])
{ 
    vis[node] = true;

    for (int child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, vis, adj);
        }
    }
}

// Function to find a Mother Vertex in the Graph.
int findMotherVertex(int V, vector<int> adj[])
{
    // Code here
    int ans = -1;
    vector<bool> vis(V, false), vis2(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj);
            ans = i;
        }
    }

    dfs(ans, vis2, adj);

    for (auto it : vis2)
    {
        if (!it)
            return -1;
    }
    return ans;
}