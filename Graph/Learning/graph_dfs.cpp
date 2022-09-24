vector<int>ans;
  
  void dfs(int node,vector<int>adj[],vector<int>&v){
      ans.push_back(node);
      v[node]=1;
      for(auto i: adj[node]){
          if(v[i]==0)dfs(i,adj,v);
      }
  }
     
  vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>v(V,0);
        dfs(0,adj,v);
        return ans;
    }
