// https://cses.fi/problemset/task/1193
#include<bits/stdc++.h>
using namespace std;
int dir[5] = {0, 1, 0, -1, 0};
char d[4] = {'R','D','L','U'};
vector<char>ans = {};
bool valid(int i,int j,vector<vector<char>>matrix){
    if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()||matrix[i][j]=='#')return false;
    return true;
}
void dfs(int i, int j, vector<vector<char>>matrix,vector<vector<bool>>vis,vector<char>temp){
    vis[i][j] = true;
    if (matrix[i][j] == 'B' && (ans.size() == 0 || ans.size() > temp.size()))
    {
        ans = temp;
    }

    for(int i=0;i<4;i++){
        int row = i+dir[i];
        int col = j+dir[i+1];
        if(!vis[i][j] && valid(row,col,matrix)){
            temp.push_back(d[i]);
        }
    }
    temp.pop_back(); 
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>matrix(n,vector<char>(m));
    vector<vector<bool>>vis(n, vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vector<char>temp;
            if(matrix[i][j]=='A')dfs(i,j,matrix,vis,temp);
        }
    }

    if(ans.size()==0){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(int i =0;i<ans.size();i++){
            cout<<ans[i];
        }
    }
    return 0;
}