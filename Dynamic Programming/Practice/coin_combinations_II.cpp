#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,sum;
    cin>>n;
    cin >> sum;
    int mod = 1e9+7;
    
    vector<int>coins(n);
    
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j]; 
            if (j >= coins[i - 1])
                dp[i][j] += (dp[i][j - coins[i - 1]]); 
                dp[i][j]%=mod;
        } 
    }

    cout<<dp[n][sum]<<endl;

    return 0;
}