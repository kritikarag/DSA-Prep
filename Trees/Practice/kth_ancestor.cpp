// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

#include<bits/stdc++.h>
using namespace std;

void getparents(int node, int parent, vector<int>tree[], vector<int>&parents){
    parents[node] = parent;

    for(int i:tree[node]){
        if(i==parent)continue;
        getparents(i,node,tree,parents);
    }
}

int KthAncestor(int node, vector<int>tree[], int n, int k){

    vector<int>parents(n);
    getparents(1,0,tree,parents); 
    while(k--){
        node = parents[node];
    }

    return node;
}

// For a range of queries
int n;
vector<vector<int>>parents(n+1,vector<int>(17,0));
int KthAncestor(int node, int parent, vector<int>tree[], int n){
    parents[node][0] = parent;

    for(int i=1;i<=16;i++){
        parents[node][i] = parents[parents[node][i-1]][i-1];
    } 

    for(int it:tree[node]){
        if(it==parent)continue;
        KthAncestor(it,node,tree,n);
    }
}

int KthAncestor(int node, vector<int> tree[], int n, int k)
{

    int count = 0,node;
    
    while(k){
        if(k&1){
            node = parents[node][count];
        }

        k>>=1;
        count++;
    }
    return node;
}