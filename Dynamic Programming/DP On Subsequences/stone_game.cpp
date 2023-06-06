// https://leetcode.com/problems/stone-game/description/

#include<bits/stdc++.h>
using namespace std;
// Memorization

int solve(int i, int j, vector<int> &piles, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
        return piles[i];
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = max(piles[i] - solve(i + 1, j, piles, dp), piles[j] - solve(i, j - 1, piles, dp));
}
bool stoneGame(vector<int> &piles)
{
    int n = piles.size(); 
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return max(piles[0] - solve(1, n - 1, piles, dp), piles[n - 1] - solve(0, n - 2, piles, dp));
}

//Tabulation

bool stoneGame(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i=0;i<n;i++)dp[i][i] = piles[i];

    for(int i=1;i<n;i++){
        for (int j=0;j<n-i;j++){
            dp[j][j+i] = max(piles[j]-dp[j+1][j+i],piles[i+j]-dp[i][i+j-1]);
        }
    }

    return dp[0][n-1]>0;
}

//SPACE OPTIMIZED
