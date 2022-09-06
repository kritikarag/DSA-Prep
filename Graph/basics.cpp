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

// DFS OF GRAPH RECURSION
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

//DFS USING STACK

vector<int>dfsofGraph(int v, vector<int>adj[]){
    vector<int>dfs;
    vector<int>vis(v,0);

    for(int i=1;i<=v;i++){
        stack<int>st;
        st.push(i);
        vis[i]=1;
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            res.push_back(temp);
            for(int it: adj[temp]){
                if(!vis[it]){
                    vis[it]=1;
                    st.push(it);
                }
            }
        }
    }

    return dfs;
}

//CYCLE DETECTION USING BFS
bool cycleDetectionBFS(int v, vector<int> adj[])
{
    queue<pair<int, int>> q;
    vector<int> vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            q.push({i, -1});
            vis[i] = 1;
            int n = q.size();
            while (!q.empty())
            {
                auto temp = q.front();
                q.pop();
                for (auto it : adj[temp.first])
                {
                    if (vis[it])
                    {
                        if (it != temp.second)
                            return true;
                    }
                    q.push({it, temp.first});
                    vis[it] = 1;
                }
            }
        }
    }
    return false;
}
//CYCLE DETECTION USING DFS
bool iscycle(int node, int parent, vector<int>&vis, vector<int>adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(iscycle(it,node,vis,adj))return true;
        }
        else{
            if(it!=parent)return true;
        }
    }

    return false;
}

bool cycleDetectionDFS(int v, vector<int>ad[]){
    vector<int>vis(v+1,0);
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            if(iscycle(i,-1,vis,adj));
        }
    }
    return false;
}

//BIPARTITE GRAPH USING BFS

bool bipartite(int v, vector<int>adj[]){

    vector<int>fill(v+1,-1);
    for(int i=1;i<=v;i++){
        if(fill[i]==-1){
            queue<int> q;
            q.push(i);
            fill[i]=0;
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                for(auto it: adj[temp]){
                    if(fill[it]==-1){
                        fill[it]=1-temp;
                        q.push(it);
                    }
                    else{
                        if(fill[i]==fill[temp])return false;
                    }
                }
            }
        }
    }
    return true;
}

//BIPARTITE USING DFS

bool bipartitedfs(int v, vector<int>adj[]){
    vector<int>fill(v+1,-1);

    for(int i=1;i<=v;i++){
        if(fill[i]==-1){
            stack<int>st;
            st.push(i);
            fill[i]=0;
            while(!st.empty()){
                int node = st.top();
                st.pop();
                for(auto it: adj[node]){
                    if(fill[it]==-1){
                        fill[it]=1-node;
                        st.push(it);
                    }

                    else if(fill[it]==fill[node])return false;
                }
            }
        }
    }

    return true;
}

//CYCLE DETECTION IN DIRECTED GRAPH

bool cycleDirectedDFS(int v, vector<int>adj[]){
    vector<int>vis(v+1,0);
    vector<int>dfsvis(v+1,0);

    for(int i=0;i<=v;i++){
        if(!vis[i]){
            vis[i]=1;
            dfsvis[i]=1;
            stack<int>st;
            st.push(i);
            while(!st.empty()){

            }
        }
    }
}
//DETECTION OF CYCLE IN DIRECTED GRAPH USING DFS RECURSSION
bool iscycle(int node, vector<int>adj[], vector<int>&vis, vector<int>&dfsvis){
    vis[node]=1;
    dfsvis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it])
            if(iscycle(it,adj,vis,dfsvis))return true;
        else if(dfsvis[it]) return true;
    }
    dfsvis[node]=0;
    return false;
}

bool cycleDirectedDFS(int v, vector<int>adj[]){
    vector<int> vis(v + 1, 0);
    vector<int> dfsvis(v + 1, 0);

    for (int i = 0; i <= v; i++)
    {
        if (!vis[i])
        {
            if(iscycle(i,adj,vis,dfsvis))return true;
        }
    }
    return true;
}