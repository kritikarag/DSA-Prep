//

#include<bits/stdc++.h>
using namespace std;

struct Component{
    int node;
    int distance;
};
int bfs(int target, vector<int>graph[]){
    queue<Component*>q;
    vector<int>vis(graph->size(),0);
    vis[target]++;
    for(int i:graph[target]){
        Component* temp = new Component();
        temp->node = i;
        temp->distance = 1; 
        q.push(temp);
    }

    while(!q.empty()){
        Component* temp = q.front();
        q.pop();
        if(temp->node==target)return temp->distance;
        int curr = temp->node;
        int dis = temp->distance;
        cout<<curr<<" ";
        vis[curr]++;
        if(vis[curr]>3)break;
        for(int i:graph[curr]){
            Component * curr = new Component();
            curr->node = i;
            curr->distance = dis+1;
            q.push(curr);
        }
    }
    return -1;
}
int main(){

    int n;
    cin>>n;
    vector<int>graph[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int v;
            cin>>v; 
            if(v)graph[i].push_back(j);
        }
    }

    vector<int> ans(n);  
    ans [0] = bfs(0,graph);
    // for(int i=0;i<n;i++){
    //     ans[i] = bfs(i,graph);
    // }

    // for(int i=0;i<n;i++){
    //     if(ans[i]==-1)cout<<"NO WAY"<<endl;
    //     else cout<<ans[i]<<endl;
    // }

    return 0;
}