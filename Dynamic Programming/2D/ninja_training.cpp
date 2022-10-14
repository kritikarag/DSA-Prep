// https://www.codingninjas.com/codestudio/problem-details/ninja-s-training_3621003
#include<bits/stdc++.h>
using namespace std;

RECURSION:
int maxpoints(int day, int last, vector<vector<int>>&vec){
    if(day==0){
        int maxi = 0;
        for(int task=0;task<=2;task++){
            if(tast!=last){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;

    for(int task = 0;task<=2;task++){
        if(task!=last){
            int point = vec[day][task] + maxpoints(day-1,task,vec);
            maxi = max(maxi, points);
        }
    }

    return maxi;
}

int ninjaTraining(vector<vector<int>>&vec){
    int n = vec.size();
    return maxpoints(n-1,3,vec);
}

Memorization:

int maxpoints(int day, int last, vector<vector<int>>&vec, vector<vector<int>>&dp){
    if(dp[day][last]!=-1)return dp[day][last];

    if(day==0){
        int maxi = 0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi = max(maxi,vec[0][i]);
            }
        }
        return dp[day][last] = maxi;
    }

    int maxi =0;
    for(int i=1;i<=3;i++){
        if(i!=last){
            int curr = vec[day-1][i-1] + maxpoints(m,day-1,i,vec,dp);
            maxi = max(maxi,curr);
        }
    }

    return dp[day][last]=maxi;
}
int ninjaTraining(vector<vector<int>>&vec){
    int n = vec.size();
    vector<vector<int>>dp(n+1,vector<int>(4,-1));
    return maxpoints(n-1,3,vec,dp);
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