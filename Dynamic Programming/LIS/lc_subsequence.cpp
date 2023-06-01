// https://leetcode.com/problems/longest-common-subsequence/description/

#include<bits/stdc++.h>
using namespace std;

int lcs(int ind1, int ind2, string text1, string text2){
    if(ind1<0||ind2<0)return 0;

    if(text1[ind1]==text2[ind2]){
        return 1+ lcs(ind1-1,ind2-2,text1,text2);
    }
    return max(lcs(ind1-1,ind2,text1,text2),lcs(ind1,ind2-1,text1,text2));
}
int longestCommonSubsequence(int n, int m,string text1, string text2, vector<vector<int>>&dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main(){
    string text1,text2;
    cin>>text1>>text2;
    int n = text1.size(), m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int res = longestCommonSubsequence(n,m,text1,text2,dp);

    int count =1;
    string ans="";
    for(int i=1;i<=m;i++){
        if(dp[n][i]==count){
            ans+=text2[i-1];
            count++;
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<res<<endl;
    cout<<ans<<endl;
    return 0;
}