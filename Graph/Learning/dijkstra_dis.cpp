// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

Dijksta's Algorithm : Shortest distance for undirected weighted graph with positive edge weights


vector<int>dijkstra(int v, vector<pair<int,int>>adj[], int src){
    vector<int>dis(v+1,INT_MAX);
    queue<pair<int,int>,vector<pair<int,int>,greater<pair<int,int>>>pq;
    pq.push(src);
    dis[src] = 0;

    while(!q.empty()){
        int node = pq.top().first;
        int weight = pq.top().second;

        for(auto it: adj[node]){
            int temp = it.first;
            int curr = it.second;

            if(dis[temp]>weight+curr){
                dis[temp] = weight+curr;
                pq.push({temp, dis[temp]}); 
            }
        }
    }
    return dis;
}