// https://www.spoj.com/problems/PT07Y/en/

#include<bits/stdc++.h>
using namespace std;
int flag = false;
void dfs(int node, int par, vector<int>adj[], vector<bool>&vis){
    vis[node] = true;
    for(int i:adj[node]){
        if(vis[i]){
            if(i!=par){
                flag = true;
                return;
            }
        }
        else{
            dfs(i,node,adj,vis);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool>vis(n+1,false);
    vector<int>parent(n+1,-1);
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,-1,adj,vis);
    }
    if(m!=n-1 || flag){
        cout<<"NO"<<endl;
    }
    else{
        bool v = true;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                v = false;
                break;
            }
        }

        if(v)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}