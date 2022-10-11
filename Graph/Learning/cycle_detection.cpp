Using BFS

bool cycleDetectionBFS(int v, vector<int> adj[])
{
    queue<pair<int,int>>q;
    vector<int>vis(n+1,0);

    for(int i=0;i<=n;i++){
        if(!vis[i]){
            q.push({i,-1});
            vis[i]=1;
            while(!q.empty()){
                aut node = q.front();
                q.pop();

                for(auto it: adj[node.first]){
                    if(vis[it]){
                        if(it!=node.second)return true;
                    }
                    else{
                        q.push({it,node.first});
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return false;
}

USING DFS

bool(vector<int>adj[], int node, int par, vector<int>&vis){
    vis[node]=1;
    for(auto it: adj[node]){
        if(vis[it]){
            if(it!=par)return true;
        }
        else{
            if(dfs(adj,it,node,vis))return true;
        }
    }
    return false;
}

bool cycleDetectionBFS(int v, vector<int> adj[])
{
    vector<int>vis(n+1,0);
    for(int i=0;i<=n;i++){
        if(!vis[i]){
            if(dfs(adj,i,-1,vis))return true;
        }
    }

    return false;
}