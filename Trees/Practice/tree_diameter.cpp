// https://cses.fi/problemset/task/1131/

#include<bits/stdc++.h>
using namespace std;

int res = 0;
int diameter(int node, int parent, vector<int>tree[]){
    if(tree[node].size()==0)return 1;
    
    int height = 0, sum_height=0, height2=0;
    for(int i:tree[node]){
        if(i==parent)continue;
        int curr_height = diameter(i,node,tree);
        if(curr_height>=height){
            height2 = height;
            height = curr_height;
        }
        else if(curr_height>=height2){
            height2 = curr_height;
        }
        sum_height = max(sum_height,height2+height);
    }
    
    res = max(res,sum_height);
    //cout << "Node: " << node << " -> Diameter: " << sum_height << " Height:" << height << endl;
    return height+1;
}
int main(){
    int n;
    cin>>n;
    vector<int>tree[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    diameter(1,-1,tree);
    cout<<res<<endl;
    return 0;
}