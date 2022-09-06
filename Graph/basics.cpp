//ADJACENCY MATRIX
int main(){
    int n,m;
    cin>>n>>m;

    int adj[n+1][n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u][v]=1;
        adj[v][u]=1;
    }

    return 0;
}

//ADJACENCY LIST

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v>> wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    return 0;
}

// BFS OF GRAPH

vector<int> bfsofGraph(int v, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(v + 1, 0);

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it : adj[node])
                {
                    if (!vis[it])
                        q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    return bfs;
}

// DFS OF GRAPH
void dfstraversal(int node, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
{
    dfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfstraversal(it, vis, adj, bfs);
        }
    }
}
vector<int> dfsofGraph(int v, vector<int> &adj[])
{
    vector<int> dfs;
    vector<int> vis(v + 1, 0);

    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            dfstraversal(i, vis, adj, dfs);
        }
    }
    return dfs;
}

void cycleDetectionBFS(int v, vector<int> adj[])
{
}