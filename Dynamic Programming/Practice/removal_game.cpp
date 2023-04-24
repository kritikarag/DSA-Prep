// https://cses.fi/problemset/task/1097/

#include <bits/stdc++.h>
using namespace std;

//recursion

// long long calculate(int i, int j, vector<long long> &scores, vector<vector<long long>> &dp, vector<vector<long long>> &sum)
// {
//     if(i==j)return scores[i];
//     if(dp[i][j]!=LLONG_MAX)return dp[i][j];

//     return dp[i][j] = max(scores[i]+ sum[i+1][j] - calculate(i+1,j,scores,dp,sum), scores[j]+sum[i][j-1]-calculate(i,j-1,scores,dp,sum));
// }

int main()
{

    int n;
    cin >> n;
    vector<long long> scores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX)), sum(n, vector<long long>(n));

    for (int i = 0; i < n; i++)
    {
        long long curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += scores[j];
            sum[i][j] = curr;
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i>j) continue;
            if(i==j)dp[i][j] = scores[i];
            else {
                dp[i][j] = max(scores[i]+sum[i+1][j]-dp[i+1][j],scores[j]+sum[i][j-1]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    //cout << calculate(0, n - 1, scores, dp, sum) << endl;

    return 0;
}