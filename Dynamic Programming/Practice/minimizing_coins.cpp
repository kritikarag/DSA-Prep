#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, sum;
    cin>>n>>sum;

    vector<int>coin(n);
    
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(sum+1));

    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    for(int i=1;i<=sum;i++){
        dp[0][i] = INT_MAX-1;
    }

    for(int i=0;i<=sum;i++){
        if(i%coin[0]!=0)dp[1][i] = INT_MAX-1;
        else dp[1][i] = i/coin[0];
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=coin[i-1])dp[i][j] = min(1+dp[i][j-coin[i-1]],dp[i][j]);
        }
    }

    cout<<(dp[n][sum]==INT_MAX-1?-1:dp[n][sum])<<endl;

    return 0;
}