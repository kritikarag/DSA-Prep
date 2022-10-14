#include<bits/stdc++.h>
using namespace std;

//RECURSION

int uniquePathSum(int i, int j){
    if(i==1&&j==1)return 1;
    if(i<=0||j<=0)return 0; 

    else return uniquePathSum(i,j-1)+uniquePathSum(i-1,j);
}

//Memorization

int uniquePathSum(int i, int j, vector<vector<int>>&dp){
    if(i<=0||j<=0)return dp[i][j]=0;
    if(i==1||j==1)return dp[i][j]=1;

    if(dp[i][j]!=-1)return dp[i][j];

    int left = uniquePathSum(i-1,j,dp);
    int up = uniquePathSum(i,j-1,dp);

    return dp[i][j] = left + up;
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
    vector<int>prev(m+1,0);
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

//Short Logistic Approach

int uniquePathSum(int n, int m){

    int row = n + m -2;
    int col = n -1;

    double res =1;

    for(int i=1;i<=col;i++){
        res*=(row-col+i)/i;
    }

    return (int)res;
}

int main(){
    cout<<uniquePathSum(3,2)<<endl;
    return 0;
}