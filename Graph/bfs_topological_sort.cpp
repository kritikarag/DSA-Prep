vector<int>topologicalSortBFS(int v, vector<int>adj[]){
    vector<int>indegree(v+1,0);
    queue<int>q;
    for(int i=1;i<=v;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    for(int i=1;i<=v;i++){
        if(indegree[i]==0)q.push(i);
    }
    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }

    return topo;
}