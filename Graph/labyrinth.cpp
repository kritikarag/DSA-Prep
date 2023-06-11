// https://cses.fi/problemset/task/1193
#include<bits/stdc++.h>
using namespace std;
bool valid(int i,int j, int n, int m, vector<vector<char>>matrix){
    if(i<0||j<0||i>=n||j>=m||matrix[i][j]=='#')return false;
    return true;
}
bool bfs(int i, int j, vector<vector<char>>matrix,vector<vector<bool>>vis){
    queue<pair<int,int>>q;
    int n = matrix.size(), m = matrix[0].size();
    int dir[5] = {0,1,0,-1,0};
    vis[i][j] = true;
    q.push({i,j});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(matrix[i][j]=='B')return true;
        for(int k=0;k<4;k++){
            int row = x + dir[k];
            int col = y + dir[k+1];
            if(valid(row,col,n,m,matrix)&&!vis[row][col]){
                q.push({row,col});
            }
        }                
    }
    return false;
}
int main(){
    int n,m;cin>>n>>m;
    vector<vector<char>>matrix(n,vector<char>(m));
    vector<vector<bool>>vis(n, vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='A')bfs(i,j,matrix,vis);
        }
    }
    return 0;
}