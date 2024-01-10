#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

RECURSION

int maxlength(int ind1 ,int ind2, string&a, string &b, int count){
    if(ind1<0||ind2<0)return count;

    if(a[ind1]==b[ind2]){
        count = maxlength(ind1-1,ind2-1,a,b, count+1);
    }
    return max(count,max(maxlength(ind1-1,ind2,a,b,0),maxlength(ind1,ind2-1,a,b,0)));
}

MEMORIZATION 

int solve(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp)
{

    if (ind1 == 0 || ind2 == 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s1[ind1 - 1] != s2[ind2 - 1])
    {
        dp[ind1][ind2] = 0;
    }
    else
    {
        dp[ind1][ind2] = 1 + solve(s1, s2, ind1 - 1, ind2 - 1, dp);
    }

    solve(s1,s2,ind1-1,ind2);
    solve(s1,s2,ind1,ind2-1);

    return dp[ind1][ind2];
}

int maxlength(int n, int m, string &a, string &b){
    int maxi = INT_MIN;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    solve(a,b,n,m);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            maxi = max(maxi, dp[i][j]);
        }
    }
    return maxi;
}

TABULATION

int maxlength(int n, int m,string &a, string &b){
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int maxi = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi,dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return maxi;
}

SPACE OPTIMIZATION

int maxlength(int n, int m, string &a, string &b)
{
    vector<int>prev(n+1,0);
    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        vector<int>curr(m+1,0);
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                curr[j] = 1 + prev[j-1];
                maxi = max(maxi, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return maxi;
}

int main()
{

    string s1 = "abcjklp";
    string s2 = "acjkp";
    int n = s1.length();
    int m = s2.length();

    cout << "The Length of Longest Common Substring is " << maxlength(n, m, s1, s2, 0) << endl;

    //FOR CALLING RECURSIVE FUNCTION
    cout << "The Length of Longest Common Substring is " << maxlength(n, m, s1, s2,0)<<endl;
    return 0;
}