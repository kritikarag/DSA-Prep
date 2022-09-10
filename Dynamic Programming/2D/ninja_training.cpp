// https://www.codingninjas.com/codestudio/problem-details/ninja-s-training_3621003
#include<bits/stdc++.h>
using namespace std;

//RECURSION

int maxpoints(int m,int day, int last, vector<vector<int>>&vec, vector<vector<int>>&dp){
    if(day<=0)return 0;

    int maxi =0;
    for(int i=1;i<=3;i++){
        if(i!=last){
            int curr = vec[day-1][last-1] + maxpoints(m,day-1,i,vec,dp);
            maxi = max(maxi,curr);
        }
    }

    return maxi;
}
int ninjaTraining(vector<vector<int>>&vec){
    int n = vec.size();
    int m = vec[0].size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    return maxpoints(m,n,m,vec,dp);
}

//TABULATION (INCOMPLETE)

int ninjaTraining(vector<vector<int>> &vec)
{
    int n = vec.size();
    int m = vec[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i=0;i<=m;i++){
        dp[1][i]=0;
        for(int j=0;j<m;j++){
            if(i!=j){
                dp[1][i]=max(dp[1][i],vec[i-1][j]);
            }
        }
    }
}
int main()
{

    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size();
    cout << ninjaTraining(points);
    return 0;
}