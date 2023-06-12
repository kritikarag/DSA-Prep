// https://cses.fi/problemset/task/1666/

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>graph[],vector<bool>&vis){
    vis[node] = true;
    for(int it:graph[node]){
        if(!vis[it])dfs(it,graph,vis);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>graph[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool>vis(n+1,false);
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,graph,vis);
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<endl;
    if(ans.size()>1){
        for(int i=1;i<ans.size();i++){
            cout<<ans[0]<<" "<<ans[i]<<endl;
        }
    }
    return 0;
}