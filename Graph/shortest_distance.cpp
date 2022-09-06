vector<int> shortestDistance(int v, vector<int>adj[],int src){
    vector<int>dis(v+1,INT_MAX);
    queue<int>q;
    q.push(src);
    dis[src]=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dis[it]>dis[node]+1){
                q.push(it);
                dis[it]=dis[node]+1;
            }
        }
    }

    return dis;
}