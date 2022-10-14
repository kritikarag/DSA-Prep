#include<bits/stdc++.h>
using namespace std;
//RECURSION
int mazeObstacles(int i, int j, vector<vector<int>>&vec){
    if (i == 1 && j == 1)
        return 1;
    if (i <= 0 || j <= 0)
        return 0;
    if (vec[i - 1][j - 1] == -1)
        return 0;

    return mazeObstacles(i - 1, j, vec) + mazeObstacles(i, j - 1, vec);
}

//MEMORIZATION

int mazeObstacles(int i, int j, vector<vector<int>> &vec, vector<vector<int>> &dp)
{
    if (i <= 0 || j <= 0 || vec[i - 1][j - 1] == -1)
        return 0;
    if (i == 1 && j == 1)
        return dp[i][j] = 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    int left = mazeObstacles(i - 1, j, vec, dp);
    int up = mazeObstacles(i, j - 1, vec, dp);

    return dp[i][j] = left + up;
}

//TABULATION

int mazeObstacles(int n, int m, vector<vector<int>> &vec)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                dp[i][j] = 1;
            else if (vec[i - 1][j - 1] == -1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n][m];
}

//SPACE OPTIMIZATION

int mazeObstacles(int n, int m, vector<vector<int>> &vec)
{
    vector<int>prev(m + 1,0);

    for (int i = 1; i <= n; i++)
    {
        vector<int> curr(m + 1, 0);
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                curr[j] = 1;
            else if (vec[i - 1][j - 1] == -1)
                curr[j] = 0;
            else
                curr[j] = prev[j] + curr[j - 1];
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    vector<vector<int>> maze{{0, 0, 0},
                             {0, -1, 0},
                             {0, 0, 0}};

    int n = maze.size();
    int m = maze[0].size();

    cout << mazeObstacles(n, m, maze);
    return 0;
}