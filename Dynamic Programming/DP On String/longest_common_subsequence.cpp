#include<bits/stdc++.h>
using namespace std;

// RECURSION
int maxLength(int ind1, int ind2, string &a, string &b){
    if(ind1<0||ind2<0)return 0;

    if(a[ind1]==b[ind2]){
        return 1 + maxLength(ind1-1,ind2-1,a,b);
    }
    else{
        return max(maxLength(ind1-1,ind2,a,b),maxLength(ind1,ind2-1,a,b));
    }
}

//MEMORIZATION

int maxLength(int ind1, int ind2, string &a, string &b, vector<vector<int>>&dp){
    if(ind1<=0||ind2<=0)return 0;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    if(a[ind1-1]==b[ind2-1]){
        return dp[ind1][ind2] = 1 + maxLength(ind1-1,ind2-1,a,b,dp);
    }
    else{
        return dp[ind1][ind2] = max(maxLength(ind1-1,ind2,a,b,dp),maxLength(ind1,ind2-1,a,b,dp));
    } 
}

//TABULATION

int maxlength(int ind1, int ind2, string &a, string &b){
    vector<vector<int>>dp(ind1+1,vector<int>(ind2+1,-1));
    for(int i=0;i<=ind1;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=ind2;i++){
        dp[0][i] = 0;
    }

    for(int i = 1;i<=ind1;i++){
        for(int j=1;j<=ind2;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[ind1][ind2];
}

//SPACE OPTIMIZATION

int maxLength(int ind1, int ind2, string &a, string &b){
    vector<int>prev(ind1+1,-1);
    prev[0]=0;
    for(int i=1;i<=ind1;i++){
        vector<int>curr(ind2+1,-1);
        curr[0]=0;
        for(int j=1;j<=ind2;j++){
            if(a[i-1]==b[j-1]){
                curr[j]=1+prev[j-1];
            }
            else {
                curr[j] = max(curr[j-1],prev[j]);
            }
        }
        prev = curr;
    }

    return prev[ind2];
}

int main()
{
    string s1 = "acd";
    string s2 = "ced";
    int n=s1.size(),m=s2.size();
    
    cout << "The Length of Longest Common Subsequence is " << maxLength(n,m,s1,s2)<<endl;

    //For calling memorization function
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout << "The Length of Longest Common Subsequence is " << maxLength(n, m, s1, s2, dp) << endl;

    return 0;
}