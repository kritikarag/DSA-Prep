#include<bits/stdc++.h>
using namespace std;

int count(int m,int m){
    int dp[n][m];
    for(int i=0;i<m;i++)dp[0][i]=1;
    for(int i=0;i<n;i++)dp[i][0]=1;

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]= dp[i-1][j]+dp[i][j-1];
        }
    }

    return  dp[i-1][j-1];
}