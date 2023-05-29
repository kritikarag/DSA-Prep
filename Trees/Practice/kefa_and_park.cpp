// 

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void solve(int node, int &res, int &curr, int m, vector<int>adj[], vector<bool>&vis,vector<int>&cats){
    if(cats[node-1]==1)curr++;
    else curr = 0;

    if(adj[node].size()==0 && curr<=m){
        res++;
        return;
    }
    for(int i:adj[node]){
        solve(i, res, curr, m, adj, vis, cats);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    vector<bool>vis(n+1,false);
    vector<int>cats(n+1);
    cats[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>cats[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y); 
    }

    int res = 0,curr=0;
    vis[0] = true;
    solve(1,res,curr,m,adj,vis,cats);
    cout<<res<<endl;
}