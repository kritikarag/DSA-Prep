vector<int>topologicalSortDFS(int v, vector<int>adj[]){
    vector<int>vis(v+1,0);
    vector<int>ts;
    stack<int> st;
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            vis[i]=1;
            for(auto it: adj[i]){
                if(!vis[it]){
                    vis[it]=1;
                    st.push(it);
                }
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        ts.push_back(st.top());
        st.pop();
    }

    return ts;
}

//USING RECURSION

void findtopo(int node, vector<int>&vis,stack<int>&st,vector<int>adj[]){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            findtopo(it, vis, st,adj);
        }
    }
    st.push(node);
}

vector<int> topologicalSortDFS(int v, vector<int> adj[])
{
    vector<int> vis(v + 1, 0);
    vector<int> ts;
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            findtopo(i,vis,st,adj);
        }
    }

    while(!st.empty()){
        ts.push_back(st.top());
        st.pop();
    }

    return ts;
}
