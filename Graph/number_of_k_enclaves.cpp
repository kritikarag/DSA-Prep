// https://leetcode.com/problems/number-of-enclaves/

//Using DFS
void dfs(int i, int j, vector<vector<int>> &grid)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        return;
    grid[i][j] = 0;
    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
}

int numEnclaves(vector<vector<int>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1)
                dfs(i, j, grid);
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
                count++;
        }
    }
    return count;
}

//USING BFS

int row[4] = {0,0,-1,1};
int col[4] = {1,-1,0,0};

bool valid_index(int i, int j, vector<vector<int>> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        return false;
    
    return true;
}

void bfs(int i, int j, vector<vector<int>> &grid)
{
    grid[i][j] = 0;
    queue<pair<int, int>> pq;
    pq.push({i, j});
    while (!pq.empty())
    {
        int i = pq.front().first;
        int j = pq.front().second;
        pq.pop();
        for(int k=0;k<4;k++){
            int r = row[k]+i;
            int c = col[k]+j;
            if(!valid_index(r,c,grid))continue;

            if(grid[r][c]==1){
                pq.push({r,c});
                grid[r][c]=0;
            }
        }
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1){
                if (grid[i][j] == 1)
                    bfs(i, j, grid);
            }
        }
    }

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
                count++;
        }
    }
    return count;
}