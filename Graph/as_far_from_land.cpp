// https://leetcode.com/problems/as-far-from-land-as-possible/

// Solvable through DFS but take high time complexity
#include<bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>>&grid,int &count){
    if(i<0||j<0||i>=grid.size()||j>=grid[i].size()||(grid[i][j]!=0&&grid[i][j]<=count)){
        return ;
    }

    grid[i][j]= ++count;

    dfs(i+1, j, grid, count);
    dfs(i, j+1, grid, count);
    dfs(i-1, j, grid, count);
    dfs(i, j-1, grid, count);
}

int maxDistance(vector<vector<int>>&grid){
    for(int i = 0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                int count=0;
                dfs(i,j,grid,count);
            }
        }
    }

    int res = -1;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]>1){
                res = max(res, grid[i][j]-1);
            }
        }
    }

    return res;
}

//Using BFS

int row[4] = {1,0,-1,0};
int col[4] = {0,1,0,-1};

bool validIndex(int i, int j, vector<vector<int>>&grid, int count){
    if(i<0||j<0||i>=grid.size()||j>=grid[i].size()||(grid[i][j]!=0 && grid[i][j]<=count))
        return false;

    return true;
}

void bfs(int i, int j, vector<vector<int>>&grid, int count){
    queue<pair<int,int>>q;

    q.push({i,j});
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;

        grid[r][c] = count++;

        for(int k=0;k<4;k++){
            int cr = r+row[k];
            int cc = c+col[k];
            if(validIndex(cr,cc,grid,count)){
                grid[cr][cc] = count;
            }
        }
    }
}

int maxDistance(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                int count = 1;
                bfs(i, j, grid, count);
            }
        }
    }

    int res = -1;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] > 1)
            {
                res = max(res, grid[i][j] - 1);
            }
        }
    }

    return res;
}
