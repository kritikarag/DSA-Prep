#include<bits/stdc++.h>
using namespace std;

//RECURSION

int uniquePathSum(int i, int j){
    if(i==1&&j==1)return 1;
    if(i<=0||j<=0)return 0; 

    else return uniquePathSum(i,j-1)+uniquePathSum(i-1,j);
}

//TABULATION

int uniquePathSum(int n,int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)dp[i][j]=1;
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}

//SPACE OPTIMIZATION
int uniquePathSum(int n, int m){
    vector<int>prev(n+1,0);
    for(int i=1;i<=n;i++){
        vector<int>curr(m+1,0);
        for(int j=1;j<=m;j++){
            if(i==1&&j==1)curr[j]=1;
            else curr[j]= curr[j-1]+prev[j];
        }

        prev = curr;
    }

    return prev[m];
}
int main(){
    cout<<uniquePathSum(3,2)<<endl;
    return 0;
}