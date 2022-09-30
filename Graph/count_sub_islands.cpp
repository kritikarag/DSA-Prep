#include<bits/stdc++.h>
using namespace std;

//Using DFS 
bool dfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    if (i < 0 || j < 0 || i >= grid1.size() || j >= grid1[0].size())
        return true;

    if (grid2[i][j] == 0)
        return true;
    if (grid1[i][j] == 0)
        return false;

    grid1[i][j] = 0;
    grid2[i][j] = 0;

    bool right = dfs(i + 1, j, grid1, grid2);
    bool top = dfs(i, j + 1, grid1, grid2);
    bool left = dfs(i - 1, j, grid1, grid2);
    bool down = dfs(i, j - 1, grid1, grid2);

    return ((right && left) && (top && down));
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int count = 0;
    for (int i = 0; i < grid1.size(); i++)
    {
        for (int j = 0; j < grid1[0].size(); j++)
        {
            if (grid2[i][j] == 1)
            {
                if (dfs(i, j, grid1, grid2))
                    count++;
            }
        }
    }
    return count;
}

//Using BFS
int row[4] = {0, 0, -1, 1};
int col[4] = {1, -1, 0, 0};

bool valid_index(int i, int j, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return false;

    return true;
}

bool bfs(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2){
    grid1[i][j]=0;
    grid2[i][j] =0;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;

        for(int k=0;k<4;k++){
            int r = row[k] + i;
            int c = col[k] + j;

            if(!valid_index(i,j,grid1))continue;
            if(grid2[r][c]==1){
                if(grid1[r][c]==0)return false;
                else{
                    q.push({r,c});
                    grid1[r][c]=0;
                    grid2[r][c]=0;
                }
            } 
        }
    }
    return true;
}
int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int count = 0;
    for (int i = 0; i < grid1.size(); i++)
    {
        for (int j = 0; j < grid1[0].size(); j++)
        {
            if (grid2[i][j] == 1 && grid1[i][j]==1)
            {
                if (bfs(i, j, grid1, grid2))
                    count++;
            }
        }
    }
    return count;
}