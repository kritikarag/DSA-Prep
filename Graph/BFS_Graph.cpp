vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,false);
        vector<int> vec;
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int curr=q.front();
            vec.push_back(curr);
            for(auto i: adj[curr]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
            q.pop();
        }
        return vec;
    }
