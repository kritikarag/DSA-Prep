void toposort(int node, vector<int>&vis, stack<int>&st, vector<pait<int,int>>adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[node]){
            toposort(it,vis,st,adj);
        }
    }
    st.push(node);
}

vector<int>DAGshortestPath(int v, vector<pair<int,int>>adj[], int src){
    vector<int>dis(v+1,INT_MAX);
    stack<int>st;

    for(int i=1;i<=v;i++){
        if(!vis[i]){
            toposort(i,vis,st,adj);
        }
    }

    dis[src]=0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(dis[node]!=INT_MAX){
            for(auto it: adj[node]){
                if(dis[node]+it.second < dis[it.first]){
                    dis[it.first]=dis[node]+it.second;
                }
            }
        }
    }

    return res;
}