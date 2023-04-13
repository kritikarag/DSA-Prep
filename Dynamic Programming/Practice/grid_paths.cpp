// https://cses.fi/problemset/task/1638

#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int calculate(vector<vector<char>>&grid, vector<vector<int>>&dp,int n){
    if(grid[0][0]=='*'||grid[n-1][n-1]=='*')return 0;

    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                dp[i][j] = 0;
            }
            else if (i > 0 && j > 0)
            {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
            else if (i > 0)
            {
                dp[i][j] += dp[i - 1][j];
            }
            else if (j > 0)
            {
                dp[i][j] += dp[i][j - 1];
            }

            dp[i][j]%=mod;
        }
    }

    return dp[n-1][n-1];
}
int main(){
    int n;
    cin>>n;

    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>dp(n,vector<int>(n,0));

    cout<<calculate(grid,dp,n)<<endl; 
    return 0;
}