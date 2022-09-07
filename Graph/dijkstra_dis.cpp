// Shortest distance for undirected weighted graph

vector<int>dijkstra(int v, vector<pair<int,int>>adj[], int src){
    vector<int>dis(v+1,INT_MAX);
    queue<pair<int,int>,vector<pair<int,int>,greater<pair<int,int>>pq;
    q.push(src);
    dis[src] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dis[it.first]>dis[node]+it.second){
                dis[it.first]=dis[node]+it.second;
            }
        }
    }
}