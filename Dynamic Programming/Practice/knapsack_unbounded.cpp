#include<bits/stdc++.h>
using namespace std;

int unknapsack(int arr[], int val[],int n,int k){
    int dp[n+1][k+1];

    for(int i=0;i<=k;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(arr[i-1]<=j)dp[i][j]=max(val[i-j]+dp[i][j-arr[i-1]],dp[i-1][j]);
            else dp[i][j]=arr[i-1][j];
        }
    }

    return dp[n][k];
}

//ROD CUTTING PROBLEM

int rodcut(int cost[],int n){
    int sum = cost.size();
    // for(int i=0;i<n;i++)
    //     sum+=cost[i];
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= k; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(cost[i-1]<=j)dp[i][j]=max(cost[i-1]+dp[i][j-cost[i-1]],dp[i][j]);
        }
    }

    return dp[n][sum];
}

//MAXIMUM NUMBER OF WAYS COIN CHANGE

int coinchangemax(int coin[],int n,int sum){
    int dp[n+1][sum+1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 0; i <= sum; i++)
        dp[0][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if (arr[i - 1] <= j)
                dp[i][j] = max(dp[i][j - coin[i - 1]], dp[i][j]);
                //Replace comma with plus sign to get all number of ways
        }
    }
    return dp[n][sum];
}

//MINIMUM NUMBER OF COINS FOR A SUM

int mincoins(int coin[],int n,int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 0; i <= sum; i++)
        dp[0][i] = INT_MAX-1;

    for(int i=1;i<=sum;i++){
        if(i%coin[0]!=0)dp[1][i]=INT_MAX-1;
        else dp[1][i]=i/coin[0];
    }
    
    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(coin[i-1]<=j)dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i][j]);
        }
    }

    return dp[n][sum];
}