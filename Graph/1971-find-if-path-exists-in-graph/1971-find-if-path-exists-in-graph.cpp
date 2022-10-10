class Solution {
public: 
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        vector<int>vis(n,0);
        vector<int>graph[n];
        for(int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: graph[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
            
        }
        
        return vis[des]==1;
    }
};