//

#include<bits/stdc++.h>
using namespace std;

int minimizingCoins(vector<int>&coins, int target){
    int n = coins.size();

    vector<vector<int>>dp(n+1,vector<int>(target+1,0));
    for(int i=1;i<=target;i++)dp[0][i] = INT_MAX;

    for(int i=0;i<=target;i++){
        if(i%coins[0]==0)dp[1][i] = i/coins[0];
        else dp[1][i] = INT_MAX;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=target;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=coins[i-1]){
                dp[i][j] = min(dp[i][j], dp[i][j-coins[i-1]]+1);
            }
        }
    }

    return (dp[n][target]==INT_MAX?-1:dp[n][target]);
}